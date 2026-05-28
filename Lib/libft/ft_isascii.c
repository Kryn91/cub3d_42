/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:30:55 by kealves-          #+#    #+#             */
/*   Updated: 2025/11/13 16:29:04 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int ch)
{
	if (ch >= 0 && ch <= 127)
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	unsigned char ch = 0x7c;
	int	i = 0;
	while (i < 255)
	{
		if (ft_isascii(ch))
			printf("The character is %c\n", ch);
		else
		       printf("Cannot be represented by ascii\n");
		ch++;
		i++;	
	}
}
*/
