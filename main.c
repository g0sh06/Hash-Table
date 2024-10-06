
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Define the structure of a node in the hash table
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node* table[TABLE_SIZE];  // Array of pointers to nodes (for chaining)
} HashTable;

// Hash function to determine the index
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Create a new node
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the hash table
void insert(HashTable* ht, int key, int value) {
    int hashIndex = hashFunction(key);
    Node* current = ht->table[hashIndex];

    // Check if the key exists, update the value if found
    while (current != NULL) {
        if (current->key == key) {
            current->value = value;
            return;
        }
        current = current->next;
    }

    // Create a new node and insert it at the beginning of the list
    Node* newNode = createNode(key, value);
    newNode->next = ht->table[hashIndex];
    ht->table[hashIndex] = newNode;
}

// Function to search for a value by its key
int search(HashTable* ht, int key) {
    int hashIndex = hashFunction(key);
    Node* current = ht->table[hashIndex];

    // Traverse the list at the hash index to find the key
    while (current != NULL) {
        if (current->key == key) {
            return current->value;  // Return the value if key is found
        }
        current = current->next;
    }
    return -1;  // Return -1 if the key is not found
}

// Function to delete a node from the hash table
void delete(HashTable* ht, int key) {
    int hashIndex = hashFunction(key);
    Node* current = ht->table[hashIndex];
    Node* prev = NULL;

    // Traverse the list at the hash index to find the key
    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                // If it's the first node in the list
                ht->table[hashIndex] = current->next;
            } else {
                // Link the previous node to the next node
                prev->next = current->next;
            }
            free(current);  // Free the memory of the deleted node
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Function to display the hash table
void display(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = ht->table[i];
        printf("Index %d: ", i);
        while (current != NULL) {
            printf("(%d, %d) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // Initialize the hash table with NULL values
    HashTable ht;
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht.table[i] = NULL;
    }

    // Insert some key-value pairs
    insert(&ht, 1, 10);
    insert(&ht, 11, 20);
    insert(&ht, 21, 30);
    insert(&ht, 41, 45);

    // Display the hash table
    printf("Hash Table\n");
    display(&ht);

    return 0;
}


