/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_tolower : turn one upper case letter into its lower case twin.
**
** man: tolower() converts the letter c to lower case, if possible.
** man: the value returned is that of the converted letter, or c if the
** conversion was not possible.
**
** Same contract as ft_toupper, mirrored: anything that is not an upper
** case letter must come back UNCHANGED.
**
** In ASCII the lower case block sits 32 above the upper case one, so
** adding 32 to an upper case letter lands on its lower case twin.
** =========================================================================
*/

int	ft_tolower(int c)
{
	// only an upper case letter is converted
	if (c >= 'A' && c <= 'Z')
		// the lower case block is 32 higher in the table
		return (c + 32);
	// everything else comes back untouched
	return (c);
}
