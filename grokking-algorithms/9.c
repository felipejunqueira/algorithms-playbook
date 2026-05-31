#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

//apenas C e Assembly nao possuem hash padrao, implementacao dificilmente ocorrera

//structure for a hash table item (linked list node)
typedef struct Node {
    char* key;
    float value;
    struct Node* next;
} Node;

//hash table: array de ponteiros para nós
Node* hashTable[TABLE_SIZE];

//funcao hash simples: soma dos codigos ASCII % tamanho da tabela
unsigned int hash(const char* key) {
    unsigned int sum = 0;
    while (*key) {
        sum += *key++;
    }
    return sum % TABLE_SIZE;
}

//insercao na hash table
void insert(const char* key, float value) {
    unsigned int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = strdup(key); //duplica a string pra armazenar
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

//busca valor pela chave
float search(const char* key) {
    unsigned int index = hash(key);
    Node* current = hashTable[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    //valor especial para indicar "not found"
    return -1.0f;
}

//imprime toda a hash table
void printTable(){
    printf("hash table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        if (current) {
            printf("index %d: ", i);
            while(current) {
                printf("%s $%.2f", current->key, current->value);
                current = current->next;
            }
            printf("\n");
        }
    }
}

int main(){
    //inicializa a tabela com NULLs
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    //insercoes como no python
    insert("apple", 0.67f);
    insert("milk", 1.49f);
    insert("avocado", 2.32f);

    //imprime a tabela
    printTable();

    //busca por "milk"
    float price = search("milk");
    if (price >= 0) {
        printf("\nmilk price: %.2f\n", price);
    } else {
        printf("\n'milk' not found on table\n");
    }

    return 0;
} 