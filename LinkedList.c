// John Chang
// Linked List definition file: list.c

#include "LinkedList.h"

// Creates an empty list.
Node *createList(void) {
    Node *new = malloc(sizeof(Node));
    new->count1 = 0;
    new->count2 = 0;
    new->next = NULL;
    return new;
}

// Inserts alphabetically on name
void insert(List **list, char *name, int value) {
    Node *scan, *back = NULL;
    Node *newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->count1 = 0;
    newNode->count2 = 0;
    newNode->next = NULL;

    if(value == 1)
        newNode->count1 = 1;
    else
        newNode->count2 = 1;
    
    if (*list == NULL) {
        *list = newNode;
    }else {
        
        scan = *list;
        while (scan != NULL && strcmp(scan->name, name) <= 0) {
            back = scan;
            scan = scan->next;
        }
        if(scan == *list) {
            insertAtBeginning(list, newNode);
        }else if (strcmp(back->name, name) == 0 ) {
            if(value == 1)
                back->count1++;
            else
                back->count2++;
        }else {       
            newNode->next = scan;
            back->next = newNode;
        }
    }
}

// sorts by word count
void bubbleSort(List** list) {
    int done = 0;
    
    while(done == 0) {
        Node **pv = list;
        Node *nd = *list;
        Node *nx = (*list)->next;
        done = 1;
        
        while (nx) {
            if(difference(nd) < difference(nx)) {
                nd->next = nx->next;
                nx->next = nd;
                *pv = nx;
                done = 0;
            }
            pv = &nd->next;
            nd = nx;
            nx = nx->next;
        }
    }
   
}

// helper function for bubble sort
void swap(Node *one, Node *two) {
    char tname[20];
    strcpy(tname, one->name);
    int tcount1 = one->count1;
    int tcount2 = one->count1;
    
    strcpy(one->name, two->name);
    one->count1 = two->count1;
    one->count1 = two->count2;
    
    strcpy(two->name, tname);
    two->count1 = tcount1;
    two->count1 = tcount2;
    
}

// returns the difference in appearances
int difference(Node* one) {
    int result = 0;
    if(one->count1 >= one->count2)
        result = one->count1 - one->count2;
    else
        result = one->count2 - one->count1;
    return result;
}

// inserts node into the beginning of list
void insertAtBeginning(List **list, Node *n) {
    n->next = *list;
    *list = n;
}

// prints the first 25 in list
int printList(List **list, int tot, int val) {
    Node *n = *list;
    int i = 0;
    while (n != NULL) {
        if(i>0 && i < 25)
            printf("%s %d \n", n->name, difference(n));
        n = n->next;
        i++;
        if(val == 1 && i >= tot-5)
            printf("%s\n", n->name);
    }
    printf("\n");
    return i;
}

// frees the list memory allocation
void freeList(List *list) {
    if (list) {
        freeList(list->next);
        free(list);
    }
}

