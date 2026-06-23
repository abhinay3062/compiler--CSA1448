#include <stdio.h>

int main()
{
    char str[1000];
    int words = 0, lines = 0, characters = 0;
    int inWord = 0;
    int i;

    printf("Enter text (use ~ to end):\n");
    scanf("%[^~]", str);

    for(i = 0; str[i] != '\0'; i++)
    {
        characters++;

        if(str[i] == '\n')
            lines++;

        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            inWord = 0;
        }
        else if(inWord == 0)
        {
            words++;
            inWord = 1;
        }
    }

    if(characters > 0)
        lines++;

    printf("\nTotal number of words      : %d", words);
    printf("\nTotal number of lines      : %d", lines);
    printf("\nTotal number of characters : %d", characters);

    return 0;
}
