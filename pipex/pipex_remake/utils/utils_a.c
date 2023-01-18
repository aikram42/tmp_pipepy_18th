/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:02:59 by aikram            #+#    #+#             */
/*   Updated: 2023/01/18 18:42:58 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pp.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*str;

	i = 0;
	str = malloc(count * size);
	if (!str)
		return (0);
	while (i < (count * size))
		((char *)str)[i++] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i[2];

	i[0] = 0;
	i[1] = -1;
	if (!s1 || !s2)
		return (NULL);
	s = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(*s));
	if (!s)
		return (0);
	while (s1[++i[1]])
		s[i[1]] = s1[i[1]];
	while (s2[i[0]])
		s[i[1]++] = s2[i[0]++];
	return (s);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i < n - 1
			&& s1[i] && s2[i])
		i++;
	if (n)
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}
