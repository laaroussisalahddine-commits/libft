#include "libft.h"

int main (void)
{
	t_list *lst;
	int number = 10;

	lst = lstnew(&number);
	while(lst != NULL)
	{
		printf("content : %d\n",*(int *)lst -> content );
		lst = lst -> next;
	}
	free(lst);
	return(0);
}
