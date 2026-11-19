/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_atoi : read an int out of the front of a string.
**
** man: the atoi() function converts the initial portion of the string
** pointed to by nptr to int.
** man: the behaviour is the same as strtol(nptr, NULL, 10) except that
** atoi() does not detect errors.
**
** So the grammar is the one of strtol: optional whitespace, then ONE
** optional sign, then decimal digits, and the conversion stops at the
** first character that does not fit. Nothing is an error: a string with
** no digits at all simply gives 0.
**
** Three places where versions usually differ from libc:
**
** 1. The whitespace set is the one of isspace, six characters: space plus
** '\t' '\n' '\v' '\f' '\r'. Those five are the values 9 to 13, in a row
** in the ASCII table, so '>= \t && <= \r' covers them. Skipping only
** space, '\t' and '\n' fails on the other three.
**
** 2. There is ONE sign at most. It is an if, not a while. '--5' and '+-5'
** are not numbers: the conversion stops on the second sign and the answer
** is 0. A loop over the signs would read '--5' as 5.
**
** 3. Whitespace is allowed only BEFORE the sign. '- 42' is 0, because
** after the '-' a space is not a digit, so the digit loop reads nothing.
**
** The accumulator n is a long and not an int. INT_MIN is -2147483648, and
** its digits build the positive value 2147483648, which does NOT fit in
** an int. Building it in a long and applying the sign afterwards keeps
** both limits exact. Input that does not fit in an int at all is
** undefined behaviour for atoi, so it is not handled here.
**
** The digits are turned into a value with n * 10 + (c - '0'). Subtracting
** '0' works because the ten digits are contiguous in ASCII: '7' - '0'
** is 7.
** =========================================================================
*/

#include <string.h>

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	// long, so the digits of INT_MIN can be built before the sign is applied
	long	n;

	i = 0;
	sign = 1;
	n = 0;
	// the full isspace set: ' ' plus the values 9 to 13, '\t' to '\r'
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
	{
		i++;
	}
	// an if and not a while: at most ONE sign is accepted
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	// stops at the first byte that is not a digit, that is 'initial portion'
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		// '0' is 48 and the digits are contiguous, so c - '0' is its value
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	// apply the sign in long, then cut down to int
	return ((int)(sign * n));
}
