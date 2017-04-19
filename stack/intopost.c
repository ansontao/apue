#include <stdio.h>
#include <ctype.h>
#include "math.h"
#include "stack.h"

#define   STACK_SLOT    100

int isOperator(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
            return 1;
            break;
        default:
            return 0;
    }
}

int isBracker(char ch)
{
     switch(ch)
     {
         case '(':
         case ')':
             return 1;
     }
     return 0;
}

int isRightBra(char ch)
{
    return ch == ')';
}

int compOperator(char a, char b)
{
    if (b == '(')
        return 1;
    return -(a-b);
}

int main(int argc, char const* argv[])
{
    FILE *file;
    char ch;
    int  num;
    Stack math = CreateStack(STACK_SLOT);

    file = fopen("math.txt", "r+");
    if (file == NULL)
        Error("file open failed");

    while ((ch = fgetc(file)) != EOF)
    {
        if (isdigit(ch))
        {
            ungetc(ch, file);
            fscanf(file, "%d", &num);
            printf("%d ", num);
        }

        if (isOperator(ch))
        {
            while(!IsEmpty(math) && (compOperator(ch, Top(math)) <= 0))
            {
                char op = TopAndPop(math);
                printf("%c ", op);
            }
            if (ch != ')')
                Push(ch, math);
            else{
                 while (!IsEmpty(math))
                 {
                     char op = TopAndPop(math);
                     if (op != '(')
                         printf("%c ", op);
                 }
            }
        }
    }

    while(!IsEmpty(math))
    {
        ch = TopAndPop(math);
        printf("%c ", ch);
    }
        printf("\n");

    return 0;
}
