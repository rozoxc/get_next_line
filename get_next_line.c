/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:47:22 by ababdoul          #+#    #+#             */
/*   Updated: 2024/11/18 02:48:35 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int has_newline(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (ft_strchr(&str[i], '\n'))
            return (1);
    }
    return (0);
}
char *extract_line(const char *str)
{
    
}

char *save_after_newline(const char *str);
{

}

char *append_to_str(char *str, const char *buffer);
{
    
}
char *get_next_line(int fd) {
    static char *str;    // Static variable to store leftover data
    char *buffer;        // Buffer for reading
    ssize_t bytes_read;  // Number of bytes read
    char *line;          // Line to return

    // 1. Validate input and allocate buffer
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);

    // 2. Append new data to leftover
    while (!has_newline(str)) {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        str = append_to_str(str, buffer);
    }
    free(buffer);

    // 3. Extract line and update leftover
    if (has_newline(str)) {
        line = extract_line(str);
        str = save_after_newline(str);
        return (line);
    }

    // 4. Handle EOF
    if (str) {
        line = str;
        str = NULL;
        return (line);
    }
    return (NULL);
}

