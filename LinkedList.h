 // John Chang
 // Linked List Header file: list.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Make up of a node
typedef struct node {
    char name[20];
    int count1;
    int count2;
    struct node *next;
} Node, List;

// LinkedList prototypes
int difference(Node *);
Node *createList(void);
void insert(List **, char *, int);
void insertAtBeginning(List **, Node *);
int printList(List **, int, int);
void freeList(List *);
void bubbleSort(List **);
void swap(Node *, Node *);

#endif 