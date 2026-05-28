/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:10:22 by kealves-          #+#    #+#             */
/*   Updated: 2025/11/14 13:59:53 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int ch)
{
	if ((ch >= 32 && ch <= 126))
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	unsigned char ch = '\0';
	int i = 0;
	while (i < 127)
	{
		if (ft_isprint(ch))
			printf(" %d	char %C is printable\n", i , ch);
		else
			printf("%d	char %C is not printable\n", i, ch);
		ch++;
		i++;
	}
}
*/
