#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ip_sym[20], stack[20];
int ip_ptr = 0, st_ptr = 0, len;
char act[20];

void check();

int main()
{
    printf("\n\tSHIFT REDUCE PARSER\n");
    printf("\nGrammar:");
    printf("\nE -> E+E");
    printf("\nE -> E*E");
    printf("\nE -> E/E");
    printf("\nE -> a | b\n");

    printf("\nEnter the input string: ");
    scanf("%s", ip_sym);

    len = strlen(ip_sym);

    printf("\nStack\t\tInput\t\tAction\n");
    printf("---------------------------------------\n");

    while (ip_ptr < len)
    {
        stack[st_ptr] = ip_sym[ip_ptr];
        stack[st_ptr + 1] = '\0';

        strcpy(act, "SHIFT");

        ip_ptr++;
        printf("%s\t\t%s\t\t%s\n", stack, ip_sym + ip_ptr, act);

        check();
        st_ptr++;
    }

    check();

    if (strcmp(stack, "E") == 0 && ip_ptr == len)
        printf("\nString Accepted\n");
    else
        printf("\nString Rejected\n");

    return 0;
}

void check()
{
    int changed;

    do
    {
        changed = 0;

        if (st_ptr >= 0 &&
            (stack[st_ptr] == 'a' || stack[st_ptr] == 'b'))
        {
            stack[st_ptr] = 'E';
            printf("%s\t\t%s\t\tREDUCE E->%c\n",
                   stack, ip_sym + ip_ptr,
                   (stack[st_ptr] == 'E') ? 'a' : 'b');
            changed = 1;
        }

        if (strlen(stack) >= 3)
        {
            int n = strlen(stack);

            if (stack[n - 3] == 'E' &&
                (stack[n - 2] == '+' ||
                 stack[n - 2] == '*' ||
                 stack[n - 2] == '/') &&
                stack[n - 1] == 'E')
            {
                stack[n - 3] = 'E';
                stack[n - 2] = '\0';

                st_ptr = strlen(stack) - 1;

                printf("%s\t\t%s\t\tREDUCE E->E%cE\n",
                       stack,
                       ip_sym + ip_ptr,
                       stack[n - 2]);

                changed = 1;
            }
        }

    } while (changed);
}
