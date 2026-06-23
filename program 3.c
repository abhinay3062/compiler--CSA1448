#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[])
{
    char keywords[32][10] = {
        "main","auto","break","case","char","const","continue","default",
        "do","double","else","enum","extern","float","for","goto",
        "if","int","long","register","return","short","signed",
        "sizeof","static","struct","switch","typedef",
        "unsigned","void","printf","while"
    };

    int i;

    for(i = 0; i < 32; i++)
    {
        if(strcmp(keywords[i], buffer) == 0)
            return 1;
    }

    return 0;
}

int main()
{
    char ch, buffer[50];
    char operators[] = "+-*/%=";
    FILE *fp;
    int i, j = 0;

    fp = fopen("C:\\Users\\gudis\\OneDrive\\Desktop\\compiler programs\\flex_input.txt", "r");

    if(fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        for(i = 0; i < 6; i++)
        {
            if(ch == operators[i])
            {
                printf("%c is an operator\n", ch);
                break;
            }
        }

        if(isalnum(ch) || ch == '_')
        {
            buffer[j++] = ch;
        }
        else if((ch == ' ' || ch == '\n' || ch == ';' ||
                 ch == ',' || ch == '(' || ch == ')') && j != 0)
        {
            buffer[j] = '\0';

            if(isKeyword(buffer))
                printf("%s is a keyword\n", buffer);
            else
                printf("%s is an identifier\n", buffer);

            j = 0;
        }
    }

    fclose(fp);
    return 0;
}
