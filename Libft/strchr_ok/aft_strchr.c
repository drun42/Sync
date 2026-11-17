/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_strchr : address of the FIRST c inside s, or NULL.
**
** man: the strchr() function returns a pointer to the first occurrence of
** the character c in the string s.
** man: the terminating null byte is considered part of the string, so if c
** is '\0' the function locates the terminator.
** man: returns NULL if the character is not found.
**
** Two details carry every test of this function.
**
** First, c arrives as an int but must be compared as a CHAR. The caller
** may pass any int, and libc is specified to convert it to char. So
** 'o' + 256 has to behave exactly like 'o': both have the same low byte.
** Casting c to char throws the higher bits away and gets that for free.
** Comparing s[i] == c without the cast makes 'o' + 256 miss.
**
** Second, the terminator is part of the string. The walking loop stops ON
** the '\0' without testing it, so that case is handled after the loop:
** if c was '\0', the address of that terminator is the answer.
**
** The return type is char * while the parameter is const char *. That is
** the man prototype, and it is why the cast on the way out is needed: the
** function hands back a writable pointer into a string it promised only to
** read. The cast is on the return value, NOT on the parameter type.
**
** (char *)s + i is the address of byte i: the start of the string plus an
** offset of i bytes, because a char is one byte wide.
** =========================================================================
*/

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	// walk until the terminator, which this condition treats as false
	while (s[i])
	{
		// the cast to char is what makes 'o' + 256 match 'o'
		if (s[i] == (char)c)
			// address of byte i, not the byte itself
			return ((char *)s + i);
		i++;
	}
	// the loop ended on the '\0', which man counts as part of the string
	if ((char)c == '\0')
		return ((char *)s + i);
	// c is not in s at all
	return (NULL);
}
