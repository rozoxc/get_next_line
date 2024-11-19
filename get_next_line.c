/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:47:22 by ababdoul          #+#    #+#             */
/*   Updated: 2024/11/19 23:10:14 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void f()
// {
//     system("leaks a.out");
// }
char *return_line(char **str, int length) {
    static int i = 0;
    if (i < length && str[i] != NULL) {
        return str[i];
        i++;
    }
    return NULL;
}

char **get_lines(char *str, int *line_count) {
    int i = 0, j = 0, start = 0;
    int lines = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            lines++;
        i++;
    }
    lines++;
    *line_count = lines;
    char **array = malloc(sizeof(char *) * (lines + 1));
    if (!array)
        return NULL;

    i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            array[j] = malloc(i - start + 2);
            if (!array[j])
                return NULL;
            ft_strncpy(array[j], &str[start], i - start + 1);
            array[j][i - start + 1] = '\0';
            start = i + 1;
            j++;
        }
        i++;
    }
    if (start < i) {
        array[j] = malloc(i - start + 1);
        ft_strncpy(array[j], &str[start], i - start);
        array[j][i - start] = '\0';
        j++;
    }
    array[j] = NULL;

    return array;
}

char *get_next_line(int fd) {
    static char *str = NULL;
    static char **lines = NULL;
    static int line_count = 0;
    static int initialized = 0;

    if (!initialized) {
        char buffer[BUFFER_SIZE + 1];
        ssize_t bytes_read;

        // Read the entire file content
        str = malloc(1);
        str[0] = '\0';
        while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
        {
            buffer[bytes_read] = '\0';
            char *temp = str;
            str = malloc(ft_strlen(temp) + bytes_read + 1);
            ft_strcpy(str, temp);
            ft_strcat(str, buffer);
            free(temp);
        }
        lines = get_lines(str, &line_count);
        initialized = 1;
    }
    return return_line(lines, line_count);
}

// int main()
// {
//     int fd = open("file.txt", O_RDONLY);
//     if (fd < 0)
//         perror("faild to read");
//         char *str;
//     while ((str = get_next_line(fd)) != NULL)
//     {
//         printf("%s", str);
//         free(str);
//     }
//     f();
// 