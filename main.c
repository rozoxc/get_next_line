#include "get_next_line.h"

int main()
{
    int fd = open("file.txt",O_RDONLY);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));

    return (0);
}