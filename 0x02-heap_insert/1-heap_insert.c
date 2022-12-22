#include "binary_trees.h"

/**
 * binary_tree_size - measures the size
 * @tree: parents
 * Return: size or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	size_t size = 1 +
				  binary_tree_size(tree->left) +
				  binary_tree_size(tree->right);
	return (size);
}

/**
 * convertor - convertes
 * @num: size tree
 * @base: base
 * Return: string
 */
char *convertor(unsigned long int num, int base)
{
	static char buff[50];
	char *binary;
	char *representation = "01";

	binary = &buff[49];
	*binary = '\0';

	while (num)
	{
		binary--;
		*binary = representation[num % base];
		num /= base;
	}

	return (binary);
}

/**
 * insert_node - insert position
 * @root: root
 * @node: node to insert
 */
void insert_node(heap_t **root, heap_t *node)
{
	char bin, *binary;
	unsigned int idx, size;
	heap_t *aux = NULL;

	aux = *root;
	size = binary_tree_size(aux) + 1;
	binary = convertor(size, 2);

	for (idx = 1; idx < strlen(binary); idx++)
	{
		bin = binary[idx];
		if (idx == strlen(binary) - 1)
		{
			if (bin == '1')
			{
				aux->right = node;
			}
			else if (bin == '0')
			{
				aux->left = node;
			}
			node->parent = aux;
		}
		else if (bin == '1')
		{
			aux = aux->right;
		}
		else if (bin == '0')
		{
			aux = aux->left;
		}
	}
}

/**
 * heap_insert - insert
 * @root: root
 * @value: insertable
 * Return: the pointer
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (!root)
	{
		return (NULL);
	}

	heap_t *new_node = binary_tree_node(NULL, value);

	if (!(*root))
	{
		*root = new_node;
		return (new_node);
	}

	insert_node(root, new_node);
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		int temp = new_node->parent->n;

		new_node->parent->n = new_node->n;
		new_node->n = temp;
		new_node = new_node->parent;
	}
	return (new_node);
}
