#include "../level0/libft.h"

static void check(int num, t_list *lst, t_list *expected_last,
	unsigned int expected_size)
{
	t_list *last;
	unsigned int size;

	last = ft_lstlast(lst);
	size = ft_lstsize(lst);
	if (last == expected_last && size == expected_size)
		printf("Test %02d: PASS\n", num);
	else
	{
		printf("Test %02d: FAIL\n", num);
		printf("  Expected size: %u | Got: %u\n",
			expected_size, size);
		printf("  Expected last: %p | Got: %p\n",
			(void *)expected_last, (void *)last);
	}
}

static t_list *new_node(void *content)
{
	t_list *node;

	node = ft_lstnew(content);
	if (!node)
	{
		printf("Allocation failed\n");
		exit(1);
	}
	return (node);
}

int main(void)
{
	t_list *lst;
	t_list *n1;
	t_list *n2;
	t_list *n3;
	t_list *n4;
	t_list *n5;
	t_list *n6;
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;

	a = 10;
	b = 20;
	c = 30;
	d = 40;
	e = 50;
	f = 60;

	/* Test 01: Add to empty list */
	lst = NULL;
	n1 = new_node(&a);
	ft_lstadd_back(&lst, n1);
	check(1, lst, n1, 1);

	/* Test 02: Add second node */
	n2 = new_node(&b);
	ft_lstadd_back(&lst, n2);
	check(2, lst, n2, 2);

	/* Test 03: Add third node */
	n3 = new_node(&c);
	ft_lstadd_back(&lst, n3);
	check(3, lst, n3, 3);

	/* Test 04: Add fourth node */
	n4 = new_node(&d);
	ft_lstadd_back(&lst, n4);
	check(4, lst, n4, 4);

	/* Test 05: Add fifth node */
	n5 = new_node(&e);
	ft_lstadd_back(&lst, n5);
	check(5, lst, n5, 5);

	/* Test 06: Add sixth node */
	n6 = new_node(&f);
	ft_lstadd_back(&lst, n6);
	check(6, lst, n6, 6);

	/* Test 07: Head must remain the same */
	check(7, lst, n6, 6);
	if (lst == n1)
		printf("Test 07 head: PASS\n");
	else
		printf("Test 07 head: FAIL\n");

	/* Test 08: New node content */
	if (n6->content == &f)
		printf("Test 08 content: PASS\n");
	else
		printf("Test 08 content: FAIL\n");

	/* Test 09: Last node next must be NULL */
	if (n6->next == NULL)
		printf("Test 09 next: PASS\n");
	else
		printf("Test 09 next: FAIL\n");

	/* Test 10: Add node with NULL content */
	{
		t_list *n_null;

		n_null = new_node(NULL);
		ft_lstadd_back(&lst, n_null);
		check(10, lst, n_null, 7);
	}

	/* Test 11: Add another node after NULL content */
	{
		t_list *n7;

		n7 = new_node(&a);
		ft_lstadd_back(&lst, n7);
		check(11, lst, n7, 8);
	}

	/* Test 12: Independent empty list */
	{
		t_list *empty;

		empty = NULL;
		ft_lstadd_back(&empty, new_node(&b));
		check(12, empty, empty, 1);
		free(empty);
	}

	/* Test 13: Independent one-node list */
	{
		t_list *one;

		one = new_node(&c);
		ft_lstadd_back(&one, new_node(&d));
		check(13, one, one->next, 2);
		free(one->next);
		free(one);
	}

	/* Test 14: Add node to a two-node list */
	{
		t_list *two;
		t_list *two_last;
		t_list *added;

		two = new_node(&a);
		two_last = new_node(&b);
		two->next = two_last;
		added = new_node(&c);
		ft_lstadd_back(&two, added);
		check(14, two, added, 3);
		free(added);
		free(two_last);
		free(two);
	}

	/* Test 15: Original list must keep its order */
	if (lst == n1 && n1->next == n2 && n2->next == n3)
		printf("Test 15 order: PASS\n");
	else
		printf("Test 15 order: FAIL\n");

	/* Test 16: Last node is still the expected node */
	check(16, lst, n6->next->next, 8);

	/* Test 17: Add node to another empty list */
	{
		t_list *empty;
		t_list *added;

		empty = NULL;
		added = new_node(&e);
		ft_lstadd_back(&empty, added);
		check(17, empty, added, 1);
		free(added);
	}

	/* Test 18: Add node with value zero */
	{
		t_list *zero;
		int z;

		z = 0;
		zero = new_node(&z);
		ft_lstadd_back(&zero, new_node(&a));
		check(18, zero, zero->next, 2);
		free(zero->next);
		free(zero);
	}

	/* Test 19: Check final size */
	if (ft_lstsize(lst) == 8)
		printf("Test 19 size: PASS\n");
	else
		printf("Test 19 size: FAIL\n");

	/* Test 20: Final node points to NULL */
	if (ft_lstlast(lst)->next == NULL)
		printf("Test 20 next: PASS\n");
	else
		printf("Test 20 next: FAIL\n");

	/* Free main list */
	while (lst)
	{
		t_list *tmp;

		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (0);
}
