#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <ctype.h> // Include this header for isdigit() 
 
int i, top = -1; 
int op1, op2, res, s[20]; 
char postfix[90], symb; 
 
void push(int item) 
{ 
    if (top >= 19) // Prevent stack overflow 
    { 
        printf("Stack Overflow\n"); 
        exit(1); 
    } 
    top = top + 1; 
    s[top] = item; 
} 
 
int pop() 
{ 
    if (top < 0) // Prevent stack underflow 
    { 
        printf("Stack Underflow\n"); 
        exit(1); 
    } 
    int item = s[top]; 
    top = top - 1; 
    return item; 
} 
 
int main() 
{ 
    printf("\nEnter a valid postfix expression:\n"); 
    scanf("%s", postfix); 
    for (i = 0; postfix[i] != '\0'; i++) 
    { 
        symb = postfix[i]; 
        if (isdigit(symb)) 
        { 
            push(symb - '0'); 
        } 
        else 
        { 
            if (top < 1) 
            { 
                printf("Invalid postfix expression\n"); 
                exit(1); 
            } 
            op2 = pop(); 
            op1 = pop(); 
            switch (symb) 
            { 
            case '+': 
                push(op1 + op2); 
                break; 
            case '-': 
                push(op1 - op2); 
                break; 
            case '*': 
                push(op1 * op2); 
                break; 
            case '/': 
                if (op2 == 0) 
                { 
                    printf("Division by zero error\n"); 
                    exit(1); 
                } 
                push(op1 / op2); 
                break; 
            case '%': 
                if (op2 == 0) 
                { 
                    printf("Modulo by zero error\n"); 
                    exit(1); 
                } 
                push(op1 % op2); 
                break; 
            case '$': 
            case '^': 
                { 
                    int result = 1; 
                    for (int j = 0; j < op2; j++) 
                    { 
                        result *= op1; 
                    } 
                    push(result); 
                } 
                break; 
            default: 
                printf("Invalid operator: %c\n", symb); 
                exit(1); 
            } 
        } 
    } 
    res = pop(); 
    if (top >= 0) 
    { 
        printf("Invalid postfix expression\n"); 
        exit(1); 
    } 
printf("\nResult = %d\n", res); 
return 0; 
}