/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:23:52 by kealves-          #+#    #+#             */
/*   Updated: 2025/11/17 11:52:46 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *lhs, const char *rhs, size_t count)
{
	size_t			i;
	unsigned char	*clhs;
	unsigned char	*crhs;

	i = 0;
	clhs = (unsigned char *)lhs;
	crhs = (unsigned char *)rhs;
	if (count == 0)
		return (0);
	while (*clhs && *crhs == *clhs && i < count - 1)
	{
		clhs++;
		crhs++;
		i++;
	}
	return (*clhs - *crhs);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char	str[] = "abcdefg";
	const char	str1[] = "abcdwxy";
	printf("%d\n", ft_strncmp(str, str1, 4));
	printf("%d\n", strncmp(str, str1, 4));
}
*/
