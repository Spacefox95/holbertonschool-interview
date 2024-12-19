#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL, *next = NULL;
	while (head)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return prev;
}

int is_palindrome(listint_t **head)
{
	if (!head || !(*head))
		return 1;

	listint_t *first_list = *head;
	listint_t *second_list = *head;
	listint_t *first_half = *head;
	listint_t *second_half;

	while (second_list && second_list->next)
	{
		first_list = first_list->next;
		second_list = second_list->next->next;
	};
	second_half = reverse_list(first_list);

	listint_t *temp = second_half;
	while (second_half)
	{
		if (first_half->n != second_half->n)
		{
			reverse_list(temp);
			return 0;
		}
		first_half = first_half->next;
		second_half = second_half->next;
	}
	reverse_list(temp);
	return 1;
}
