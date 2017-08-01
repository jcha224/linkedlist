// John Chang
// our file should only have main, header for linked list, and linkedlist code
// compile: gcc -std=c99 -o Driver lldriver.c linkedlist.c llergesort1.c

#include <stdio.h>

#include "LinkedList.h"

// prototypes
void readFile(List *list, FILE *file, int type);
char * updateWord(char *word);
void print(List*);

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    
    List *list = createList();
    FILE *in1 = fopen("RedBadge.txt", "r");
    FILE *in2 = fopen("LittleRegiment.txt", "r");
    
    
    readFile(list, in1, 1);
    
    readFile(list, in2, 2);

    int total = printList(&list, 0, 0);
    
    bubbleSort(&list);
    printList(&list, total, 1);
    
    freeList(list);
    fclose(in1);
    fclose(in2);
    return 0;
}

// reads words of file and adds to list or increments counter
void readFile(List *list, FILE *file, int type) {
    //return (c <= 'Z' && c >= 'A') ? c + 32 : c    // converts to lower
    char name[20];
    int value;
    while (fscanf(file, "%s", name) != EOF) {
        strcpy(name, updateWord(name));
        
        if(name[0] != '\0')
            insert(&list, name, type);
    }
}

// checks and updates word
char* updateWord(char *word) {
    char new[20] = {'\0'};
    char *scan = word;
    int i=0;
    while(*scan != '\0' && i !=-1) {
        if(*scan <= 90 && *scan >= 65) {
            new[i]= *scan + 32;
        } else if(*scan == '\'' || *scan == '-'){
            new[i] = *scan;
        }else if(*scan <= 122 && *scan >= 97) {
            new[i] = *scan;
        } else {
            i = -2;
        }
            
        scan++;
        i++;
    }
    char* ans = &new[0];
    return ans;
}

