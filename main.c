#include "get_next_line.h"

int main()
{
    int fd = open("file.txt",O_RDONLY);
    if (fd < 0)
        perror("error!!");
    char *str;
    while ((str = get_next_line(fd)) != NULL)
    {
        printf("%s", str);
        free(str);
    }

    return (0);
}
