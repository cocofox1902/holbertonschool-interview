#include "binary_trees.h"

/**
 * swapper - swapper
 * @parent: parent
 * @node: node
 * Return: void
 */
void swapper(int *parent, int *node)
{
	int temp = *parent;
	*parent = *node;
	*node = temp;
}

/**
 * size_tree - size of tree
 * @tree: tree
 * Return: size
 */
size_t size_tree(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (size_tree(tree->left) + 1 + size_tree(tree->right));
}

/**
 * childe_finder - find
 * @root: root
 * @idx: node index
 * @size: size
 * Return: position
 */
heap_t *childe_finder(heap_t *root, size_t idx, size_t size)
{
	heap_t *left, *right;

	if (idx > size)
	{
		return (NULL);
	}

	if (idx == size)
	{
		return (root);
	}

	left = childe_finder(root->left, 2 * idx + 1, size);
	right = childe_finder(root->right, 2 * idx + 2, size);

	if (left != NULL)
	{
		return (left);
	}
	else if (right != NULL)
	{
		return (right);
	}
	else
	{
		return (NULL);
	}
}

/**
 * parent_finder - find
 * @root: root
 * @new: node to insert
 * Return: position
 */
heap_t *parent_finder(heap_t *root, heap_t *new)
{
	heap_t *parent;
	size_t size;

	size = size_tree(root);
	parent = childe_finder(root, 0, (size - 1) / 2);

	if (parent->left == NULL)
	{
		parent->left = new;
	}
	else
	{
		parent->right = new;
	}

	return (parent);
}

/**
 * heap_insert - insert
 * @root: root
 * @value: value
 * Return: new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	new_node = binary_tree_node(NULL, value);

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	parent = parent_finder(*root, new_node);
	new_node->parent = parent;

	while (new_node->parent != NULL && new_node->parent->n < new_node->n)
	{
		swapper(&new_node->parent->n, &new_node->n);
		new_node = new_node->parent;
	}

	return (new_node);
}
