#include "math.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#define   STACK_SLOT    100

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
        } else if (isOperator(ch))
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

