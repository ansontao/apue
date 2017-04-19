#include "math.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void Error(char *msg)
{
    perror(msg);
    exit(-1);
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

