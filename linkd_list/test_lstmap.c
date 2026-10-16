
#include "../level0/libft.h"

static void	*add_one(void *content)
{
	int	*n;

	n = malloc(sizeof(int));
	if (!n)
		return (NULL);
	*n = *(int *)content + 1;
	return (n);
}

static void	*multiply_two(void *content)
{
	int	*n;

	n = malloc(sizeof(int));
	if (!n)
		return (NULL);
	*n = *(int *)content * 2;
	return (n);
}

static void	*square_num(void *content)
{
	int	*n;

	n = malloc(sizeof(int));
	if (!n)
		return (NULL);
	*n = (*(int *)content) * (*(int *)content);
	return (n);
}

static void	*return_null(void *content)
{
	(void)content;
	return (NULL);
}

static void	delete_int(void *content)
{
	free(content);
}

static t_list	*new_node(int value)
{
	int		*n;
	t_list	*node;

	n = malloc(sizeof(int));
	if (!n)
		exit(1);
	*n = value;
	node = ft_lstnew(n);
	if (!node)
	{
		free(n);
		exit(1);
	}
	return (node);
}

static t_list	*make_list(int *values, int size)
{
	t_list	*lst;
	t_list	*node;
	int		i;

	lst = NULL;
	i = 0;
	while (i < size)
	{
		node = new_node(values[i]);
		ft_lstadd_back(&lst, node);
		i++;
	}
	return (lst);
}

static int	check_values(t_list *lst, int *expected, int size)
{
	int	i;

	i = 0;
	while (i < size && lst)
	{
		if (*(int *)lst->content != expected[i])
			return (0);
		lst = lst->next;
		i++;
	}
	return (i == size && lst == NULL);
}

static void	check(int num, t_list *lst, int *expected, int size)
{
	int	i;

	if (check_values(lst, expected, size))
		printf("Test %02d: PASS\n", num);
	else
	{
		printf("Test %02d: FAIL\n", num);
		printf("  Expected: ");
		i = 0;
		while (i < size)
		{
			printf("%d ", expected[i]);
			i++;
		}
		printf("\n  Got:      ");
		while (lst)
		{
			printf("%d ", *(int *)lst->content);
			lst = lst->next;
		}
		printf("\n");
	}
}

static void	free_list(t_list *lst)
{
	ft_lstclear(&lst, delete_int);
}

int	main(void)
{
	int		values[] = {1, 2, 3};
	int		expected1[] = {2, 3, 4};
	int		expected2[] = {2, 4, 6};
	int		expected3[] = {1, 4, 9};
	int		expected4[] = {6};
	int		expected5[] = {1, 1, 1};
	int		expected6[] = {0, -1, -2};
	int		expected7[] = {1, 2, 3};
	int		expected12[] = {2, 3, 4, 5};
	int		single[] = {5};
	int		zeros[] = {0, 0, 0};
	int		negatives[] = {-1, -2, -3};
	int		four[] = {1, 2, 3, 4};
	t_list	*lst;
	t_list	*mapped;
	t_list	*empty;
	int		i;

	/* Test 01: Empty list */
	mapped = ft_lstmap(NULL, add_one, delete_int);
	if (!mapped)
		printf("Test 01: PASS\n");
	else
		printf("Test 01: FAIL\n");
	free_list(mapped);

	/* Test 02: One node */
	lst = make_list(single, 1);
	mapped = ft_lstmap(lst, add_one, delete_int);
	check(2, mapped, expected4, 1);
	free_list(mapped);
	free_list(lst);

	/* Test 03: Three nodes with add_one */
	lst = make_list(values, 3);
	mapped = ft_lstmap(lst, add_one, delete_int);
	check(3, mapped, expected1, 3);
	free_list(mapped);
	free_list(lst);

	/* Test 04: multiply_two */
	lst = make_list(values, 3);
	mapped = ft_lstmap(lst, multiply_two, delete_int);
	check(4, mapped, expected2, 3);
	free_list(mapped);
	free_list(lst);

	/* Test 05: square_num */
	lst = make_list(values, 3);
	mapped = ft_lstmap(lst, square_num, delete_int);
	check(5, mapped, expected3, 3);
	free_list(mapped);
	free_list(lst);

	/* Test 06: Zero values */
	lst = make_list(zeros, 3);
	mapped = ft_lstmap(lst, add_one, delete_int);
	check(6, mapped, expected5, 3);
	free_list(mapped);
	free_list(lst);

	/* Test 07: Negative values */
	lst = make_list(negatives, 3);
	mapped = ft_lstmap(lst, add_one, delete_int);
	check(7, mapped, expected6, 3);
	free_list(mapped);
	free_list(lst);

	/* Test 08: Original list unchanged */
	lst = make_list(values, 3);
	mapped = ft_lstmap(lst, add_one, delete_int);
	if (check_values(lst, expected7, 3))
		printf("Test 08: PASS\n");
	else
		printf("Test 08: FAIL\n");
	free_list(mapped);
	free_list(lst);

	/* Test 09: Different head addresses */
	lst = make_list(values, 3);
	mapped = ft_lstmap(lst, add_one, delete_int);
	if (mapped && mapped != lst)
		printf("Test 09: PASS\n");
	else
		printf("Test 09: FAIL\n");
	free_list(mapped);
	free_list(lst);

	/* Test 10: Different content addresses */
	lst = make_list(values, 3);
	mapped = ft_lstmap(lst, add_one, delete_int);
	if (mapped && mapped->content != lst->content)
		printf("Test 10: PASS\n");
	else
		printf("Test 10: FAIL\n");
	free_list(mapped);
	free_list(lst);

	/* Test 11: Repeated values */
	lst = make_list(zeros, 3);
	mapped = ft_lstmap(lst, multiply_two, delete_int);
	check(11, mapped, zeros, 3);
	free_list(mapped);
	free_list(lst);

	/* Test 12: Four nodes */
	lst = make_list(four, 4);
	mapped = ft_lstmap(lst, add_one, delete_int);
	check(12, mapped, expected12, 4);
	free_list(mapped);
	free_list(lst);

	/* Test 13: Mapped list size */
	lst = make_list(values, 3);
	mapped = ft_lstmap(lst, add_one, delete_int);
	if (ft_lstsize(mapped) == ft_lstsize(lst))
		printf("Test 13: PASS\n");
	else
		printf("Test 13: FAIL\n");
	free_list(mapped);
	free_list(lst);

	/* Test 14: Mapped last node */
	lst = make_list(values, 3);
	mapped = ft_lstmap(lst, add_one, delete_int);
	if (mapped && ft_lstlast(mapped)->next == NULL)
		printf("Test 14: PASS\n");
	else
		printf("Test 14: FAIL\n");
	free_list(mapped);
	free_list(lst);

	/* Test 15: Last mapped value */
	lst = make_list(values, 3);
	mapped = ft_lstmap(lst, add_one, delete_int);
	if (mapped && *(int *)ft_lstlast(mapped)->content == 4)
		printf("Test 15: PASS\n");
	else
		printf("Test 15: FAIL\n");
	free_list(mapped);
	free_list(lst);

	/* Test 16: NULL returned by f */
	lst = make_list(values, 3);
	mapped = ft_lstmap(lst, return_null, delete_int);
	if (!mapped)
		printf("Test 16: PASS\n");
	else
		printf("Test 16: FAIL\n");
	free_list(mapped);
	free_list(lst);

	/* Test 17: Original still valid after mapping */
	lst = make_list(values, 3);
	mapped = ft_lstmap(lst, add_one, delete_int);
	if (check_values(lst, expected7, 3))
		printf("Test 17: PASS\n");
	else
		printf("Test 17: FAIL\n");
	free_list(mapped);
	free_list(lst);

	/* Test 18: Empty list size */
	empty = NULL;
	mapped = ft_lstmap(empty, multiply_two, delete_int);
	if (ft_lstsize(mapped) == 0)
		printf("Test 18: PASS\n");
	else
		printf("Test 18: FAIL\n");
	free_list(mapped);

	/* Test 19: All mapped nodes have separate contents */
	lst = make_list(values, 3);
	mapped = ft_lstmap(lst, add_one, delete_int);
	if (mapped && mapped->next
		&& mapped->content != mapped->next->content)
		printf("Test 19: PASS\n");
	else
		printf("Test 19: FAIL\n");
	free_list(mapped);
	free_list(lst);

	/* Test 20: Final list terminates correctly */
	lst = make_list(values, 3);
	mapped = ft_lstmap(lst, add_one, delete_int);
	i = 0;
	empty = mapped;
	while (empty)
	{
		i++;
		empty = empty->next;
	}
	if (i == 3 && ft_lstlast(mapped)->next == NULL)
		printf("Test 20: PASS\n");
	else
		printf("Test 20: FAIL\n");
	free_list(mapped);
	free_list(lst);
	return (0);
}