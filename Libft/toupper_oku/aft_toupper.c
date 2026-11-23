/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_toupper : turn one lower case letter into its upper case twin.
**
** man: toupper() converts the letter c to upper case, if possible.
** man: the value returned is that of the converted letter, or c if the
** conversion was not possible.
**
** 'if possible' is the whole contract: anything that is not a lower case
** letter must come back UNCHANGED. Returning 0, or returning c - 32 for
** every input, both break it.
**
** In ASCII 'a' is 97 and 'A' is 65, and the two blocks run in parallel,
** so the distance is always 32: 'a' - 'A' == 32. Subtracting 32 from a
** lower case letter therefore lands exactly on its upper case twin.
**
** The return type is int, like the parameter, because libc is specified
** that way. The value still fits in a char.
** =========================================================================
*/

int	ft_toupper(int c)
{
	// only a lower case letter is converted
	if (c >= 'a' && c <= 'z')
		// 32 is the constant distance between the two blocks, 'a' - 'A'
		return (c - 32);
	// everything else comes back untouched, that is the 'if possible' part
	return (c);
}
