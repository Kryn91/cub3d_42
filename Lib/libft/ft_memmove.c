/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:10:47 by kealves-          #+#    #+#             */
/*   Updated: 2025/11/14 13:51:40 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t				i;
	unsigned char		*cdest;
	const unsigned char	*csrc;

	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	if (cdest < csrc)
	{
		i = 0;
		while (i < count)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	if (cdest > csrc)
	{
		i = count;
		while (i > 0)
		{
			cdest[i - 1] = csrc[i - 1];
			i--;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char src[] = "aaaaaaaaaaa";
	char dest[] = "bbbbbbbbbbbbbbbbb";
	printf("avant %s\n", dest);
	ft_memmove(dest, src, 5);
	printf("apres %s\n", dest);
}
*/
