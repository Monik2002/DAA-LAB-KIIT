/*Huffman coding assigns variable length codewords to fixed length input
characters based on their frequencies or probabilities of occurrence. Given a set of characters
along with their frequency of occurrences,write a c program to construct a Huffman tree.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for symbols
struct SYMBOL {
    char alphabet;
    int frequency;
    struct SYMBOL* left;
    struct SYMBOL* right;
};

// Define a structure for a Min-Priority Queue Node
struct MinPriorityQueueNode {
    struct SYMBOL* symbol;
    struct MinPriorityQueueNode* next;
};

// Function to create a new Min-Priority Queue Node
struct MinPriorityQueueNode* createNode(struct SYMBOL* symbol) {
    struct MinPriorityQueueNode* node = (struct MinPriorityQueueNode*)malloc(sizeof(struct MinPriorityQueueNode));
    node->symbol = symbol;
    node->next = NULL;
    return node;
}

// Function to merge two nodes into a single node
struct MinPriorityQueueNode* mergeNodes(struct MinPriorityQueueNode* left, struct MinPriorityQueueNode* right) {
    struct SYMBOL* mergedSymbol = (struct SYMBOL*)malloc(sizeof(struct SYMBOL));
    mergedSymbol->alphabet = '\0'; // Not a valid character
    mergedSymbol->frequency = left->symbol->frequency + right->symbol->frequency;
    mergedSymbol->left = left->symbol;
    mergedSymbol->right = right->symbol;

    struct MinPriorityQueueNode* mergedNode = createNode(mergedSymbol);
    return mergedNode;
}

// Function to insert a node into the Min-Priority Queue
void insert(struct MinPriorityQueueNode** queue, struct MinPriorityQueueNode* newNode) {
    if (*queue == NULL || newNode->symbol->frequency < (*queue)->symbol->frequency) {
        newNode->next = *queue;
        *queue = newNode;
    } else {
        struct MinPriorityQueueNode* current = *queue;
        while (current->next != NULL && newNode->symbol->frequency >= current->next->symbol->frequency) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to build the Huffman tree
struct SYMBOL* buildHuffmanTree(struct SYMBOL* symbols[], int numSymbols) {
    struct MinPriorityQueueNode* queue = NULL;

    for (int i = 0; i < numSymbols; i++) {
        insert(&queue, createNode(symbols[i]));
    }

    while (queue != NULL && queue->next != NULL) {
        struct MinPriorityQueueNode* left = queue;
        struct MinPriorityQueueNode* right = queue->next;
        queue = queue->next->next;

        struct MinPriorityQueueNode* mergedNode = mergeNodes(left, right);
        insert(&queue, mergedNode);
    }

    return queue->symbol;
}

// Function to perform in-order traversal of the Huffman tree
void inorderTraversal(struct SYMBOL* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        if (root->alphabet != '\0') {
            printf("%c ", root->alphabet);
        }
        inorderTraversal(root->right);
    }
}


int main() {
    int numSymbols;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &numSymbols);

    struct SYMBOL* symbols[numSymbols];

    printf("Enter the alphabets: ");
    for (int i = 0; i < numSymbols; i++) {
        symbols[i] = (struct SYMBOL*)malloc(sizeof(struct SYMBOL));
        scanf(" %c", &symbols[i]->alphabet);
    }

    printf("Enter their frequencies: ");
    for (int i = 0; i < numSymbols; i++) {
        scanf("%d", &symbols[i]->frequency);
        symbols[i]->left = NULL;
        symbols[i]->right = NULL;
    }

    struct SYMBOL* root = buildHuffmanTree(symbols, numSymbols);

    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
