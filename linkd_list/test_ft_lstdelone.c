#include "../level0/libft.h"

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

int main(void)
{
	t_list *n1;
	t_list *n2;
	t_list *n3;
	t_list *single;
	t_list *null_content;
	int *content;

	/* Test 01: Delete a single node */
	g_del_count = 0;
	single = new_int_node(10);
	ft_lstdelone(single, test_del);
	check(1, g_del_count == 1);

	/* Test 02: del called exactly once */
	g_del_count = 0;
	single = new_int_node(20);
	ft_lstdelone(single, test_del);
	check(2, g_del_count == 1);

	/* Test 03: Delete first node; next node survives */
	n1 = new_int_node(1);
	n2 = new_int_node(2);
	n1->next = n2;
	ft_lstdelone(n1, test_del);
	check(3, *(int *)n2->content == 2);

	/* Test 04: Next pointer of surviving node unchanged */
	check(4, n2->next == NULL);

	/* Test 05: Delete middle node; next survives */
	n1 = new_int_node(1);
	n2 = new_int_node(2);
	n3 = new_int_node(3);
	n2->next = n3;
	ft_lstdelone(n2, test_del);
	check(5, *(int *)n3->content == 3);

	/* Test 06: The next node still exists */
	check(6, n2->next == n3);

	/* Test 07: del receives the node content */
	n1 = new_int_node(42);
	content = n1->content;
	g_del_count = 0;
	ft_lstdelone(n1, test_del);
	check(7, g_del_count == 1);
	(void)content;

	/* Test 08: Delete node whose content is NULL */
	null_content = ft_lstnew(NULL);
	if (!null_content)
		return (1);
	g_del_count = 0;
	ft_lstdelone(null_content, test_del);
	check(8, g_del_count == 1);

	/* Test 09: Delete a node with string content */
	n1 = ft_lstnew(NULL);
	if (!n1)
		return (1);
	n1->content = malloc(6);
	if (!n1->content)
	{
		free(n1);
		return (1);
	}
	snprintf(n1->content, 6, "hello");
	g_del_count = 0;
	ft_lstdelone(n1, test_del);
	check(9, g_del_count == 1);

	/* Test 10: del called once for string content */
	check(10, g_del_count == 1);

	/* Test 11: Node with zero as content value */
	n1 = new_int_node(0);
	g_del_count = 0;
	ft_lstdelone(n1, test_del);
	check(11, g_del_count == 1);

	/* Test 12: Negative integer content */
	n1 = new_int_node(-42);
	g_del_count = 0;
	ft_lstdelone(n1, test_del);
	check(12, g_del_count == 1);

	/* Test 13: Large integer content */
	n1 = new_int_node(2147483647);
	g_del_count = 0;
	ft_lstdelone(n1, test_del);
	check(13, g_del_count == 1);

	/* Test 14: Delete last node */
	n1 = new_int_node(1);
	n2 = new_int_node(2);
	n1->next = n2;
	ft_lstdelone(n2, test_del);
	check(14, *(int *)n1->content == 1);
	free(n1->content);
	free(n1);

	/* Test 15: Delete node with custom content */
	n1 = new_int_node(99);
	g_del_count = 0;
	ft_lstdelone(n1, test_del);
	check(15, g_del_count == 1);

	/* Test 16: Delete one node from a two-node chain */
	n1 = new_int_node(11);
	n2 = new_int_node(22);
	n1->next = n2;
	ft_lstdelone(n1, test_del);
	check(16, *(int *)n2->content == 22);
	free(n2->content);
	free(n2);

	/* Test 17: del receives NULL content */
	null_content = ft_lstnew(NULL);
	if (!null_content)
		return (1);
	g_del_count = 0;
	ft_lstdelone(null_content, test_del);
	check(17, g_del_count == 1);

	/* Test 18: Delete node with another integer */
	n1 = new_int_node(123);
	g_del_count = 0;
	ft_lstdelone(n1, test_del);
	check(18, g_del_count == 1);

	/* Test 19: Delete node with content 7 */
	n1 = new_int_node(7);
	g_del_count = 0;
	ft_lstdelone(n1, test_del);
	check(19, g_del_count == 1);

	/* Test 20: Delete node with content 100 */
	n1 = new_int_node(100);
	g_del_count = 0;
	ft_lstdelone(n1, test_del);
	check(20, g_del_count == 1);

	/* Clean up nodes intentionally kept alive */
	free(n2->content);
	free(n2);
	free(n3->content);
	free(n3);
	return (0);
}
