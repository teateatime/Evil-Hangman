#ifndef ASSOCIATIVE_ARRAY_H
#define ASSOCIATIVE_ARRAY_H
#include "my_string.h"
#include "generic_vector.h"

typedef void* AVL;

typedef struct node Node;

struct node {
    MY_STRING key;
    GENERIC_VECTOR data;
    Node* right;
    Node* left;
    int height;
};

struct tree {
    Node* root;
};

typedef struct tree Tree;

AVL avl_init_default(void);

int getHeight(AVL pNode);

int getBalance(AVL pNode);

int maximum(int A, int B);

AVL rightRotation(AVL pY);

AVL leftRotation(AVL pX);

AVL avl_insert(AVL pAvl, MY_STRING hKey, MY_STRING hWord);

void preOrder(AVL root);

void avl_destroy(AVL* phAvl);

/*

GENERIC_VECTOR* get_largest_word_list(Tree** t);

void get_largest_word_list_helper(Node* node, Node** temp, int* max);

void swap_vectors(GENERIC_VECTOR* dest, GENERIC_VECTOR* source);

*/

#endif
