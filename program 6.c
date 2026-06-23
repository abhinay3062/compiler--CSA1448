#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char a[50];
    int flag = 1, i = 1;

    printf("Enter an identifier: ");
    fgets(a, sizeof(a), stdin);

    a[strcspn(a, "\n")] = '\0';

    if(isalpha(a[0]) || a[0] == '_')
    {
        while(a[i] != '\0')
        {
            if(!isalnum(a[i]) && a[i] != '_')
            {
                flag = 0;
                break;
            }
            i++;
        }
    }
    else
    {
        flag = 0;
    }

    if(flag)
        printf("Valid identifier\n");
    else
        printf("Not a valid identifier\n");

    return 0;
}
