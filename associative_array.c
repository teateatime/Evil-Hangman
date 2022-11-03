#include <stdio.h>
#include <stdlib.h>
#include "associative_array.h"

AVL avl_init_default(void) {
    Node* pAvl;
    pAvl = (Node*)malloc(sizeof(Node*));

    if (pAvl) {
        pAvl->key = NULL;
        pAvl->data = generic_vector_init_default(my_string_assignment, my_string_destroy);
        pAvl->height = 1;
        pAvl->right = NULL;
        pAvl->left = NULL;
    }

    return (AVL)pAvl;
}

int getHeight(AVL pNode) { 
    Node* ppNode = (Node*)pNode;
    if (ppNode == NULL) {
        return 0;
    }
    return ppNode->height;
}

int getBalance(AVL pNode) {
    Node* ppNode = (Node*)pNode;
    if (!ppNode) {
        return 0;
    }
    return getHeight(ppNode->left) - getHeight(ppNode->right);
}

int maximum(int A, int B) {

    if (A > B) {
        return A;
    }
    return B;
}

AVL rightRotation(AVL pY) {
    Node* pY2 = (Node*)pY;
    Node *pX = pY2->left;
    Node* T2 = pX->right;

    pX->right = pY;
    pY2->left = T2;

    pY2->height = maximum(getHeight(pY2->left), getHeight(pY2->right)) + 1;
    pX->height = maximum(getHeight(pX->left), getHeight(pX->right)) + 1;

    return pX;
}

AVL leftRotation(AVL pX) {
    Node* pX2 = (Node*)pX;
    Node* pY = pX2->right;
    Node* T2 = pY->left;

    pY->left = pX;
    pX2->right = T2;

    pX2->height = maximum(getHeight(pX2->left), getHeight(pX2->right)) + 1;
    pY->height = maximum(getHeight(pY->left), getHeight(pY->right)) + 1;

    return pY;
}

AVL avl_insert(AVL pAvl, MY_STRING hKey, MY_STRING hWord) {
    Node* ppAvl = (Node*)pAvl;
    if (ppAvl == NULL) {
        Node* pNew = (Node*)malloc(sizeof(Node)); // create avl init default // root

        if (pNew == NULL) {
            printf("Allocation failed\n");
            exit(1);
        }

        MY_STRING copy = my_string_init_c_string(my_string_c_str(hWord));
        //(MY_STRING*)my_string_assignment((Item*)&hWord, (Item*)hKey);
          
        pNew->key = copy; // Need to fix // Copy of key that is an independent object
        pNew->data = generic_vector_init_default(my_string_assignment, my_string_destroy);
        pNew->height = 1;
        pNew->right = NULL;
        pNew->left = NULL;
        ppAvl = pNew;

        generic_vector_push_back(pNew, hKey);

        return pNew;
    }

    if (my_string_compare(hKey, &ppAvl->key) > 0) {
        ppAvl->left = avl_insert(&ppAvl->left, hKey, hWord);
    }
    else if (my_string_compare(&ppAvl->key, hKey) < 0) {
        ppAvl->right = avl_insert(&ppAvl->right, hKey, hWord);
    }
    else if (my_string_compare(&ppAvl->key, hKey) == 0) {
        generic_vector_push_back(ppAvl, hKey);
        return ppAvl;
    }
    else {
        return ppAvl;
    }

    ppAvl->height = 1 + maximum(getHeight(ppAvl->left), getHeight(ppAvl->right));

    int balance = getBalance(ppAvl);

    if (balance > 1 && hKey < ppAvl->left->key) {
        return rightRotation(ppAvl);
    }

    if (balance < -1 && hKey > ppAvl->right->key) {
        return leftRotation(ppAvl);
    }

    if (balance > 1 && hKey > ppAvl->left->key) {
        ppAvl->left = leftRotation(ppAvl->left);
        return rightRotation(ppAvl);
    }

    if (balance < -1 && hKey < ppAvl->right->key) {
        ppAvl->right = rightRotation(ppAvl->right);
        return leftRotation(ppAvl);
    }

    return ppAvl;
}

void preOrder(AVL root) {
    Node* pRoot = (Node*)root;
    if (pRoot != NULL) {
        preOrder(pRoot->left);
        preOrder(pRoot->right);
    }
}

void avl_destroy(AVL* phAvl) { // Dont think its complete
    Node* pAvl = (Node*)*phAvl;

    free(pAvl->left);
    free(pAvl->right);
    free(pAvl);
    *phAvl = NULL;
}

