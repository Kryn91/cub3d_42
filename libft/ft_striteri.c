/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:59:48 by kealves-          #+#    #+#             */
/*   Updated: 2025/11/19 11:17:33 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	to_upper(unsigned int i, char *s)
{
		if (*s >= 'a' || *s <= 'z')
			*s -= 32;
}

#include <stdio.h>
int	main(void)
{
	char	str[] = "bonjour";
	printf("avant %s\n", str);
	ft_striteri(str, &to_upper);
	printf("apres %s\n", str);
}
*/
