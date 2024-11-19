#include "get_next_line.h"

int main()
{
    int fd = open("file.txt",O_RDONLY);
    if (fd < 0)
        perror("error!!");
    printf("%s", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));


    return (0);
}