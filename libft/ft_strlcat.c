/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:03:30 by kealves-          #+#    #+#             */
/*   Updated: 2025/11/14 10:58:52 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	dstlen;
	unsigned long	srclen;
	unsigned long	i;

	dstlen = 0;
	srclen = 0;
	i = 0;
	while (dstlen < size && dst[dstlen])
		dstlen++;
	while (src[srclen])
		srclen++;
	if (dstlen == size)
		return (size + srclen);
	while (src[i] && (dstlen + i + 1) < size)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if (dstlen + i < size)
		dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
/*
int	main(void)
{
	char str[20] = "Hello";
	size_t result;

	result = ft_strlcat(str, " World!", sizeof(str));
	printf("chaine finale %s\n", str);
	printf("lentgh : %zu\n", result); 
}
*/
