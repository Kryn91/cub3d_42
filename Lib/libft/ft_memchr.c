/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:59:15 by kealves-          #+#    #+#             */
/*   Updated: 2025/11/13 16:31:08 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	size_t		i;
	const char	*str;

	i = 0;
	str = (char *)ptr;
	while (i < count)
	{
		if (*str == (char) ch)
			return ((void *)str);
		str++;
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const	char str[] = "ABCDEFG";
	printf("%s\n", str);
	const char *ps = ft_memchr(str, 'H', 3);
	printf("%s\n", ps);
}
*/
