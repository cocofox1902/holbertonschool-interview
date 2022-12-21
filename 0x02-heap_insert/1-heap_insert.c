#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"


/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node = malloc(sizeof(heap_t));

	node->left = NULL;
	node->right = NULL;
	node->n = value;
	if (node == NULL)
	{
		return (NULL);
	}
	if (*root == NULL)
	{
		*root = node;
		return (node);
	}

	heap_t *current = *root;

	while (current->left != NULL && current->right != NULL)
	{
		if (current->left->left == NULL || current->left->right == NULL)
		{
			current = current->left;
		}
		else if (current->right->left == NULL || current->right->right == NULL)
		{
			current = current->right;
		}
		else
		{
			current = current->left;
		}
	}

	if (current->left == NULL)
	{
		current->left = node;
		node->parent = current;
	}
	else if (current->right == NULL)
	{
		current->right = node;
		node->parent = current;
	}

	while (node->parent != NULL && node->n > node->parent->n)
	{
		swap(&node->n, &node->parent->n);
		node = node->parent;
	}
	return (node);
}
