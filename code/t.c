// Covert infix expression to postfix

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char dataItem) {
    stack[++top] = dataItem;
}

int pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

int priority(char dataItem) {
    if (dataItem == '(') {
        return 0;
    } else if (dataItem == '+' || dataItem == '-') {
        return 1;
    } else if (dataItem == '*' || dataItem == '/') {
        return 2;
    } else if (dataItem == '^') {
        return 3;
    }
    return 0;
}

int isRightAssociative(char op) {
    return (op == '^');  // '^' is right associative
}

int hasHigherPrecedence(char op1, char op2) {
    int p1 = priority(op1);
    int p2 = priority(op2);

    if (p1 == p2) {
        // If operators are of equal precedence, return true if not right associative
        if (isRightAssociative(op1)) {
            return 0;
        } else {
            return 1;
        }
    }
    return p1 > p2;
}

int isValidCharacter(char c) {
    return isalnum(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')';
}

int main() {
    char str[100], *ptr, dataItem;
    int i, invalid = 0;

    printf("\nEnter infix expression: ");
    scanf("%s", str);

    // Validate the expression
    for (i = 0; str[i] != '\0'; i++) {
        if (!isValidCharacter(str[i])) {
            invalid = 1;
            break;
        }
    }

    if (invalid) {
        printf("\nInvalid Expression\n");
        return 1;
    }

    ptr = str;
    while (*ptr != '\0') {
        if (isalnum(*ptr)) {
            printf("%c", *ptr);  // Output operands directly
        } else if (*ptr == '(') {
            push(*ptr);
        } else if (*ptr == ')') {
            while ((dataItem = pop()) != '(') {
                printf("%c", dataItem);  // Pop until '(' is found
            }
        } else {
            // Handle operators
            while (top != -1 && !isRightAssociative(*ptr) && hasHigherPrecedence(stack[top], *ptr)) {
                printf("%c", pop());
            }
            push(*ptr);
        }
        ptr++;
    }

    // Pop all remaining operators
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");

    return 0;
}
