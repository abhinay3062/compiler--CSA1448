#include <stdio.h>

int main()
{
    char str[1000];
    int words = 0, lines = 0, characters = 0;
    int i;

    printf("Enter text (Press ~ to stop):\n");

    scanf("%[^~]", str);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
            characters++;

        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            words++;

        if(str[i] == '\n')
            lines++;
    }

    if(characters > 0)
    {
        words++;
        lines++;
    }

    printf("\nTotal number of words      : %d", words);
    printf("\nTotal number of lines      : %d", lines);
    printf("\nTotal number of characters : %d", characters);

    return 0;
}
