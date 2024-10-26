/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassos- <rpassos-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:28:47 by rpassos-          #+#    #+#             */
/*   Updated: 2024/10/25 18:29:39 by rpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <stdlib.h>
# include <unistd.h>


char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
int check_nl_or_null(char *store);
void    clear_static(char *s, int range);
char *concat_line(char *store, char *full_line);
char *read_line(int fd);
char *get_next_line(int fd);

#endif
