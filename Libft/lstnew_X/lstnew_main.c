/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew_main.c                                     :+:      :+:    :+:   */
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

//subject prototype : takes the content, returns the new node
t_list	*ft_lstnew(void *content);

int main(void)
{
//subject: allocates with malloc and returns a new node
//subject: content is initialized with the given parameter
//subject: next is initialized to NULL
//the content is NOT copied : only the pointer is stored
//run it under valgrind : valgrind --leak-check=full ./a.out
char	*c;
t_list	*n;
t_list	*m;

c = "hello";

	//base case : the node exists
	printf("%s\n", "Base Case, ft_lstnew(\"hello\") != NULL:");
	n = ft_lstnew(c);
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", n != NULL);
	printf("%s\n"," ");

	//the content pointer is stored as it is, not copied
	printf("%s\n", "Content Case, n->content == c:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", n->content == c);
	printf("%s\n", "Content Case, the string behind it:");
	printf("expected : [hello]\n");
	printf("actual   : [%s]\n", (char *)n->content);
	printf("%s\n"," ");

	//next must start at NULL, not at whatever malloc left there
	printf("%s\n", "Next Case, n->next == NULL:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", n->next == NULL);
	printf("%s\n"," ");

	//NULL content is allowed : the node must still be created
	printf("%s\n", "NULL Content Case, ft_lstnew(NULL) != NULL:");
	m = ft_lstnew(NULL);
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", m != NULL);
	printf("%s\n", "NULL Content Case, m->content == NULL:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", m->content == NULL);
	printf("%s\n"," ");

	//two calls must give two different nodes
	printf("%s\n", "Unique Case, n != m:");
	printf("%s\n", "expected : 1");
	printf("actual   : %d\n", n != m);
	free(n);
	free(m);
	printf("%s\n", "both nodes freed");
	printf("%s\n"," ");

}
