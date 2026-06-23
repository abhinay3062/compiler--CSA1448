#include <stdio.h>
#include <string.h>

int main()
{
    char string[50];
    int flag = 0, count;

    printf("The grammar is: S -> aS | Sb | ab\n");
    printf("Enter the string to be checked: ");
    scanf("%s", string);

    if (string[0] != 'a')
    {
        printf("String not accepted");
        return 0;
    }

    for (count = 1; string[count] != '\0'; count++)
    {
        if (string[count] == 'b')
            flag = 1;
        else if (flag == 1 && string[count] == 'a')
        {
            printf("The string does not belong to the specified grammar");
            return 0;
        }
    }

    if (flag == 1)
        printf("String accepted");
    else
        printf("String not accepted");

    return 0;
}
