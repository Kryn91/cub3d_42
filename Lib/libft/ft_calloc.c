/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:27:00 by kealves-          #+#    #+#             */
/*   Updated: 2025/11/25 10:56:09 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	long	len;
	void	*str;

	len = (long)num * (long)size;
	if (size > 65535)
		return (NULL);
	if (size == 0)
	{
		str = NULL;
		return (str);
	}
	str = malloc(len);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, len);
	return (str);
}
