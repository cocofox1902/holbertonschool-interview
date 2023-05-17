#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * swap_nodes - Swaps the positions of two nodes in a binary tree
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */
void swap_nodes(heap_t *node1, heap_t *node2)
{
	int temp;

	temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}

/**
 * heapify_down - Restores the max heap property by moving a node down the tree
 * @root: Pointer to the root node of the tree
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = root;

	if (root->left && root->left->n > largest->n)
		largest = root->left;

	if (root->right && root->right->n > largest->n)
		largest = root->right;

	if (largest != root)
	{
		swap_nodes(root, largest);
		heapify_down(largest);
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node, *temp;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;
	last_node = *root;

	while (last_node->left || last_node->right)
	{
		if (!last_node->right || last_node->left->n >= last_node->right->n)
		{
			swap_nodes(last_node, last_node->left);
			last_node = last_node->left;
		}
		else if (!last_node->left || last_node->left->n < last_node->right->n)
		{
			swap_nodes(last_node, last_node->right);
			last_node = last_node->right;
		}
	}

	if (last_node->parent)
	{
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;
	}
	else
	{
		*root = NULL;
	}
	temp = last_node->parent;
	free(last_node);
	if (temp && binary_tree_size(temp) > 1)
		heapify_down(temp);
	return (value);
}
