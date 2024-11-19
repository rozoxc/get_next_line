#ifndef  GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# define BUFFER_SIZE  10
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 11
#endif
char    *get_next_line(int fd);
void    ft_putchar_fd(char c, int fd);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *s, int c);
size_t  ft_strlen(const char *s);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char *ft_strcat(char *dest, char *src);
char    *ft_strcpy(char *s1, char *s2);

#endif