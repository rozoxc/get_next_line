#include "get_next_line.h"
int main()
{
    char *buffer;
    ssize_t a = read(0, buffer, 5);
    printf("%zd\n", a);
    printf("%s\n", buffer);
    return (0);
}