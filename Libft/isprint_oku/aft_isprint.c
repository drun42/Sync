/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_isprint : is this byte printable ?
**
** man: isprint() checks for any printable character including space.
**
** SUBJECT: the return value must be exactly 1 or exactly 0.
**
** The printable ASCII characters are one single block, from the space
** (32) to the tilde (126). Everything below 32 is a control character,
** '\n' and '\t' among them, so they are NOT printable even though they
** clearly do something on screen.
**
** 127 is DEL, a control character, so the upper bound is 126 and not 127.
** That off by one is what the tests look for.
** =========================================================================
*/

int	ft_isprint(int c)
{
	// 32 is ' ' and 126 is '~', 127 is DEL and is not printable
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
