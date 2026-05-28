/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:31:02 by kealves-          #+#    #+#             */
/*   Updated: 2025/11/19 14:21:02 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr( const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char) ch)
			return ((char *)str + i);
		i++;
	}
	if ((char)ch == '\0')
		return ((char *)str + i);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char str[] = "bonjour\0le monde";
	printf("%s\n", ft_strchr(str, '\0'));
	printf("%s\n", strchr(str, '\0'));

}
*/
