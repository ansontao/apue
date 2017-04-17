#include "math.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#define   STACK_SLOT    100

void Error(char *msg)
{
    perror(msg);
    exit(-1);
}

int isOperator(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
            break;
        default:
            return 0;
    }
}

int calc(char ch, int a, int b)
{
    int res;
    switch (ch)
    {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
        default:
            return 0;
    }
    return res;
}

int main(int argc, char const* argv[])
{
    int fd;
    FILE *file;
    char ch;
    printf("hello world\n");
    file = fopen("data.txt", "r+");
    if (file == NULL)
        Error("file open failed");

    Stack math = CreateStack(STACK_SLOT);
    while( (ch = fgetc(file)) != EOF )
    {
        if (isdigit(ch)){
            ungetc(ch, file);
            fscanf(file, "%d", &fd);
            Push(fd, math);
        }
        if (isOperator(ch))
        {
            Push(calc(ch, TopAndPop(math), TopAndPop(math)), math);
        }
    }
    while (!IsEmpty(math))
    {
        fd = TopAndPop(math);
        printf("%d ", fd);
    }
    printf("\n");
    return 0;
}

Stack CreateStack( int MaxElements )
{
     Stack S;

     if (MaxElements < MinStackSize)
         Error("Stack Size is too small");

     S= malloc( sizeof(struct StackRecord) );
     if (S == NULL)
         Error(" Out of space!!!");

     S->Array = malloc(MaxElements * sizeof(ElementType));
     if (S->Array == NULL)
         Error("Out of space");

     S->Capacity = MaxElements;
     MakeEmpty( S );

     return S;
}

void DisposeStack( Stack S )
{
     if (S != NULL)
     {
         free(S->Array);
         free(S);
     }
}

int IsEmpty( Stack S )
{
     return S->TopOfStack == EmptyTOS;
}

int IsFull( Stack S )
{
    return S->TopOfStack == S->Capacity-1;
}

void MakeEmpty( Stack S )
{
     S->TopOfStack = EmptyTOS;
}

void Push( ElementType X, Stack S )
{
     if ( IsFull(S) )
         Error("Full stack");
     else {
         S->Array[++S->TopOfStack] = X;
     }
}

ElementType
Top( Stack S )
{
     if (!IsEmpty( S ))
         return S->Array[S->TopOfStack];

     Error("Empty Stack");
     return 0;
}

void Pop( Stack S )
{
     if (!IsEmpty( S ))
         S->TopOfStack--;
     else
         Error("Empty stack");
}

ElementType
TopAndPop(Stack S)
{
     if (!IsEmpty(S))
         return S->Array[S->TopOfStack--];
     else {
         Error("Empty stack");
         return 0;
     }
}
