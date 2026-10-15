#include "../level0/libft.h"

static void run_test(int test_num, t_list *lst,
	unsigned int expected)
{
	unsigned int result;

	result = ft_lstsize(lst);
	printf("Test %02d: expected=%u | got=%u | %s\n",
		test_num, expected, result,
		result == expected ? "PASS" : "FAIL");
}

static t_list *create_node(void *content)
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
	int a;
	int b;
	int c;
	int d;
	int e;

	a = 10;
	b = 20;
	c = 30;
	d = 40;
	e = 50;

	/* Test 01: Empty list */
	run_test(1, NULL, 0);

	/* Test 02: One node */
	lst = create_node(&a);
	run_test(2, lst, 1);

	/* Test 03: Two nodes */
	n2 = create_node(&b);
	lst->next = n2;
	run_test(3, lst, 2);

	/* Test 04: Three nodes */
	n3 = create_node(&c);
	n2->next = n3;
	run_test(4, lst, 3);

	/* Test 05: Four nodes */
	n4 = create_node(&d);
	n3->next = n4;
	run_test(5, lst, 4);

	/* Test 06: Five nodes */
	n5 = create_node(&e);
	n4->next = n5;
	run_test(6, lst, 5);

	/* Test 07: Count from second node */
	run_test(7, n2, 4);

	/* Test 08: Count from third node */
	run_test(8, n3, 3);

	/* Test 09: Count from fourth node */
	run_test(9, n4, 2);

	/* Test 10: Count from last node */
	run_test(10, n5, 1);

	/* Test 11: Last node has NULL next */
	run_test(11, n5, 1);

	/* Test 12: List with NULL content */
	lst->content = NULL;
	run_test(12, lst, 5);

	/* Test 13: Change content */
	lst->content = &a;
	run_test(13, lst, 5);

	/* Test 14: First node points directly to last */
	n1 = create_node(&a);
	n1->next = n5;
	run_test(14, n1, 2);

	/* Test 15: Separate one-node list */
	n1->next = NULL;
	run_test(15, n1, 1);

	/* Test 16: Separate two-node list */
	n1->next = n2;
	n2->next = NULL;
	run_test(16, n1, 2);

	/* Test 17: Separate three-node list */
	n2->next = n3;
	n3->next = NULL;
	run_test(17, n1, 3);

	/* Test 18: Restore original five-node list */
	n1->next = NULL;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	run_test(18, n1, 5);

	/* Test 19: Another empty list */
	run_test(19, NULL, 0);

	/* Test 20: Count again after restoring list */
	run_test(20, lst, 5);

	/* Free each allocated node exactly once */
	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);

	return (0);
}

