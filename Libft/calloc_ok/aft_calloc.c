/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aft_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/17 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** =========================================================================
** ft_calloc : malloc, but the memory comes back zeroed.
**
** man: the calloc() function allocates memory for an array of nmemb
** elements of size bytes each and returns a pointer to the allocated
** memory. The memory is set to ZERO.
** man: if nmemb or size is 0, then calloc() returns either NULL, or a
** unique pointer value that can later be successfully passed to free().
**
** SUBJECT: that choice is removed, the subject requires the second
** behaviour: with nmemb or size at 0 the result must be a unique pointer
** that free() accepts, so returning NULL is wrong.
**
** Nothing special has to be written for that case: malloc(0) already
** returns such a pointer, both in glibc and on a mac. The product is 0,
** the zeroing loop does not run, and the pointer is handed back as it is.
**
** Two arguments instead of one is the whole interface difference with
** malloc: the total is nmemb * size bytes.
**
** malloc can fail, and then it returns NULL. That has to be tested BEFORE
** the zeroing loop, otherwise the loop writes through a NULL pointer and
** the program dies.
**
** The zeroing is done through a char * view, because the area is counted
** in bytes and void * cannot be indexed. 0 and '\0' are the same value
** here, the byte 0.
**
** Note that nmemb * size can overflow for huge arguments; man says NULL
** in that case. The subject does not ask for it, so it is left out.
** =========================================================================
*/

#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	char	*c;
	size_t	i;

	// one block of nmemb * size bytes, 0 bytes is a valid request
	p = malloc(nmemb * size);
	// test the failure FIRST, before anything is written
	if (p == NULL)
		return (NULL);
	// byte sized view of the block, void * cannot be indexed
	c = (char *)p;
	i = 0;
	// zero every byte, this is what calloc adds to malloc
	while (i < nmemb * size)
	{
		c[i] = 0;
		i++;
	}
	// the pointer the caller will later pass to free
	return (p);
}
