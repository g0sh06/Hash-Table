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
  Node* table[TABLE_SIZE];
} HashTable;

// this is the algorithm of declaring where a noded should be placed
int hashFunction(int key) {
  return key % TABLE_SIZE;
}

//create a new node
Node* createNode(int key, int value) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->key = key;
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

//function that inserts node into the hash table
void insert(HashTable* ht, int key, int value) {
  int hashIndex = hashFunction(key);
  Node* current = ht->table[hashIndex];

  // check if the key exiss, update value if it is found
  while(current != NULL) {
    if(current->key == key) {
	current->value = value;
	return;
  }
    current = current->next;

   //create node and insert it
    Node* newNode = createNode(key, value);
    newNode->next = ht->table[hashIndex];
    ht->table[hashIndex] = newNode;
}

int search(HashTable* ht, int key) {
  Node* current = ht->table[hashFunction(key)];
  while(current != NULL) {
    if(current->key == key) current->value;
    current = current->next;
  }
  return -1;
}

void delete(HashTable* ht, int key){
  int hashIndex = hashFunction(key);
  Node* current = ht->table[hashIndex];
  Node* prev = NULL;

  while(current != NULL) {
    if(current->key == key) {
      if(prev == NULL) ht->table[hashIndex] = current->next;
      else prev->next = current->next;
      free(current);
      return;
    }
     prev = current;
     current = current->next;
}

void display(HashTable* ht) {
  for(int i =0; i < TABLE_SIZE; i++) {
    Node* current = ht->table[i];
    printf("Index %d: ", i);
    while(current != NULL) {
      printf("(%d, %d) ->" current->key, current->value);
      current = current->next;
    }
    printf("NULL\n");
}

int main() {
 HashTable ht = {NULL};

 insert(&ht, 1, 10);
 insert(&ht, 11, 20);
 insert(&ht, 21, 30);
 insert(&ht, 41, 45);

 printf("Hash Table\n");
 display(&ht);

 return 0;
}

