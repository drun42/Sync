/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_strdup : make a private copy of a string.
**
** man: the strdup() function returns a pointer to a new string which is a
** duplicate of the string s. Memory for the new string is obtained with
** malloc(3), and can be freed with free(3).
** man: it returns NULL if insufficient memory was available.
**
** The caller becomes the owner of the result and has to free it. That is
** the contract, and it is why this function belongs to the malloc group
** of the subject.
**
** The size to ask for is len + 1: len bytes of text plus one for the
** terminating '\0'. Asking for len is the classic off by one, and the
** write of the terminator then lands one byte outside the block.
**
** malloc can fail, and then NULL is returned without touching anything.
**
** The copy stops at the '\0' of the source, like every string function:
** bytes that sit behind it are not part of the string and are not copied.
** The terminator is written by hand after the loop, because the loop ends
** ON it without copying it.
**
** The result is a NEW block: writing into the copy must not change the
** original. That is what makes it different from returning s itself.
** =========================================================================
*/

#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	len;
	size_t	i;

	// length of the source, the '\0' is not counted
	len = 0;
	while (s[len])
	{
		len++;
	}
	// len + 1: the text plus room for the terminator
	p = (char *)malloc(len + 1);
	// allocation failed, man says return NULL
	if (p == NULL)
		return (NULL);
	i = 0;
	// copy the text only, the loop stops before the '\0'
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	// terminate the copy by hand, the loop did not copy the '\0'
	p[len] = '\0';
	return (p);
}
