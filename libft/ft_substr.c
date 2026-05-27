/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:59:08 by kealves-          #+#    #+#             */
/*   Updated: 2025/11/20 11:18:52 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		return (sub[0] = '\0', sub);
	}
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub[i] = '\0', sub);
}
/*
#include <stdio.h>
int	main(void)
{
const char str[] = "bonjour le monde";
char *sub = ft_substr(str, 10, 10);
printf("%s", sub);
free (sub);
}
*/
