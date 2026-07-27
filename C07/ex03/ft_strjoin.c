/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbogucki <nbogucki@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:13:38 by nbogucki          #+#    #+#             */
/*   Updated: 2026/07/27 06:34:21 by nbogucki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//#include <stdio.h>

int	hm_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	hm_bigboi_strlen(int size, char **aos)
{
	int	i;

	i = 0;
	while (size-- > 0)
		i += hm_strlen(aos[size]);
	return (i);
}

void	format_str(int size, char **aoc, char *sep, char *res)
{
	int	i;
	int	ii;
	int	c;

	i = 0;
	c = 0;
	while (i < size)
	{
		ii = 0;
		while (aoc[i][ii])
			res[c++] = aoc[i][ii++];
		if (i < size - 1)
		{
			ii = 0;
			while (sep[ii])
				res[c++] = sep[ii++];
		}
		i++;
	}
	res[c] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*p_str;

	p_str = malloc(sizeof(char) * (hm_bigboi_strlen(size, strs)
				+ (hm_strlen(sep) * (size - 1)) + 1));
	if (p_str == NULL)
		return (NULL);
	format_str(size, strs, sep, p_str);
	return (p_str);
}
/*
int	main()
//int	main(int ac, char **av)
{
	char	*str;
	char	*arr[] = {
		"I",
		"hear",
		"birds."
	};
	
	str = ft_strjoin(3, arr, "-_");
	printf("the string is: \"%s\"\n", str);
	str = ft_strjoin(0, arr, "-_");
	printf("the string is: \"%s\"\n", str);
	free(str);
	return (0);
}
*/
