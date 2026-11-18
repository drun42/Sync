/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_isdigit : is this byte a decimal digit ?
**
** man: isdigit() checks for a digit (0 through 9).
**
** SUBJECT: the return value must be exactly 1 or exactly 0.
**
** The test is on the CHARACTER '0' to '9', not on the numbers 0 to 9.
** The character '0' is the byte 48, so c == 0 is the terminating '\0' and
** is not a digit. Mixing '0' and 0 is the classic mistake here.
**
** The ten digits are contiguous in ASCII, so one range check is enough.
** =========================================================================
*/

int	ft_isdigit(int c)
{
	// '0' is the byte 48 and '9' is the byte 57, the ten digits are in a row
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
