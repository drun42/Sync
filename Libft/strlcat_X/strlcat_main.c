/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//man prototype : returns size_t, size is the FULL size of the dst buffer
size_t	ft_strlcat(char *dst, const char *src, size_t size);

int main(void)
{
//man: appends src to dst, writing at most size - 1 bytes in total
//man: the result is always terminated with '\0' if there was any room
//man: RETURNS the total length it TRIED to create : strlen(dst) + strlen(src)
//man: a return value >= size means the append was truncated
//watch the case where size is SMALLER than the current strlen(dst)
//expected is produced by libc strlcat on a reference buffer
char	dst [16];
char	ref [16];


void prep(void)
{
	memset(dst, 'X', 15);
	memset(ref, 'X', 15);
	dst[15] = '\0';
	ref[15] = '\0';
	memcpy(dst, "abc", 4);
	memcpy(ref, "abc", 4);
}


void both(char *s, size_t size)
{
	size_t	r;

	prep();
	r = strlcat(ref, s, size);
	printf("expected : ret %zu  dst [%s]\n", r, ref);
	r = ft_strlcat(dst, s, size);
	printf("actual   : ret %zu  dst [%s]\n", r, dst);
}


	//plenty of room : "abc" + "de"
	printf("%s\n", "Base Case, strlcat(\"abc\", \"de\", 16):");
	both("de", 16);
	printf("%s\n"," ");

	//exact fit : 5 characters plus the terminator
	printf("%s\n", "Exact Fit Case, size = 6:");
	both("de", 6);
	printf("%s\n"," ");

	//truncation : only one character of src fits
	printf("%s\n", "Truncation Case, size = 5:");
	both("de", 5);
	printf("%s\n"," ");

	//size equals strlen(dst) : no room for anything, return is still the total
	printf("%s\n", "Size == strlen(dst) Case, size = 3:");
	both("de", 3);
	printf("%s\n"," ");

	//size SMALLER than strlen(dst) : dst is not even scanned to its end
	printf("%s\n", "Size < strlen(dst) Case, size = 2:");
	both("de", 2);
	printf("%s\n"," ");

	//size = 0 : nothing is written at all
	printf("%s\n", "Size 0 Case:");
	both("de", 0);
	printf("%s\n"," ");

	//empty src : dst is unchanged, return is strlen(dst)
	printf("%s\n", "Empty Src Case, strlcat(\"abc\", \"\", 16):");
	both("", 16);
	printf("%s\n"," ");

}
