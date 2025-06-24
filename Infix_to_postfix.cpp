#include <stdio.h>
#include <ctype.h>  
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char ch) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = ch;
}

char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

char peek() {
    if (top == -1)
        return '\0';
    return stack[top];
}


int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': return 3;
        case '/': return 3;
        case '%': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}


//int isRightAssociative(char op) {
 //   return (op == '^');
//}


int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%';
}


void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[j++] = ch; 
        } else if (ch == '(' ) {
            push(ch);
        } else if (ch == ')' ) {
            while (peek() != '(' && top != -1)
                postfix[j++] = pop();
            pop(); 
        } else if (isOperator(ch)) {
            while (top != -1 && peek() != '(' &&
                   (precedence(ch) < precedence(peek()) ||
                   (precedence(ch) == precedence(peek()) && ch!='^'))) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
//A+B*(C^D-E)^(F+G*H)-I

/*Initialize an empty stack for operators and an empty output list.

Scan the infix expression from left to right.

For each token:

Operand: Add it to the output.

Operator: Pop from the stack to the output while top of the stack has higher or equal precedence, then push the current operator.

Left Parenthesis ((): Push onto the stack.

Right Parenthesis ()): Pop to output until a left parenthesis is encountered, then discard the left parenthesis.

After the expression ends, pop all remaining operators in the stack to the output.*/