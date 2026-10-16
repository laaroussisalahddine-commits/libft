#include "../level0/libft.h"

static int g_call_count;
static int g_sum;

static void add_int(void *content)
{
    if (content)
    {
        g_sum += *(int *)content;
        g_call_count++;
    }
    else
        g_call_count++;
}

static void increment_int(void *content)
{
    if (content)
        (*(int *)content)++;
}

static void set_to_zero(void *content)
{
    if (content)
        *(int *)content = 0;
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

static void free_list(t_list *lst)
{
    t_list *next;

    while (lst)
    {
        next = lst->next;
        free(lst->content);
        free(lst);
        lst = next;
    }
}

int main(void)
{
    t_list *lst;
    t_list *second;
    t_list *third;
    int *value;

    /* Test 01: Empty list does not call f */
    lst = NULL;
    g_call_count = 0;
    ft_lstiter(lst, add_int);
    check(1, g_call_count == 0);

    /* Test 02: One node calls f once */
    lst = new_int_node(10);
    g_call_count = 0;
    g_sum = 0;
    ft_lstiter(lst, add_int);
    check(2, g_call_count == 1 && g_sum == 10);
    free_list(lst);

    /* Test 03: Three nodes call f three times */
    lst = make_list(3);
    g_call_count = 0;
    g_sum = 0;
    ft_lstiter(lst, add_int);
    check(3, g_call_count == 3 && g_sum == 6);
    free_list(lst);

    /* Test 04: Five nodes call f five times */
    lst = make_list(5);
    g_call_count = 0;
    g_sum = 0;
    ft_lstiter(lst, add_int);
    check(4, g_call_count == 5 && g_sum == 15);
    free_list(lst);

    /* Test 05: Callback changes the first node */
    lst = new_int_node(41);
    ft_lstiter(lst, increment_int);
    check(5, *(int *)lst->content == 42);
    free_list(lst);

    /* Test 06: Callback changes every node */
    lst = make_list(3);
    ft_lstiter(lst, increment_int);
    check(6, *(int *)lst->content == 2
        && *(int *)lst->next->content == 3
        && *(int *)lst->next->next->content == 4);
    free_list(lst);

    /* Test 07: Callback sets each value to zero */
    lst = make_list(4);
    ft_lstiter(lst, set_to_zero);
    check(7, *(int *)lst->content == 0
        && *(int *)lst->next->content == 0
        && *(int *)lst->next->next->content == 0
        && *(int *)lst->next->next->next->content == 0);
    free_list(lst);

    /* Test 08: NULL content is passed safely to this callback */
    lst = ft_lstnew(NULL);
    if (!lst)
        return (1);
    g_call_count = 0;
    ft_lstiter(lst, add_int);
    check(8, g_call_count == 1);
    free(lst);

    /* Test 09: Three nodes with NULL content */
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
    g_call_count = 0;
    ft_lstiter(lst, add_int);
    check(9, g_call_count == 3);
    free_list(lst);

    /* Test 10: Sum negative, zero and positive values */
    lst = new_int_node(-5);
    lst->next = new_int_node(0);
    lst->next->next = new_int_node(8);
    g_call_count = 0;
    g_sum = 0;
    ft_lstiter(lst, add_int);
    check(10, g_call_count == 3 && g_sum == 3);
    free_list(lst);

    /* Test 11: Original values remain unchanged with read-only callback */
    lst = new_int_node(7);
    second = new_int_node(8);
    lst->next = second;
    g_call_count = 0;
    g_sum = 0;
    ft_lstiter(lst, add_int);
    check(11, *(int *)lst->content == 7
        && *(int *)second->content == 8);
    free_list(lst);

    /* Test 12: Large list visits every node */
    lst = make_list(50);
    g_call_count = 0;
    g_sum = 0;
    ft_lstiter(lst, add_int);
    check(12, g_call_count == 50 && g_sum == 1275);
    free_list(lst);

    /* Test 13: Callback applies to the last node too */
    lst = new_int_node(1);
    second = new_int_node(2);
    third = new_int_node(99);
    lst->next = second;
    second->next = third;
    ft_lstiter(lst, increment_int);
    check(13, *(int *)third->content == 100);
    free_list(lst);

    /* Test 14: Repeated iteration applies callback each time */
    lst = new_int_node(1);
    ft_lstiter(lst, increment_int);
    ft_lstiter(lst, increment_int);
    check(14, *(int *)lst->content == 3);
    free_list(lst);

    /* Test 15: Empty list with a valid callback */
    lst = NULL;
    g_call_count = 0;
    ft_lstiter(lst, add_int);
    check(15, g_call_count == 0);

    /* Test 16: One-node list with negative value */
    lst = new_int_node(-100);
    g_call_count = 0;
    g_sum = 0;
    ft_lstiter(lst, add_int);
    check(16, g_call_count == 1 && g_sum == -100);
    free_list(lst);

    /* Test 17: One-node list with zero value */
    lst = new_int_node(0);
    g_call_count = 0;
    g_sum = 0;
    ft_lstiter(lst, add_int);
    check(17, g_call_count == 1 && g_sum == 0);
    free_list(lst);

    /* Test 18: Callback called once for each of seven nodes */
    lst = make_list(7);
    g_call_count = 0;
    ft_lstiter(lst, add_int);
    check(18, g_call_count == 7);
    free_list(lst);

    /* Test 19: Values are incremented independently */
    lst = new_int_node(10);
    second = new_int_node(20);
    lst->next = second;
    ft_lstiter(lst, increment_int);
    check(19, *(int *)lst->content == 11
        && *(int *)second->content == 21);
    free_list(lst);

    /* Test 20: All nodes are visited in order (weighted sum) */
    lst = new_int_node(1);
    second = new_int_node(2);
    third = new_int_node(3);
    lst->next = second;
    second->next = third;
    g_call_count = 0;
    g_sum = 0;
    ft_lstiter(lst, add_int);
    value = third->content;
    check(20, g_call_count == 3 && g_sum == 6 && *value == 3);
    free_list(lst);

    return (0);
}
