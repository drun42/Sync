/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//the struct comes from the subject, it must match the one in your libft.h
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//subject prototype : f is applied to the CONTENT of each node
void	ft_lstiter(t_list *lst, void (*f)(void *));

//modifies the content in place, through the void pointer
void	add_one(void *content)
{
	*(int *)content += 1;
}

//records the order in which the nodes were visited
char	order [8];
int	oi = 0;

void	record(void *content)
{
	order[oi] = *(char *)content;
	oi++;
	order[oi] = '\0';
}

int main(void)
{
//subject: iterates over the list and applies f to the content of each node
//subject: nothing is returned and nothing is allocated
//f receives the content, so it can modify it in place
//the nodes below live on the stack on purpose : this test needs no malloc
int	v1;
int	v2;
int	v3;
char	k1;
char	k2;
char	k3;
t_list	a;
t_list	b;
t_list	c;

v1 = 1;
v2 = 2;
v3 = 3;
a.content = &v1;
a.next = &b;
b.content = &v2;
b.next = &c;
c.content = &v3;
c.next = NULL;

	//every content must be modified in place
	printf("%s\n", "Base Case, ft_lstiter(&a, add_one):");
	ft_lstiter(&a, add_one);
	printf("%s\n", "expected : 2 3 4");
	printf("actual   : %d %d %d\n", v1, v2, v3);
	printf("%s\n"," ");

	//running it twice applies f twice
	printf("%s\n", "Twice Case, ft_lstiter(&a, add_one) again:");
	ft_lstiter(&a, add_one);
	printf("%s\n", "expected : 3 4 5");
	printf("actual   : %d %d %d\n", v1, v2, v3);
	printf("%s\n"," ");

	//the visiting order must be first node to last node
	k1 = 'a';
	k2 = 'b';
	k3 = 'c';
	a.content = &k1;
	b.content = &k2;
	c.content = &k3;
	printf("%s\n", "Order Case, ft_lstiter(&a, record):");
	order[0] = '\0';
	ft_lstiter(&a, record);
	printf("%s\n", "expected : [abc]");
	printf("actual   : [%s]\n", order);
	printf("%s\n"," ");

	//empty list : f is never called, nothing crashes
	printf("%s\n", "Empty List Case, ft_lstiter(NULL, record), order:");
	oi = 0;
	order[0] = '\0';
	ft_lstiter(NULL, record);
	printf("%s\n", "expected : []");
	printf("actual   : [%s]\n", order);
	printf("%s\n"," ");

	//the links must not be touched
	printf("%s\n", "Untouched Case, a.next == &b:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", a.next == &b);
	printf("%s\n"," ");

}
