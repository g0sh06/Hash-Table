#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// the structure of every node in the hash table
typedef struct NODE {
  int key;
  int value;
  struct Node* next;
} Node;

typedef struct HashTable{ 
  Node* table[TABLE_SIZe];
} HashTable;




int main() {
 printf("d");

}

