#include<stdio.h>
#include<stdlib.h>

void evaluate();
void push(char);
char pop();
int precision(char);
char infix[30], postfix[30], stack[30];
int top = -1;

void evaluate()
{
    int i = 0, j = 0;
    char symb, temp;
    push('#');
    for(i=0; infix[i] != '\0'; i++)
    {
        symb = infix[i];
        switch(symb)
        {
            case '(' :  push(symb);
                        break;

            case ')' :  temp = pop();
                        while(temp != '(' )
                        {
                            postfix[j] = temp;
                            j++;
                            temp = pop();
                        }
                        break;
            case '+' :
            case '-' :
            case '*' :
            case '/' :
            case '%' :
            case '^' :
            case '$'  : while( precision(stack[top]) >= precision(symb) )
                        {
                            temp = pop();
                            postfix[j] = temp;
                            j++;
                        }
                        push(symb);
                        break;
            default:    postfix[j] = symb;
                        j++;
        }
    }
    while(top > 0)
    {
        temp = pop();
        postfix[j] = temp;
        j++;
    }
    postfix[j] = '\0';
}

void push(char item)
{
    top = top+1;
    stack[top] = item;
}


char pop()
{
    char item;
    item = stack[top];
    top = top-1;
    return item;
}

//SYMBOL PRECISION
int precision(char symb)
{
    int p;
    switch(symb)
    {
        case '#' :  p = -1;
                    break;

        case '(' :
        case ')' :   p = 0;
                    break;

        case '+' :
        case '-' :   p = 1;
                    break;

        case '*' :
        case '/' :
        case '%' : p = 2;
                    break;

        case '^' :
        case '$' :  p = 3;
                    break;
    }
    return p;
}

void main()
{
    printf("\n Enter the valid infix expression : ");
    scanf("%s", infix);
    evaluate();
    printf(" The entered infix expression is :  %s", infix);
    printf("\n The corresponding postfix expression is : %s  \n", postfix);
}