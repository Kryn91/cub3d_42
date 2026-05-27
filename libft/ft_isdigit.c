/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:45:40 by kealves-          #+#    #+#             */
/*   Updated: 2025/11/13 16:30:01 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int ch)
{
	if (ch >= 48 && ch <= 57)
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	unsigned char c = '4';
	printf("%d\n", ft_isdigit(c));
	printf("%d\n", isdigit(c));
}
*/
