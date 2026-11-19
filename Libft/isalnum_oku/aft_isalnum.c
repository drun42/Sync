/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_isalnum : is this byte a letter or a digit ?
**
** man: isalnum() checks for an alphanumeric character; it is equivalent to
** (isalpha(c) || isdigit(c)).
**
** SUBJECT: the return value must be exactly 1 or exactly 0.
**
** The two conditions of ft_isalpha and the one of ft_isdigit are repeated
** here on purpose, so this file compiles on its own and needs no prototype
** of another function of the library.
**
** The condition is split over two lines because it is long; the operator
** || starts the second line so the reader sees at once that it continues.
** =========================================================================
*/

int	ft_isalnum(int c)
{
	// letters, lower case and upper case, then the digits on the next line
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
