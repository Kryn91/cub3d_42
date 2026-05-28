/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:55:36 by kealves-          #+#    #+#             */
/*   Updated: 2025/11/19 15:44:07 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digit(long nb)
{
	long	temp;
	int		count;

	temp = nb;
	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		count = 1 ;
	while (temp)
	{
		temp /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*tab;
	int		len;

	nb = (long) n;
	len = count_digit(nb);
	tab = (char *) malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	tab[len] = '\0';
	if (nb == 0)
		tab[0] = '0';
	if (nb < 0)
	{
		nb = -nb;
		tab[0] = '-';
	}
	while (nb)
	{
		len = len - 1;
		tab[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (tab);
}
/*
#include <stdio.h>
int main(void)
{
    int nums[] = {0, 42, -42, 123456, -123456, 2147483647, -2147483648};
    char *s;

    for (int i = 0; i < 7; i++)
    {
        s = ft_itoa(0);
        printf("ft_itoa(%d) = \"%s\"\n", nums[i], s);
        free(s);
    }
    return 0;
}
*/
