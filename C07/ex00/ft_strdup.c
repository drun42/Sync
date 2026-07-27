/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbogucki <nbogucki@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 13:16:56 by nbogucki          #+#    #+#             */
/*   Updated: 2026/07/22 09:02:10 by nbogucki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//#include <string.h>
//#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	i = 0;
	while (src[i])
		i++;
	str = malloc(i);
	i = 0;
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char foo[] = "I hear birds.";
	char *bar = ft_strdup(foo);

	printf("ft_strdup of %s (%p) = %s (%p)\n", foo, &foo, bar, bar);
	return (0);
}
*/
