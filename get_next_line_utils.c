/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:16:28 by ababdoul          #+#    #+#             */
/*   Updated: 2024/11/16 22:53:50 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while(s[i] != '\0')
        i++;
    return (i);
}
char	*ft_strdup(const char *str)
{
    int     i;
    char    *p;

    i = 0;
    p = malloc(sizeof(char) * (ft_strlen(str) + 1));
    if (p == NULL)
        return (NULL);
    while (str[i] != '\0')
    {
        p[i] = str[i];
        i++;
    }
    p[i] = '\0';
    return (p);
}
char	*ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
            return ((char *)s + i);
        i++;
    }
    if ((char)c == '\0')
        return ((char *)s + i);
    return (NULL);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  i;
    char    *p;

    i = 0;
    if (s == NULL)
        return (NULL);
    if (start > len)
        return (ft_strdup(""));
    if (len > ft_strlen(s) - start)
        len  = ft_strlen(s) - start;
    p = malloc(sizeof(char) * (len + 1));
    while (i < len)
    {
        p[i] = s[start + i];
        i++;
    }    
    p[i] = '\0';
    return (p);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
    char    *p;
    int      i;

    i = 0;
    p = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (p == NULL)
        return (NULL);
    if (s1 == NULL || s2 == NULL)
        return (NULL);
    while (s1[i] != '\0')
    {
        p[i] = s1[i];
        i++;
    }
    while (s2[i] != '\0')
    {
        p[i] = s2[i];
        i++;
    }
    p[i] = '\0';
    return (p);
}
