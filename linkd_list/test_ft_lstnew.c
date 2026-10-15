#include "libft.h"

int	main(void)
{
	t_list	*node;
	t_list	*first;
	t_list	*second;
	int		number;

	// Test 1: String content
	printf("=== Test 1: String ===\n");
	node = ft_lstnew("Hello");
	if (node)
	{
		printf("Content: %s\n", (char *)node->content);
		printf("Next: %p\n", (void *)node->next);
		free(node);
	}

	// Test 2: NULL content
	printf("\n=== Test 2: NULL content ===\n");
	node = ft_lstnew(NULL);
	if (node)
	{
		printf("Content: %p\n", node->content);
		printf("Next: %p\n", (void *)node->next);
		free(node);
	}

	// Test 3: Integer content 
	printf("\n=== Test 3: Integer ===\n");
	number = 42;
	node = ft_lstnew(&number);
	if (node)
	{
		printf("Content: %d\n", *(int *)node->content);
		free(node);
	}

	//Test 4: Allocation result 
	printf("\n=== Test 4: Allocation ===\n");
	node = ft_lstnew("Test");
	if (!node)
		printf("Allocation failed\n");
	else
	{
		printf("Allocation succeeded\n");
		free(node);
	}

	// Test 5: Multiple nodes 
	printf("\n=== Test 5: Multiple nodes ===\n");
	first = ft_lstnew("First");
	second = ft_lstnew("Second");
	if (first && second)
	{
		printf("First: %s\n", (char *)first->content);
		printf("Second: %s\n", (char *)second->content);
		printf("Same node: %d\n", first == second);
	}
	free(first);
	free(second);
	return (0);	
}
