#ifndef  GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char    *get_next_line(int fd);
void    ft_putchar_fd(char c, int fd);
#endif