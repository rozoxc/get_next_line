/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:47:22 by ababdoul          #+#    #+#             */
/*   Updated: 2024/11/20 21:40:26 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void free_string_array(char **array)
{
    int i;

    if (!array)
        return;
    i = 0;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}
char	*return_line(char **lines, int length)
{
	static int	i = 0;

	if (i < length && lines[i] != NULL)
	{
		i++;
		return (lines[i - 1]);
	}
	return (NULL);
}
int	count_lines(char *str)
{
	int	i;
	int	lines;

	i = 0;
	lines = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			lines++;
		i++;
	}
	return (lines + 1);
}
char	*allocate_line(char *str, int start, int end)
{
	char	*line;
	int		len;

	len = end - start + 1;
	line = malloc(len + 1);
	if (!line)
    {
        free(line);
		return (NULL);
    }
	ft_strncpy(line, &str[start], len);
	line[len] = '\0';
	return (line);
}
char	**get_lines(char *str, int *line_count)
{
	char	**array;
	int		i;
	int		j;
	int		start;

	*line_count = count_lines(str);
	array = malloc(sizeof(char *) * (*line_count + 1));
	if (!array)
    {
        free_string_array(array);
		return (NULL);
    }
	i = 0;
	j = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			array[j++] = allocate_line(str, start, i);
			start = i + 1;
		}
		i++;
	}
	if (start < i)
		array[j++] = allocate_line(str, start, i - 1);
	array[j] = NULL;
	return (array);
}
char	*read_entire_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*str;
	char	*temp;
	ssize_t	bytes_read;

	str = malloc(1);
	if (!str)
    {
        free(str);
		return (NULL);
    }
	str[0] = '\0';
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		temp = str;
		str = malloc(ft_strlen(temp) + bytes_read + 1);
		if (!str)
        {
            free(str);
			return (NULL);
        }
		ft_strcpy(str, temp);
		ft_strcat(str, buffer);
		free(temp);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	static char	**lines = NULL;
	static int	line_count = 0;
	static int	initialized = 0;

	if (!initialized)
	{
		str = read_entire_file(fd);
		if (!str)
			return (NULL);
		lines = get_lines(str, &line_count);
		if (!lines)
			return (NULL);
		initialized = 1;
	}
	return (return_line(lines, line_count));
}
// int main() {
//     int fd = open("file.txt", O_RDONLY);
//     if (fd < 0) {
//         perror("Failed to read the file");
//         return 1;
//     }

//     char *line;
//     while ((line = get_next_line(fd)) != NULL) {
//         printf("%s", line);
//         free(line); // Free each line returned by `get_next_line`.
//     }
//     close(fd);
//     //check_leaks(); // Check for memory leaks (optional).
//     return 0;
// }