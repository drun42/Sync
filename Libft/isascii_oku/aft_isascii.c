/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_isascii : does this value fit in the 7-bit ASCII set ?
**
** man: isascii() checks whether c is a 7-bit unsigned char value that fits
** into the ASCII character set.
**
** SUBJECT: the return value must be exactly 1 or exactly 0.
**
** This one is not a character class like the others: it asks whether the
** VALUE is in the range 0 to 127. That is why the lower bound 0 matters
** and must be written: the parameter is a signed int, so a negative value
** can arrive and is not ASCII.
**
** 127 is the last 7-bit value (0111 1111). 128 and above need an eighth
** bit, so they are out, even though they are perfectly valid bytes.
** The terminating '\0' is value 0, so it IS ascii, and the answer is 1.
** =========================================================================
*/

int	ft_isascii(int c)
{
	// 0 to 127 is everything that fits in seven bits
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
