/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front_main.c                               :+:      :+:    :+:   */
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

//subject prototype : lst is the ADDRESS of the pointer to the first node
void	ft_lstadd_front(t_list **lst, t_list *new);

int main(void)
{
//subject: adds the node new at the BEGINNING of the list
//lst is a t_list ** because the pointer to the first node itself changes
//nothing is allocated here, the nodes already exist
//the nodes below live on the stack on purpose : this test needs no malloc
t_list	a;
t_list	b;
t_list	c;
t_list	*head;

a.content = "a";
a.next = NULL;
b.content = "b";
b.next = NULL;
c.content = "c";
c.next = NULL;


void list_print(char *label, t_list *l)
{
	printf("%s : ", label);
	while (l)
	{
		printf("[%s]", (char *)l->content);
		l = l->next;
	}
	printf("\n");
}


	//empty list : the new node becomes the head
	printf("%s\n", "Empty List Case, add a to an empty list:");
	head = NULL;
	ft_lstadd_front(&head, &a);
	printf("%s\n", "expected : [a]");
	list_print("actual  ", head);
	printf("%s\n", "Empty List Case, head == &a:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", head == &a);
	printf("%s\n"," ");

	//one element : the new node goes in front, the old head follows
	printf("%s\n", "One Element Case, add b in front of a:");
	ft_lstadd_front(&head, &b);
	printf("%s\n", "expected : [b][a]");
	list_print("actual  ", head);
	printf("%s\n", "One Element Case, b->next == &a:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", b.next == &a);
	printf("%s\n"," ");

	//adding in front repeatedly reverses the insertion order
	printf("%s\n", "Third Add Case, add c in front:");
	ft_lstadd_front(&head, &c);
	printf("%s\n", "expected : [c][b][a]");
	list_print("actual  ", head);
	printf("%s\n"," ");

	//the last node must still end the list
	printf("%s\n", "Tail Case, a.next == NULL:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", a.next == NULL);
	printf("%s\n"," ");

}
