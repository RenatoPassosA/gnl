/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassos- <rpassos-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:40:42 by rpassos-          #+#    #+#             */
/*   Updated: 2024/10/21 16:40:44 by rpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check_nl_or_null(char *store)
{
    int index;

    index = 0;
    while (index < BUFFER_SIZE)
    {
        if (store[index] == '\n' || store[index] == '\0')
            return (index);
        index++;
    }
    return (index);
}

void    clear_static(char *s, int range)
{
    int index;

    index = 0;
    while (index < range)
    {
        s[index] = '\0';
        index++;
    }
    free(s);

}

char *concat_line(char *store, char *full_line)
{
    int index;
    int index_static;
    char *temp;
    static char *s;

    if (!s)
    {
        s = (char *)malloc(sizeof(char) * BUFFER_SIZE  * 2);
        s[0] = '\0';
    }
    if (s[0] == '\0')
    {
        index = 0;
        if ((index = check_nl_or_null(store)) != BUFFER_SIZE )
        {
        if (index != BUFFER_SIZE )
                index++;
            free(s);
        s = ft_strjoin(s, store + index);
        store[index] = '\0';
        free(full_line);
        full_line = ft_strjoin(full_line, store);
        return (full_line);
        }
        else
        {
            free(full_line);
            full_line = ft_strjoin(full_line, store);
            return(full_line);
        }
    }
    else
    {
        index_static = check_nl_or_null(s);
        index = check_nl_or_null(store);
        temp = (char *)malloc(sizeof(char) * ((BUFFER_SIZE  - index_static) + index));
        if (!temp)
            return (NULL);
        s[index_static + 1] = '\0';
        temp = ft_strjoin(s, store);
        free(full_line);
        full_line = ft_strjoin(full_line, temp);
        free(temp);
        clear_static(s, index_static);
        clear_static(temp, BUFFER_SIZE  - index_static);
        return (full_line);
    }
}

char *read_line(int fd)
{
    char *store;
    char *full_line;
    int index;
    int read_return;

    index = 0;
    read_return = -1;
    full_line = (char *)malloc(0);
    store = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if (!store)
        return (NULL);
    while (1)
    {
        read_return = read(fd, store, BUFFER_SIZE);
        if (read_return == 0)
            break;

        full_line = concat_line(store, full_line);
   
        if (!full_line)
            return (NULL);
        while (full_line[index])
            index++;
        if (full_line[index - 1] == '\n')
            break;
        index = 0;
    }
    free(store);
    return (full_line);
}

char *get_next_line(int fd)
{
    char *line;

    if (fd == -1)
        return (NULL);
    line = read_line(fd);
    return (line);
}

int main(void)
{
    #include <fcntl.h>
    #include <stdio.h>
    char *line;

    int fd = open("teste.txt", O_RDONLY);
    line = get_next_line(fd);
   // printf("1: %d\n", fd);
    line = get_next_line(fd);
  //  printf("2: %d\n", fd);
    line = get_next_line(fd);
   // printf("3: %d\n", fd);
    line = get_next_line(fd);
   // printf("4: %d\n", fd);
    line = get_next_line(fd);
  //  line = get_next_line(fd);
    





 



 /* line = get_next_line(fd);
    line = get_next_line(fd);

    line = get_next_line(fd);
    line = get_next_line(fd);
    line = get_next_line(fd);
    line = get_next_line(fd);*/


    int index = 0;

    while(line[index])
    {
        write(1, &line[index], 1);
        index++;
    }
    printf("\n");

    printf("%d", index);
}

