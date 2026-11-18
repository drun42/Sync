/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_strlen : how many bytes are there before the terminating '\0' ?
**
** man: strlen() calculates the length of the string pointed to by s,
** excluding the terminating null byte ('\0').
**
** The return type is size_t and not int. size_t is unsigned and is the
** type the whole string part of libc uses for sizes, so a length can
** never be negative. Returning an int would also mean converting it back
** at every call site.
**
** The parameter carries const because the string is only read. That is
** part of the man prototype and lets the caller pass a const char *.
**
** A string in C is not an object that knows its own size: it is a run of
** bytes that ENDS at the first '\0'. So the length can only be found by
** walking until that byte, which is what the loop does. The '\0' itself
** is not counted, because the loop stops ON it without adding 1.
**
** s[i] is the byte at offset i. As a condition it is read as 'is this
** byte different from 0', because in C any non zero value is true.
** =========================================================================
*/

#include <string.h>

size_t	ft_strlen(const char *s)
{
	// i is both the walking index and, at the end, the answer
	size_t	i;

	i = 0;
	// stops on the first '\0', which is false as a condition
	while (s[i])
	{
		i++;
	}
	// i now holds the number of bytes seen BEFORE the '\0'
	return (i);
}
