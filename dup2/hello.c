#include "../apue.h"

#define   STR    ("hello world.....\n")

int main(int argc, char const* argv[])
{
    int fd = open("a.txt", O_RDONLY|O_WRONLY|O_CREAT, S_IRWXU);
    if (fd < 0){
        perror("error ");
        exit(0);
    }
    write(fd, STR, strlen(STR));
    dup2(fd, STDOUT_FILENO);
    printf("hello world\n");
    printf("hello world\n");
    printf("hello world\n");
    printf("hello world\n");
    close(fd);
    return 0;
}
