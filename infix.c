#include <stdio.h>
#include <stdlib.h>

void evaluate();
void push(char);
char pop();
int prec(char);

char infix[30], postfix[30], stack[30];
int top = -1;

int main()
{
    printf("\nEnter the valid infix expression: ");
    scanf("%s", infix);
    evaluate();
    printf("\nThe entered infix expression is: %s\n", infix);
    printf("\nThe corresponding postfix expression is: %s\n", postfix);
    return 0; // Return a value from main
}

void evaluate()
{
    int i = 0, j = 0;
    char symb, temp;

    push('#'); // Push a sentinel

    while (infix[i] != '\0') // Changed for loop to while loop
    {
        symb = infix[i];
        switch (symb)
        {
        case '(':
            push(symb);
            break;

        case ')':
            temp = pop();
            while (temp != '(')
            {
                postfix[j] = temp;
                j++;
                temp = pop();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
        case '$':
            while (prec(stack[top]) >= prec(symb))
            {
                temp = pop();
                postfix[j] = temp;
                j++;
            }
            push(symb);
            break;
        default:
            postfix[j] = symb;
            j++;
            break; // Add a break to avoid falling through
        }
        i++; // Increment i in the loop
    }

    while (top > 0)
    {
        temp = pop();
        postfix[j] = temp;
        j++;
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

void push(char item)
{
    top++;
    stack[top] = item;
}

char pop()
{
    if (top < 0) // Check for underflow
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    char item = stack[top];
    top--;
    return item;
}

int prec(char symb)
{
    switch (symb)
    {
    case '#':
        return -1;
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
    case '$':
        return 3;
    default:
        return -1; // Return a default value to avoid undefined behaviour
    }
}