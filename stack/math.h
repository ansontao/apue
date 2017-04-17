
#define EmptyTOS (-1)

#define MinStackSize (5)

typedef int ElementType;

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

