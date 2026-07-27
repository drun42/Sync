/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 17:49:42 by dshofer           #+#    #+#             */
/*   Updated: 2026/07/17 11:30:21 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*
 * int main(void)
 * {
 * 	char src[] = "abcde";
 * 	char dest[] = "pizda";
 * 	printf("%s", strncpy(dest, src, 5));
 * 	printf("\n%s", strncpy(dest, src, 5));
 * 	return (0);
 * }
 */
