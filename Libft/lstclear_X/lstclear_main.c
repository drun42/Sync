/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshofer <dshofer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 00:00:00 by dshofer           #+#    #+#             */
/*   Updated: 2026/11/15 00:00:00 by dshofer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//the struct comes from the subject, it must match the one in your libft.h
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//subject prototype : lst is the ADDRESS of the pointer to the first node
void	ft_lstclear(t_list **lst, void (*del)(void *));

//counts how many times del was called, and frees the content
int	del_count = 0;

void	del(void *content)
{
	del_count++;
	free(content);
}

int main(void)
{
//subject: deletes and frees the given node AND all its successors,
//subject: using del on every content, then free on every node
//subject: finally the pointer to the list is set to NULL
//that last part is why lst is a t_list ** and not a t_list *
//run it under valgrind : valgrind --leak-check=full ./a.out
t_list	*head;
t_list	*n;
int	*c;
int	i;

head = NULL;
i = 0;
while (i < 3)
{
	c = malloc(sizeof(int));
	*c = i;
	n = malloc(sizeof(t_list));
	n->content = c;
	n->next = head;
	head = n;
	i++;
}

	//three nodes : del is called three times
	printf("%s\n", "Base Case, ft_lstclear on 3 nodes, number of del calls:");
	ft_lstclear(&head, del);
	printf("%s\n", "expected : 3");
	printf("actual   : %d\n", del_count);
	printf("%s\n"," ");

	//the head pointer itself must be set to NULL
	printf("%s\n", "Head Case, head == NULL after the call:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", head == NULL);
	printf("%s\n"," ");

	//an already empty list : nothing happens, nothing crashes
	printf("%s\n", "Empty List Case, ft_lstclear on NULL, del calls:");
	ft_lstclear(&head, del);
	printf("%s\n", "expected : 3");
	printf("actual   : %d\n", del_count);
	printf("%s\n", "Empty List Case, head still NULL:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", head == NULL);
	printf("%s\n"," ");

}
