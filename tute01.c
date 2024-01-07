#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct list {
	struct node *head;
};

int listLengthIterative(struct node *l) {
    struct node *curr = l;
    int len = 0;

    while (curr != NULL) {
        len++;
        curr = curr->next;
    } 

    return len;
}

int listLengthRec(struct node *l) {
    //base case
    if (l == NULL) return 0;

    //recursive case
    return 1 + listLengthRec(l->next);
}

int listCountOdds(struct node *l) {
    //base case
    if (l == NULL) return 0;

    //recursive case
    if (l->val % 2 == 1) return 1 + listCountOdds(l->next);
    else return listCountOdds(l->next);
}

struct node *listDelete(struct node *l, int value) {
    //base case
    if (l == NULL) return NULL;
    
    if (l->val == value) {
        struct node *tmp = l->next;
        free(l);
        return tmp;
    }

    //recursive case
    struct node *newTailHead = listDelete(l->next, value);
    l->next = newTailHead;
    return l;
}


int listIsSorted(struct node *l) {
    //base cases
    if (l == NULL) return 1;
    if (l->next == NULL) return 1;

    //recursive case
    int tailSorted = listIsSorted(l->next);
    
    if (!tailSorted) {
        return 0;
    }
    else if (l->val <= l->next->val) {
        return 1;
    }
    else {
        return 0;
    }
}

int listLength2(struct list *l) {
    //error case
    // if (l == NULL) 
    
    return listLengthHelper(l->head);
}

int listLengthHelper(struct node *curr) {
    if (curr == NULL) return 0;

    return 1 + listLengthHelper(curr->next);
}

//[1, 7, 8, 10]
    //Head:Tail
    //Head = 1
    //Tail = [7, 8, 10]
    //int tailLen = listLengthRec(l->next);
    //return 1 + tailLen;

//[1, 2, 3]
//f([1,2,3]) -> 1 + 2 = 3
    //f([2, 3]) -> 1 + 1 = 2
        //f([3]) -> 1
int main (void) {
    struct node *head = malloc(sizeof (struct node));
    head->val = 1;
    head->next = malloc(sizeof (struct node));
    head->next->val = 2;
    head->next->next = malloc(sizeof (struct node));
    head->next->next->val = 3;
    head->next->next->next = NULL;


    //DO SOME WORK
    printf("%d\n", listLengthIterative(head));
    printf("%d\n", listLengthRec(head));

    printf("%d\n", listCountOdds(head));

    head = listDelete(head, 1);
    printf("%d\n", head->val);

    //FREE ALLOCATIONS

    return EXIT_SUCCESS;
}