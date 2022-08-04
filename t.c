#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char stack[100];
int top = -1;
void push(char dataItem)
{
    stack[++top] = dataItem;
}
int pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}
int priority(char dataItem)
{
    if (dataItem == '(')
    {
        return 0;
    }
    else if (dataItem == '+' || dataItem == '-')
    {
        return 1;
    }
    else if (dataItem == '*' || dataItem == '/')
    {
        return 2;
    }
    else if (dataItem == '^')
    {
        return 3;
    }
    return 0;
}
int main()
{
    char str[100], *ptr, dataItem;
    int stringLength, i, count = 0;
    printf("\nEnter infix expression: ");
    scanf("%s", str);
    stringLength = strlen(str);
    for (i = 0; i < stringLength; i++)
    {
        if (isalnum(str[i]) || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == '(' || str[i] == ')')
        {
            count = 0;
        }
        else
        {
            count = 1;
            break;
        }
    }
    if (count == 1)

    {
        printf("\nInvalid Expression");
    }
    else
    {
        ptr = str;
        while (*ptr != '\0')
        {
            if (isalnum(*ptr))
            {
                printf("%c ", *ptr);
            }
            else if (*ptr == '(')
            {
                push(*ptr);
            }
            else if (*ptr == ')')
            {
                while ((dataItem = pop()) != '(')
                {
                    printf("%c ", dataItem);
                }
            }
            else
            {
                while (priority(stack[top]) >= priority(*ptr))
                {
                    printf("%c ", pop());
                }
                push(*ptr);
            }
            ptr++;
        }
        while (top != -1)
        {
            printf("%c ", pop());
        }
        printf("\n");
    }
    return 0;
}

/*
Output 1: -
Enter infix expression: (a+b)*c+(d-a)
a b + c * d a - +

Output 2: -
Enter infix expression: ((5+1)(4-5))/((2-8)(1+6))
5 1 + 4 5 - 2 8 - 1 6 + /
*/