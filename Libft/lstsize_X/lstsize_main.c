/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize_main.c                                    :+:      :+:    :+:   */
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

//subject prototype : THIS version returns an unsigned int, check your subject
unsigned int	ft_lstsize(t_list *lst);

int main(void)
{
//subject: counts the number of nodes in the list
//an empty list is a NULL pointer, not a node holding nothing
//the nodes below live on the stack on purpose : this test needs no malloc
t_list	a;
t_list	b;
t_list	c;

a.content = "a";
a.next = &b;
b.content = "b";
b.next = &c;
c.content = "c";
c.next = NULL;

	//empty list
	printf("%s\n", "Empty List Case, ft_lstsize(NULL):");
	printf("%s\n", "expected : 0");
	printf("actual   : %u\n", ft_lstsize(NULL));
	printf("%s\n"," ");

	//one node
	printf("%s\n", "One Node Case, ft_lstsize(&c):");
	printf("%s\n", "expected : 1");
	printf("actual   : %u\n", ft_lstsize(&c));
	printf("%s\n"," ");

	//two nodes
	printf("%s\n", "Two Nodes Case, ft_lstsize(&b):");
	printf("%s\n", "expected : 2");
	printf("actual   : %u\n", ft_lstsize(&b));
	printf("%s\n"," ");

	//three nodes
	printf("%s\n", "Three Nodes Case, ft_lstsize(&a):");
	printf("%s\n", "expected : 3");
	printf("actual   : %u\n", ft_lstsize(&a));
	printf("%s\n"," ");

	//the list must not be modified by counting it
	printf("%s\n", "Untouched Case, a.next == &b after counting:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", a.next == &b);
	printf("%s\n"," ");

}
