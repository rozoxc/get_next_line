#include "get_next_line.h"
#include <string.h>
// char *get_next_line(char *p)
// {
//     static char **str;
//     int i;
//     int j;

//     i = 0;
//     if (str[i] == NULL)
//         str[i] = ft_strdup("");
// }
void f()
{
    system("leaks a.out");
}
char *get_next_line(int fd)
{
    static char **str;
    char *p;
    int i = 0;

    p = mallos(sizeof(char) * BUFFER_SIZE);
    if (p == NULL)
        return (NULL);
}

int main() {
    int fd = open("file.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);
    }
    f();
    close(fd);
    return 0;
}
