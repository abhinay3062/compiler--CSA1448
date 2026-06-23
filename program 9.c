#include <stdio.h>
#include <string.h>

#define SIZE 20

int main()
{
    char non_terminal;
    char beta, alpha;
    int num;
    char production[10][SIZE];
    int index = 3;
    int i;

    printf("Enter Number of Productions: ");
    scanf("%d", &num);

    printf("Enter the grammar as E->E+A|T\n");

    for(i = 0; i < num; i++)
    {
        scanf("%s", production[i]);
    }

    for(i = 0; i < num; i++)
    {
        printf("\nGrammar: %s", production[i]);

        non_terminal = production[i][0];

        if(non_terminal == production[i][3])
        {
            alpha = production[i][4];

            printf("\nLeft Recursive Grammar");

            while(production[i][index] != '\0' &&
                  production[i][index] != '|')
            {
                index++;
            }

            if(production[i][index] == '|')
            {
                beta = production[i][index + 1];

                printf("\nGrammar after removing Left Recursion:\n");

                printf("%c->%c%c'\n",
                       non_terminal,
                       beta,
                       non_terminal);

                printf("%c'->%c%c'|E\n",
                       non_terminal,
                       alpha,
                       non_terminal);
            }
            else
            {
                printf("\nCannot be reduced");
            }
        }
        else
        {
            printf("\nNot Left Recursive");
        }

        index = 3;
    }

    return 0;
}
