#include<stdio.h>
#include<string.h>

int main()
{
    char lhs, op1, op2, op3;
    char opr1, opr2;
    int temp = 1;

    printf("Enter expression (Example: A=B+C-D): ");
    scanf("%c=%c%c%c%c%c%c",
          &lhs, &op1, &opr1, &op2, &opr2, &op3);

    printf("\nThree Address Code:\n");

    printf("t%d = %c %c %c\n", temp, op1, opr1, op2);
    temp++;

    printf("t%d = t%d %c %c\n", temp, temp-1, opr2, op3);

    printf("%c = t%d\n", lhs, temp);

    return 0;
}
