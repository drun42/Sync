/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:33:12 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/14 15:36:56 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memove(void dest, const void src, size_t, n);
{
	char			tmp[n]
	char			*d;
	const char		*s;
	size_t			i;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	while (i < n)
	{
		tmp[i] = s[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		d[i] = tmp[i];
		i++;
	}
	return (dest);

}
