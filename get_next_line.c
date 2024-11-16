/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:47:22 by ababdoul          #+#    #+#             */
/*   Updated: 2024/11/16 17:20:27 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    if (fd < 0)
        return (NULL);
    char *p;
    ssize_t byte_read;
    
    if (fd == EOF)
        return (NULL);
    p = malloc(sizeof(char) * BUFFER_SIZE);
    if (p == NULL)
        return (NULL);
    byte_read = read(fd , p, BUFFER_SIZE);
    return (p);
}