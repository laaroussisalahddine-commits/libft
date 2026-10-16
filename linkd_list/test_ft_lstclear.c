#include "../level0/libft.h"
#include <stdio.h>
#include <stdlib.h>

static int g_del_count;

static void test_del(void *content)
{
    g_del_count++;
    free(content);
}

static void check(int num, int condition)
{
    if (condition)
        printf("Test %02d: PASS\n", num);
    else
        printf("Test %02d: FAIL\n", num);
}

static t_list *new_int_node(int value)
{
    t_list *node;
    int *content;

    content = malloc(sizeof(int));
    if (!content)
        exit(1);
    *content = value;
    node = ft_lstnew(content);
    if (!node)
    {
        free(content);
        exit(1);
    }
    return (node);
}

static t_list *make_list(int count)
{
    t_list *head;
    t_list *tail;
    t_list *node;
    int i;

    head = NULL;
    tail = NULL;
    i = 0;
    while (i < count)
    {
        node = new_int_node(i + 1);
        if (!head)
            head = node;
        else
            tail->next = node;
        tail = node;
        i++;
    }
    return (head);
}

int main(void)
{
    t_list *lst;
    int i;

    /* Test 01: Empty list */
    lst = NULL;
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    check(1, lst == NULL && g_del_count == 0);

    /* Test 02: One node */
    lst = new_int_node(10);
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    check(2, lst == NULL && g_del_count == 1);

    /* Test 03: Two nodes */
    lst = make_list(2);
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    check(3, lst == NULL && g_del_count == 2);

    /* Test 04: Three nodes */
    lst = make_list(3);
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    check(4, lst == NULL && g_del_count == 3);

    /* Test 05: Ten nodes */
    lst = make_list(10);
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    check(5, lst == NULL && g_del_count == 10);

    /* Test 06: Del called once per node */
    lst = make_list(5);
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    check(6, g_del_count == 5);

    /* Test 07: Pointer set to NULL after clearing */
    lst = make_list(4);
    ft_lstclear(&lst, test_del);
    check(7, lst == NULL);

    /* Test 08: Clearing an already empty list */
    lst = NULL;
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    check(8, lst == NULL && g_del_count == 0);

    /* Test 09: Content is NULL */
    lst = ft_lstnew(NULL);
    if (!lst)
        return (1);
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    check(9, lst == NULL && g_del_count == 1);

    /* Test 10: Three nodes with NULL content */
    lst = ft_lstnew(NULL);
    if (!lst)
        return (1);
    lst->next = ft_lstnew(NULL);
    if (!lst->next)
    {
        free(lst);
        return (1);
    }
    lst->next->next = ft_lstnew(NULL);
    if (!lst->next->next)
    {
        free(lst->next);
        free(lst);
        return (1);
    }
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    check(10, lst == NULL && g_del_count == 3);

    /* Test 11: Negative integer content */
    lst = new_int_node(-42);
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    check(11, lst == NULL && g_del_count == 1);

    /* Test 12: Zero integer content */
    lst = new_int_node(0);
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    check(12, lst == NULL && g_del_count == 1);

    /* Test 13: Large integer content */
    lst = new_int_node(2147483647);
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    check(13, lst == NULL && g_del_count == 1);

    /* Test 14: String content */
    lst = ft_lstnew(NULL);
    if (!lst)
        return (1);
    lst->content = malloc(6);
    if (!lst->content)
    {
        free(lst);
        return (1);
    }
    snprintf((char *)lst->content, 6, "hello");
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    check(14, lst == NULL && g_del_count == 1);

    /* Test 15: Repeated clearing of the same list pointer */
    lst = make_list(3);
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    ft_lstclear(&lst, test_del);
    check(15, lst == NULL && g_del_count == 3);

    /* Test 16: List of twenty nodes */
    lst = make_list(20);
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    check(16, lst == NULL && g_del_count == 20);

    /* Test 17: All nodes deleted from a longer list */
    lst = make_list(7);
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    check(17, lst == NULL && g_del_count == 7);

    /* Test 18: Clear one list, then another independent list */
    lst = make_list(2);
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    lst = make_list(3);
    ft_lstclear(&lst, test_del);
    check(18, lst == NULL && g_del_count == 5);

    /* Test 19: One node with NULL content */
    lst = ft_lstnew(NULL);
    if (!lst)
        return (1);
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    check(19, lst == NULL && g_del_count == 1);

    /* Test 20: Clear a list with twenty-five nodes */
    lst = make_list(25);
    g_del_count = 0;
    ft_lstclear(&lst, test_del);
    check(20, lst == NULL && g_del_count == 25);

    (void)i;
    return (0);
}
