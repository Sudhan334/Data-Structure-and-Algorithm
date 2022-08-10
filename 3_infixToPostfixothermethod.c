#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
int precedency(char);
int isOperator(char);

int main()
{

    int opstackPointer = -1, poststackPointer = -1, len, length;
    char infix[100], poststack[100], opstack[100];
    printf("Enter a valid infix \n");
    gets(infix);
    length = strlen(infix);
    len = length;
    for (int i = 0; i < length; i++)
    {
        if (infix[i] == '(')
        {
            opstack[++opstackPointer] = infix[i];
        }
        else if (isOperator(infix[i]) == 0)
        {
            poststack[++poststackPointer] = infix[i];
        }
        else if (isOperator(infix[i]) == 1)
        {
            while (((precedency(opstack[opstackPointer]) >= precedency(infix[i])) && (opstackPointer != -1)) && (infix[i] != '$'))
            {
                poststack[++poststackPointer] = opstack[opstackPointer];
                --opstackPointer;
            }
            opstack[++opstackPointer] = infix[i];
        }
        else if (infix[i] = ')')
        {

            while (opstack[opstackPointer] != '(')
            {
                poststack[++poststackPointer] = opstack[opstackPointer];
                opstackPointer--;
            }
            opstackPointer--; // to remove the left over ( at the end.
        }
    }
    while (opstackPointer != -1)
    {
        poststack[++poststackPointer] = opstack[opstackPointer];
        opstackPointer--;
    }
    poststack[++poststackPointer] = '\0';
    printf("%s", poststack);
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