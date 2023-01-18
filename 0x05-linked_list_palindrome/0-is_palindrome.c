#include <stdio.h>
#include <stddef.h>
#include "lists.h"

/**
 * is_palindrome - palindrome
 * @head: head
 * Return: 1 if palindrome
 */
int is_palindrome(listint_t **head){
    listint_t *temp = *head;
    int i = 0;
    int j = 0;
    int array[1000000];

    if (*head == NULL)
        return (1);
    while (temp != NULL){
        array[i] = temp->n;
        temp = temp->next;
        i++;
    }
    i--;
    while (i > j){
        if (array[i] != array[j])
            return (0);
        i--;
        j++;
    }
    return (1);
}