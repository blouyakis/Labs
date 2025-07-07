#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>


// TODO: Create your node_t type here
typedef struct node
{
    int num_wins;
    int year;
    struct node *next; // notice this pointer!
} Pair;

typedef struct list
{
    Pair *head;
    int size;
} NeuList;

Pair *new_node(int wins, int year, Pair *next)
{

    Pair *newNode = (Pair *)malloc(sizeof(Pair));
    newNode->num_wins = wins;
    newNode->year = year;
    newNode->next = next;
    return newNode;
}

NeuList* create_list() {
    NeuList *list = (NeuList *)malloc(sizeof(NeuList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void push_front(NeuList *list, int wins, int year)
{
    Pair *newNode = new_node(wins, year, list->head);
    list->head = newNode;
    list->size++;
}

void add_back(NeuList *list, int wins, int year) {
    Pair *newNode = new_node(wins, year, NULL);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Pair *curr = list->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    list->size++;
}

void print_list(NeuList *list)
{
    Pair *curr = list->head;
    while (curr != NULL)
    {
        printf("(%d, %d)", curr->num_wins, curr->year);
        if (curr->next != NULL)
        {
            printf(" -> ");
        }
        curr = curr->next;
    }
    printf("\n");
}

Pair *find(NeuList *list, int year)
{
    // Check if list is NULL or empty
    if (list == NULL || list->head == NULL) {
        return NULL;
    }
    
    // Traverse the list to find the node with matching year
    Pair *curr = list->head;
    while (curr != NULL) {
        if (curr->year == year) {
            return curr;  // Found the node
        }
        curr = curr->next;
    }
    
    return NULL;  // Year not found in the list
}

void free_list(NeuList *list)
{
    // Check if list is NULL
    if (list == NULL) {
        return;
    }
    
    // Free all nodes in the list
    Pair *curr = list->head;
    while (curr != NULL) {
        Pair *temp = curr;      // Store current node
        curr = curr->next;      // Move to next node
        free(temp);             // Free the stored node
    }
    
    // Free the list structure itself
    free(list);
}

#endif //LINKED_LIST_H