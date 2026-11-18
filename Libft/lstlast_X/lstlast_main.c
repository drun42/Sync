/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast_main.c                                    :+:      :+:    :+:   */
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

//subject prototype : returns the last node, not its content
t_list	*ft_lstlast(t_list *lst);

int main(void)
{
//subject: returns the LAST node of the list
//the last node is the one whose next is NULL
//an empty list has no last node : the answer is NULL
//the nodes below live on the stack on purpose : this test needs no malloc
t_list	a;
t_list	b;
t_list	c;
t_list	*r;

a.content = "a";
a.next = &b;
b.content = "b";
b.next = &c;
c.content = "c";
c.next = NULL;


void show(char *label, t_list *n)
{
	if (n == NULL)
		printf("%s : NULL\n", label);
	else
		printf("%s : [%s]\n", label, (char *)n->content);
}


	//empty list : NULL, and no dereference of it
	printf("%s\n", "Empty List Case, ft_lstlast(NULL):");
	printf("%s\n", "expected : NULL");
	show("actual  ", ft_lstlast(NULL));
	printf("%s\n"," ");

	//three nodes : the third one
	printf("%s\n", "Three Nodes Case, ft_lstlast(&a):");
	printf("%s\n", "expected : [c]");
	r = ft_lstlast(&a);
	show("actual  ", r);
	printf("%s\n", "Three Nodes Case, result == &c:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", r == &c);
	printf("%s\n"," ");

	//a single node is its own last node
	printf("%s\n", "One Node Case, ft_lstlast(&c) == &c:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", ft_lstlast(&c) == &c);
	printf("%s\n"," ");

	//the returned node really ends the list
	printf("%s\n", "Tail Case, result->next == NULL:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", ft_lstlast(&a)->next == NULL);
	printf("%s\n"," ");

}
