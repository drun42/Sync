/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back_main.c                                :+:      :+:    :+:   */
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
void	ft_lstadd_back(t_list **lst, t_list *new);

int main(void)
{
//subject: adds the node new at the END of the list
//lst is a t_list ** because on an EMPTY list the head pointer itself changes
//that empty case is the one that is usually forgotten
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
	ft_lstadd_back(&head, &a);
	printf("%s\n", "expected : [a]");
	list_print("actual  ", head);
	printf("%s\n", "Empty List Case, head == &a:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", head == &a);
	printf("%s\n"," ");

	//one element : the new node goes behind it
	printf("%s\n", "One Element Case, add b at the back:");
	ft_lstadd_back(&head, &b);
	printf("%s\n", "expected : [a][b]");
	list_print("actual  ", head);
	printf("%s\n", "One Element Case, a.next == &b:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", a.next == &b);
	printf("%s\n"," ");

	//adding at the back keeps the insertion order
	printf("%s\n", "Third Add Case, add c at the back:");
	ft_lstadd_back(&head, &c);
	printf("%s\n", "expected : [a][b][c]");
	list_print("actual  ", head);
	printf("%s\n"," ");

	//the head must NOT have moved
	printf("%s\n", "Head Case, head == &a:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", head == &a);
	printf("%s\n", "Tail Case, c.next == NULL:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", c.next == NULL);
	printf("%s\n"," ");

}
