#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * swap_values - Swaps values of 2 nodes
 * @a: pointer to first node
 * @b: pointer to second node
 */
void swap_values(heap_t *a, heap_t *b)
{
	int temp = a->n;

	a->n = b->n;
	b->n = temp;
}

/**
 * get_last_node - finds the last node in level-order traversal
 * @root: Pointer to the root node of the heap
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t *last = NULL;
	size_t height = 0, size = 0, mask;
	heap_t *node = root;

	for (size_t tmp = 1; node; tmp <<= 1)
	{
		height++;
		node = node->left;
	}
	size = (1 << height) - 1;
	mask = 1 << (height - 2);
	node = root;

	while (mask)
	{
		if (size & mask)
			node = node->right;
		else
			node = node->left;
		mask >>= 1;
	}
	last = node;
	return (last);
}

/**
 * sift_down - restores heap property by shifting down
 * @node: pointer to the node sift down
 */
void sift_down(heap_t *node)
{
	heap_t *largest;

	while (node->left)
	{
		largest = node->left;
		if (node->right && node->right->n > node->left->n)
			largest = node->right;
		if (node->n >= largest->n)
			break;
		swap_values(node, largest);
		node = largest;
	}
}

/**
 * heap_extract - Etracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
	heap_t *last, *parent;
	int value;

	if (!root || !*root)
	{
		return (0);
	}

	value = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = get_last_node(*root);
	swap_values(*root, last);

	parent = last->parent;
	if (parent->left == last)
		parent->left = NULL;
	else
		parent->right = NULL;

	free(last);
	sift_down(*root);

	return (value);
}
