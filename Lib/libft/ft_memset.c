/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:10:43 by kealves-          #+#    #+#             */
/*   Updated: 2025/11/13 16:33:41 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int ch, size_t count)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)dest;
	while (i < count)
	{
		str[i] = ch;
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char  str[] = "ooooooooooooo";
	puts(str);
	ft_memset(str, 'x', 5);
	puts(str);
}
*/
