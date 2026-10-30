#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 400

int getPriority(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(const char* infix, char* postfix) {
    char stack[MAX_SIZE];
    int top = -1;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isdigit(ch) || ch == '.' || isalpha(ch) || (ch == '-' && (i == 0 || infix[i-1] == '(' || strchr("+-*/", infix[i-1]) != NULL)))
        {
            if (ch == '-' && (i == 0 || infix[i-1] == '(' || strchr("+-*/", infix[i-1]) != NULL)) {
                postfix[j++] = '-';
                ch = infix[++i];
            }
            postfix[j++] = ch;
            while (infix[i+1] != '\0' && (isdigit(infix[i+1]) || infix[i+1] == '.' || isalpha(infix[i+1]))) {
                postfix[j++] = infix[++i];
            }
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(') {
                top--;
            }
        } else if (strchr("+-*/", ch) != NULL) {
            if (ch == '+' && (i == 0 || infix[i-1] == '(')) {
                continue;
            }
            while (top >= 0 && getPriority(stack[top]) >= getPriority(ch)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top >= 0) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);

    return 0;
}
