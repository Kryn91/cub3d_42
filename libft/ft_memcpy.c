/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:54:10 by kealves-          #+#    #+#             */
/*   Updated: 2025/11/19 11:45:53 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t	i;
	char	*cdest;
	char	*csrc;

	i = 0;
	if (!dest && !src)
		return (NULL);
	cdest = (char *)dest;
	csrc = (char *)src;
	while (i < count)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (cdest);
}
/*
int	main(void)
{
	char src[] = "aaaaaaaa";
	char dest[] = "bbbbbbbb";
	printf("avant %s\n", dest);
	ft_memcpy(dest, src, 5);
	printf("apres %s\n", dest);
}
*/
