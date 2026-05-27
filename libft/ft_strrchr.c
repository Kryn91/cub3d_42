/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:05:48 by kealves-          #+#    #+#             */
/*   Updated: 2025/11/14 19:31:03 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	length;
	int	i;

	length = 0;
	while (str[length] != '\0')
		length++;
	i = length;
	while (i > -1)
	{
		if (str[i] == (char) ch)
			return ((char *)str + i);
		i--;
	}
	if (ch == '\0')
		return ((char *)str + i);
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char *str = "abbbbbbb";
	printf("%s\n", ft_strrchr(str, 'a'));
	printf("%s\n", strrchr(str, 'a'));

}
*/
