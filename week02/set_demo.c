#include <stdio.h>
#include <stdlib.h>

#include "set.h"

int numOddOccurences(int arr[], int size) {
    Set set = SetNew();

    for (int i = 0; i < size; i++) {
        if (SetContains(set, arr[i])) {
            SetDelete(set, arr[i]);
        }
        else {
            SetInsert(set, arr[i]);
        }
    }

    int occ = SetSize(set);
    SetFree(set);
    return occ;
}

int numSingleOccurence(int arr[], int size) {
    Set singleSet = SetNew();
    Set multiplesSet = SetNew();

    for (int i = 0; i < size; i++) {
        if (!SetContains(multiplesSet, arr[i])) {
            if (SetContains(singleSet, arr[i])) {
                SetDelete(singleSet, arr[i]);
                SetInsert(multiplesSet, arr[i]);
            }
            else {
                SetInsert(singleSet, arr[i]);
            }
        }
    }

    int occ = SetSize(singleSet);
    SetFree(singleSet);
    SetFree(multiplesSet);
    return occ;
}

int main(void) {
    Set set = SetNew();

    SetInsert(set, 5);
    SetContains(set, 4);
    SetContains(set, 5);
}