/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:14:09 by kealves-          #+#    #+#             */
/*   Updated: 2025/11/19 13:56:35 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *lhs, const void *rhs, size_t count)
{
	size_t			i;
	unsigned char	*cmp;
	unsigned char	*tocmp;

	i = 0;
	cmp = (unsigned char *)lhs;
	tocmp = (unsigned char *)rhs;
	if (count == 0)
		return (0);
	while (*cmp == *tocmp && i < count - 1)
	{
		cmp++;
		tocmp++;
		i++;
	}
	return (*cmp - *tocmp);
}
/*
int	main(void)
{
	const char str[] = "Hello";
	const char str1[] = "Hello";
	printf("%d\n", ft_memcmp(str, str1, 2));
	printf("%d\n", memcmp(str, str1, 2));
}
*/
