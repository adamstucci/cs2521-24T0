#include <stdlib.h>

struct node {
	int value;
	struct node *left;
	struct node *right;
};

int bstCountInternal(struct node *t) {
    //base case
    if (t == NULL) return 0;
    if (t->left == NULL && t-> right == NULL) return 0;
    
    //recursive case
    return 1 + bstCountInternal(t->left) + bstCountInternal(t->right);

    
}

int bstCountInternal(struct node *t) {
    //base case
    if (t == NULL) return 0;
    if (t->left != NULL || t->right != NULL) {
        return 1 + bstCountInternal(t->left) + bstCountInternal(t->right);
    }
    
    return 0;
    
}

int bstNodeLevel(struct node *t, int key) {
    if (t == NULL) return -1;
    if (t->value == key) return 0;
    if (key < t->value) {
        return 1 + bstNodeLevel(t->left, key);
    }
    else {
        return 1 + bstNodeLevel(t->right, key);
    }
}