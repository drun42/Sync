/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_isalpha : is this byte a letter ?
**
** man: isalpha() checks for an alphabetic character.
**
** SUBJECT: the return value must be exactly 1 when c belongs to the class
** and exactly 0 when it does not. libc is only required to return 'non
** zero', which is why a libc result cannot simply be forwarded.
**
** The parameter is an int and not a char because libc is specified that
** way: the caller passes the value of an unsigned char, or EOF.
**
** In ASCII the letters sit in two contiguous blocks, 'a' to 'z' and 'A' to
** 'Z', so two range checks answer the question. No lookup table is needed.
** Writing 'a' instead of 97 costs nothing and says what is meant.
**
** Everything else is not a letter: digits, space, punctuation, the control
** bytes below 32, and every byte above 126.
** =========================================================================
*/

int	ft_isalpha(int c)
{
	// the two letter blocks of the ASCII table, lower case and upper case
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	// reached only when no range matched, so c is not a letter
	return (0);
}
