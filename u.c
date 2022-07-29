#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int top = -1;
int stack[100];
void push(int dataItem)
{
    stack[++top] = dataItem;
}
int pop()
{
    return stack[top--];
}
void main()
{
    char str[100];
    char *ptr;
    int num, n, n1, n2;
    printf("Enter the expression: ");
    scanf("%s", str);
    ptr = str;
    while (*ptr != '\0')
    {
        if (isdigit(*ptr))
        {
            num = *ptr - 48;
            push(num);
        }
        else
        {
            n = pop();
            n1 = pop();
            switch (*ptr)
            {
            case '+':
                n2 = n + n1;
                break;
            case '-':
                n2 = n - n1;
                break;
            case '*':
                n2 = n * n1;
                break;
            case '/':
                n2 = n / n1;
                break;
            case '%':
                n2 = n % n1;
                break;
            case '^':
                n2 = n ^ n1;
                break;
            default:
                break;
            }
            push(n2);
        }
        ptr++;
    }
    printf("The result is %d", pop());
}
/*
Output: -
Enter the expression: 51-
The result is -4
Output 2: -
Enter the expression: 5145+**
The result is 45
*/