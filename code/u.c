// Postfix expression evaluation

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int top = -1;
int stack[100];

void push(int dataItem) {
    stack[++top] = dataItem;
}

int pop() {
    return stack[top--];
}

int main() {
    char str[100];
    char *ptr;
    int num, n1, n2, result;

    printf("Enter the postfix expression: ");
    scanf("%s", str);

    ptr = str;
    while (*ptr != '\0') {
        if (isdigit(*ptr)) {
            num = *ptr - '0'; // Convert char digit to integer
            push(num);
        } else {
            n2 = pop(); // Second operand (right side)
            n1 = pop(); // First operand (left side)

            switch (*ptr) {
                case '+':
                    result = n1 + n2;
                    break;
                case '-':
                    result = n1 - n2; // Correct order for subtraction
                    break;
                case '*':
                    result = n1 * n2;
                    break;
                case '/':
                    result = n1 / n2; // Correct order for division
                    break;
                case '%':
                    result = n1 % n2;
                    break;
                case '^':
                    result = (int)pow(n1, n2); // Use pow() for exponentiation
                    break;
                default:
                    printf("Invalid operator encountered\n");
                    exit(1);
            }
            push(result);
        }
        ptr++;
    }

    printf("The result is %d\n", pop());
    return 0;
}
