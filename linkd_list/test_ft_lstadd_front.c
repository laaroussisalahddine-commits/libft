#include "../level0/libft.h"

static int	list_size(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

static void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d", *(int *)lst->content);
		if (lst->next)
			printf(" -> ");
		lst = lst->next;
	}
	printf(" -> NULL\n");
}

static void	free_list(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

static t_list	*make_node(int *value)
{
	return (ft_lstnew(value));
}

int	main(void)
{
	t_list	*lst;
	t_list	*node;
	int		a;
	int		b;
	int		c;

	a = 10;
	b = 20;
	c = 30;

	/* Test 01: Add to empty list */
	printf("\nTEST 01: Empty list\n");
	lst = NULL;
	node = make_node(&a);
	ft_lstadd_front(&lst, node);
	printf("Expected: 10 -> NULL\n");
	printf("Got:      ");
	print_list(lst);
	free_list(lst);

	/* Test 02: Add to one-node list */
	printf("\nTEST 02: One existing node\n");
	lst = make_node(&a);
	node = make_node(&b);
	ft_lstadd_front(&lst, node);
	printf("Expected: 20 -> 10 -> NULL\n");
	printf("Got:      ");
	print_list(lst);
	free_list(lst);

	/* Test 03: Add to two-node list */
	printf("\nTEST 03: Two existing nodes\n");
	lst = make_node(&a);
	lst->next = make_node(&b);
	node = make_node(&c);
	ft_lstadd_front(&lst, node);
	printf("Expected: 30 -> 10 -> 20 -> NULL\n");
	printf("Got:      ");
	print_list(lst);
	free_list(lst);

	/* Test 04: Check size increases */
	printf("\nTEST 04: Size increases\n");
	lst = make_node(&a);
	node = make_node(&b);
	printf("Before: %d\n", list_size(lst));
	ft_lstadd_front(&lst, node);
	printf("After:  %d (expected 2)\n", list_size(lst));
	free_list(lst);

	/* Test 05: New node becomes head */
	printf("\nTEST 05: Head pointer\n");
	lst = make_node(&a);
	node = make_node(&b);
	ft_lstadd_front(&lst, node);
	printf("Passed: %d\n", lst == node);
	free_list(lst);

	/* Test 06: Old head remains second */
	printf("\nTEST 06: Old head preserved\n");
	lst = make_node(&a);
	node = make_node(&b);
	ft_lstadd_front(&lst, node);
	printf("Passed: %d\n", lst->next->content == &a);
	free_list(lst);

	/* Test 07: New node points to old head */
	printf("\nTEST 07: Link preserved\n");
	lst = make_node(&a);
	node = make_node(&b);
	{
		t_list *old_head = lst;
		ft_lstadd_front(&lst, node);
		printf("Passed: %d\n", node->next == old_head);
	}
	free_list(lst);

	/* Test 08: Add three nodes in sequence */
	printf("\nTEST 08: Three additions\n");
	lst = NULL;
	ft_lstadd_front(&lst, make_node(&a));
	ft_lstadd_front(&lst, make_node(&b));
	ft_lstadd_front(&lst, make_node(&c));
	printf("Expected: 30 -> 20 -> 10 -> NULL\n");
	printf("Got:      ");
	print_list(lst);
	free_list(lst);

	/* Test 09: Add same value, different node */
	printf("\nTEST 09: Duplicate values\n");
	lst = make_node(&a);
	node = make_node(&a);
	ft_lstadd_front(&lst, node);
	printf("Size: %d (expected 2)\n", list_size(lst));
	free_list(lst);

	/* Test 10: Negative content */
	printf("\nTEST 10: Negative value\n");
	a = -42;
	lst = make_node(&b);
	node = make_node(&a);
	ft_lstadd_front(&lst, node);
	printf("Head: %d (expected -42)\n", *(int *)lst->content);
	free_list(lst);

	/* Test 11: Zero content */
	printf("\nTEST 11: Zero value\n");
	a = 0;
	lst = make_node(&b);
	node = make_node(&a);
	ft_lstadd_front(&lst, node);
	printf("Head: %d (expected 0)\n", *(int *)lst->content);
	free_list(lst);

	/* Test 12: Large integer content */
	printf("\nTEST 12: Large integer\n");
	a = 2147483647;
	lst = make_node(&b);
	node = make_node(&a);
	ft_lstadd_front(&lst, node);
	printf("Head: %d\n", *(int *)lst->content);
	free_list(lst);

	/* Test 13: Content pointer preserved */
	printf("\nTEST 13: Content pointer\n");
	lst = make_node(&a);
	node = make_node(&b);
	ft_lstadd_front(&lst, node);
	printf("Passed: %d\n", lst->content == &b);
	free_list(lst);

	/* Test 14: Old tail preserved */
	printf("\nTEST 14: Tail preserved\n");
	lst = make_node(&a);
	lst->next = make_node(&b);
	node = make_node(&c);
	ft_lstadd_front(&lst, node);
	printf("Tail content: %d (expected 20)\n",
		*(int *)lst->next->next->content);
	free_list(lst);

	/* Test 15: Four-node list */
	printf("\nTEST 15: Four nodes\n");
	lst = make_node(&a);
	lst->next = make_node(&b);
	lst->next->next = make_node(&c);
	node = make_node(&a);
	ft_lstadd_front(&lst, node);
	printf("Size: %d (expected 4)\n", list_size(lst));
	free_list(lst);

	/* Test 16: New node next is NULL initially */
	printf("\nTEST 16: Initially NULL next\n");
	node = make_node(&a);
	printf("Passed: %d\n", node && node->next == NULL);
	free(node);

	/* Test 17: Empty list remains valid */
	printf("\nTEST 17: Empty list initialization\n");
	lst = NULL;
	node = make_node(&c);
	ft_lstadd_front(&lst, node);
	printf("Passed: %d\n", lst && lst->content == &c);
	free_list(lst);

	/* Test 18: New head next is NULL for empty list */
	printf("\nTEST 18: Empty list link\n");
	lst = NULL;
	node = make_node(&a);
	ft_lstadd_front(&lst, node);
	printf("Passed: %d\n", lst->next == NULL);
	free_list(lst);

	/* Test 19: Original head address preserved */
	printf("\nTEST 19: Original node preserved\n");
	lst = make_node(&a);
	{
		t_list *old_head = lst;
		node = make_node(&b);
		ft_lstadd_front(&lst, node);
		printf("Passed: %d\n", lst->next == old_head);
	}
	free_list(lst);

	/* Test 20: Five nodes */
	printf("\nTEST 20: Five nodes\n");
	lst = NULL;
	ft_lstadd_front(&lst, make_node(&a));
	ft_lstadd_front(&lst, make_node(&b));
	ft_lstadd_front(&lst, make_node(&c));
	ft_lstadd_front(&lst, make_node(&a));
	ft_lstadd_front(&lst, make_node(&b));
	printf("Size: %d (expected 5)\n", list_size(lst));
	free_list(lst);

	/* Test 21: NULL list pointer */
	printf("\nTEST 21: NULL lst pointer\n");
	node = make_node(&a);
	ft_lstadd_front(NULL, node);
	printf("No crash expected if NULL lst is handled.\n");
	free(node);

	/* Test 22: NULL new node */
	printf("\nTEST 22: NULL new\n");
	lst = make_node(&a);
	ft_lstadd_front(&lst, NULL);
	printf("Size: %d (expected 1 if NULL new is ignored)\n",
		list_size(lst));
	free_list(lst);

	/* Test 23: Both arguments NULL */
	printf("\nTEST 23: Both NULL\n");
	ft_lstadd_front(NULL, NULL);
	printf("No crash expected if NULL lst is handled.\n");

	/* Test 24: Repeated additions preserve order */
	printf("\nTEST 24: Reverse insertion order\n");
	lst = NULL;
	ft_lstadd_front(&lst, make_node(&a));
	ft_lstadd_front(&lst, make_node(&b));
	ft_lstadd_front(&lst, make_node(&c));
	printf("Expected: 30 -> 20 -> 10 -> NULL\n");
	printf("Got:      ");
	print_list(lst);
	free_list(lst);

	/* Test 25: Verify final head, size and links */
	printf("\nTEST 25: Final integrity\n");
	lst = NULL;
	ft_lstadd_front(&lst, make_node(&a));
	ft_lstadd_front(&lst, make_node(&b));
	ft_lstadd_front(&lst, make_node(&c));
	printf("Head: %d (expected 30)\n", *(int *)lst->content);
	printf("Size: %d (expected 3)\n", list_size(lst));
	printf("Second: %d (expected 20)\n",
		*(int *)lst->next->content);
	printf("Third: %d (expected 10)\n",
		*(int *)lst->next->next->content);
	free_list(lst);

	return (0);
}
