#include "libft.h"
#include <stdio.h>

int main(void)
{
    t_list *a;
    t_list *b;
    t_list *c;
    t_list *last;

    a = ft_lstnew("A");
    b = ft_lstnew("B");
    c = ft_lstnew("C");
    last = ft_lstnew("X");

    a->next = b;
    b->next = c;

    ft_lstadd_back(&a, last);

    while (a != NULL)
    {
        printf("%s -> ", (char *)a->content);
        a = a->next;
    }
    printf("NULL\n");

    return (0);
}