#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * enqueue - Adds a node to the end of the queue
 * @head: Pointer to the head of the queue
 * @node: Node to enqueue
 */
void enqueue(queue_t **head, heap_t *node)
{
	queue_t *new = malloc(sizeof(queue_t)), *tmp;

	if (!new)
		return;

	new->node = node;
	new->next = NULL;

	if (!*head)
	{
		*head = new;
		return;
	}

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new;
}

/**
 * dequeue - Removes and returns the first node in the queue
 * @head: Pointer to the head of the queue
 *
 * Return: Node from the queue
 */
heap_t *dequeue(queue_t **head)
{
	queue_t *tmp;
	heap_t *node;

	if (!head || !*head)
		return (NULL);

	tmp = *head;
	node = tmp->node;
	*head = tmp->next;
	free(tmp);

	return (node);
}

/**
 * get_last_node - finds the last node in level-order traversal
 * @root: Pointer to the root node of the heap
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	queue_t *queue = NULL;
	heap_t *node = NULL;

	enqueue(&queue, root);
	while (queue)
	{
		node = dequeue(&queue);
		if (node->left)
			enqueue(&queue, node->left);
		if (node->right)
			enqueue(&queue, node->right);
	}

	return (node);
}


/**
 * sift_down - restores heap property by shifting down
 * @node: pointer to the node sift down
 */
void sift_down(heap_t *node)
{
	heap_t *max;
	int tmp;

	while (node)
	{
		max = node;

		if (node->left && node->left->n > max->n)
			max = node->left;
		if (node->right && node->right->n > max->n)
			max = node->right;

		if (max == node)
			break;

		tmp = node->n;
		node->n = max->n;
		max->n = tmp;

		node = max;
	}
}


/**
 * heap_extract - Etracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
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
	(*root)->n = last->n;

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);
	sift_down(*root);

	return (value);
}
