
#include "../level0/libft.h"

static void run_test(int num, t_list *lst, t_list *expected)
{
	t_list	*result;

	result = ft_lstlast(lst);
	printf("Test %02d: %s\n", num,
		result == expected ? "PASS" : "FAIL");
	if (result != expected)
		printf("  Expected: %p | Got: %p\n",
			(void *)expected, (void *)result);
}

static t_list *new_node(void *content)
{
	t_list	*node;

	node = ft_lstnew(content);
	if (!node)
	{
		printf("Allocation failed\n");
		exit(1);
	}
	return (node);
}

int	main(void)
{
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;
	t_list	*n4;
	t_list	*n5;
	t_list	*single;
	t_list	*null_content;
	int		a;
	int		b;
	int		c;
	int		d;
	int		e;

	a = 10;
	b = 20;
	c = 30;
	d = 40;
	e = 50;

	n1 = new_node(&a);
	n2 = new_node(&b);
	n3 = new_node(&c);
	n4 = new_node(&d);
	n5 = new_node(&e);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	/* Test 01: Empty list */
	run_test(1, NULL, NULL);

	/* Test 02: One-node list */
	single = new_node(&a);
	run_test(2, single, single);

	/* Test 03: Five-node list */
	run_test(3, n1, n5);

	/* Test 04: Start at second node */
	run_test(4, n2, n5);

	/* Test 05: Start at third node */
	run_test(5, n3, n5);

	/* Test 06: Start at fourth node */
	run_test(6, n4, n5);

	/* Test 07: Start at last node */
	run_test(7, n5, n5);

	/* Test 08: Two-node list */
	n1->next = n2;
	n2->next = NULL;
	run_test(8, n1, n2);

	/* Test 09: Three-node list */
	n2->next = n3;
	n3->next = NULL;
	run_test(9, n1, n3);

	/* Test 10: Four-node list */
	n3->next = n4;
	n4->next = NULL;
	run_test(10, n1, n4);

	/* Test 11: Restore five-node list */
	n4->next = n5;
	run_test(11, n1, n5);

	/* Test 12: Last node has NULL next */
	run_test(12, n5, n5);

	/* Test 13: Node with NULL content */
	null_content = new_node(NULL);
	run_test(13, null_content, null_content);

	/* Test 14: NULL content in middle */
	n2->content = NULL;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	run_test(14, n1, n5);

	/* Test 15: NULL content at last node */
	n5->content = NULL;
	run_test(15, n1, n5);

	/* Test 16: Separate one-node list */
	n3->next = NULL;
	run_test(16, n3, n3);

	/* Test 17: Separate two-node list */
	n3->next = n4;
	n4->next = NULL;
	run_test(17, n3, n4);

	/* Test 18: Separate three-node list */
	n4->next = n5;
	n5->next = NULL;
	run_test(18, n3, n5);

	/* Test 19: Full list again */
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	run_test(19, n1, n5);

	/* Test 20: Empty list again */
	run_test(20, NULL, NULL);

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	free(single);
	free(null_content);
	return (0);
}
