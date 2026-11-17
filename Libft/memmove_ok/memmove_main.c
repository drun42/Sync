/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:37:30 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//man prototype
void	*ft_memmove(void *dest, const void *src, size_t n);

int main(void)
{
//man: copies n bytes from src to dest, the areas MAY OVERLAP, returns dest
//expected is produced by the libc function on a reference buffer
size_t	n;
char	src [10];
char	dest [10];
char	refd [10];
char	buf [11];
char	refb [11];
void	*ret;
void	*rref;
char	*z;

n = 5;


void clear(void)
{
	memset(src, 7, 10);
	memset(dest, 0, 10);
	memset(refd, 0, 10);
}


void bytes_print(char *b)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d", b[i]);
	}
	printf("%s\n", "");
}


void compare_dest(void)
{
	printf("%s", "expected : ");
	bytes_print(refd);
	printf("%s", "actual   : ");
	bytes_print(dest);
}


void bufs_reset(void)
{
	memcpy(buf, "0123456789", 11);
	memcpy(refb, "0123456789", 11);
}


void compare_buf(void)
{
	printf("expected : %s\n", refb);
	printf("actual   : %s\n", buf);
}


	//memory state
	clear();
	printf("%s\n", "Memory state (src = 7, dest = 0):");
	printf("src      : ");
	bytes_print(src);
	compare_dest();
	printf("%s\n"," ");

	//base case, no overlap
	printf("%s\n", "Base Case (no overlap), memmove(dest, src, 5):");
	memmove(refd, src, n);
	ft_memmove(dest, src, n);
	compare_dest();
	printf("%s\n"," ");

	//n = 0 : dest must stay untouched
	clear();
	printf("%s\n", "n = 0 Case:");
	memmove(refd, src, 0);
	ft_memmove(dest, src, 0);
	compare_dest();
	printf("%s\n"," ");

	//return value is dest
	clear();
	printf("%s\n", "Return Value Case, ret == dest:");
	ret = ft_memmove(dest, src, n);
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", ret == (void *)dest);
	printf("%s\n"," ");

	//both calls run on the SAME buffer, so both must hand back that buffer
	clear();
	printf("%s\n", "Return Value Case, libc and ft return the same pointer:");
	rref = memmove(dest, src, n);
	ret = ft_memmove(dest, src, n);
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", ret == rref && ret == (void *)dest);
	printf("%s\n"," ");

	//n = 0 with an UNREADABLE src : z - 1 points one byte before a string
	//literal, so reading even a single byte from it is out of bounds
	//only a function that never touches src when n is 0 survives this, and
	//it must still return dest
	z = "";
	printf("%s\n", "n = 0 Case, invalid src, ft_memmove(z, z - 1, 0):");
	rref = memmove(z, z - 1, 0);
	ret = ft_memmove(z, z - 1, 0);
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", ret == rref && ret == (void *)z);
	printf("%s\n"," ");

	//n = 0 must not write into dest either, whatever src is
	clear();
	printf("%s\n", "n = 0 Case, dest untouched with an invalid src:");
	ft_memmove(dest, z - 1, 0);
	compare_dest();
	printf("%s\n"," ");

	//bytes, not a string : a '\0' inside src does not stop the copy
	clear();
	src[2] = 0;
	printf("%s\n", "Byte iteration check (copies past '\\0'):");
	memmove(refd, src, n);
	ft_memmove(dest, src, n);
	compare_dest();
	printf("%s\n"," ");

	//overlap, dest after src : a plain forward copy destroys src
	bufs_reset();
	printf("%s\n", "Overlap Case, dest > src, memmove(buf + 3, buf, 5):");
	memmove(refb + 3, refb, n);
	ft_memmove(buf + 3, buf, n);
	compare_buf();
	printf("%s\n"," ");

	//overlap, dest before src
	bufs_reset();
	printf("%s\n", "Overlap Case, dest < src, memmove(buf, buf + 3, 5):");
	memmove(refb, refb + 3, n);
	ft_memmove(buf, buf + 3, n);
	compare_buf();
	printf("%s\n"," ");

	//dest and src are the same address
	bufs_reset();
	printf("%s\n", "Overlap Case, dest == src:");
	memmove(refb, refb, n);
	ft_memmove(buf, buf, n);
	compare_buf();
	printf("%s\n"," ");

}
