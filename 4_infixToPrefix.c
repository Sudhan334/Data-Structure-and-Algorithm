#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
int precedency(char);
int isOperator(char);

int main()
{

    int otos = -1, ptos = -1, len, length;
    char infix[100], prestack[100], opstack[100];
    printf("Enter a valid infix \n");
    gets(infix);
    length = strlen(infix);
    len = length;
    for (int i = length; i >=0; i--)
    {
        if (infix[i] == ')')
        {
            opstack[++otos] = infix[i];
        }
        else if (isOperator(infix[i]) == 0)
        {
            prestack[++ptos] = infix[i];
        }
        else if (isOperator(infix[i]) == 1)
        {
            while (((precedency(opstack[otos]) >= precedency(infix[i])) && (otos != -1)) && (infix[i] != '$'))
            {
                prestack[++ptos] = opstack[otos];
                --otos;
            }
            opstack[++otos] = infix[i];
        }
        else if (infix[i] = '(')
        {

            while (opstack[otos] != ')')
            {
                prestack[++ptos] = opstack[otos];
                otos--;
            }
            otos--; // to remove the left over ( at the end.
        }
    }
    while (otos != -1)
    {
        prestack[++ptos] = opstack[otos];
        otos--;
    }
    // prestack[++ptos] = '\0';
    // printf("%s", prestack);
    for (int i = len; i >=0 ; i--)
    {
        printf("%c",prestack[i]);
    }
    
    getch();
}

int precedency(char ch)
{
    switch (ch)
    {
    case '$':
        return (4);
    case '*':
    case '/':
        return (3);
    case '+':
    case '-':
        return (2);
    default:
        return (1);
    }
}
int isOperator(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}