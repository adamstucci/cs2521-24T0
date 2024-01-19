/**
 * Input: array S[0..n-1]
 * Output: True if S is a palindrome, false otherwise
 * 
 * l = 0 // 1 
 * r = n-1 // 1
 * 
 * //loop runs in worst case (n/2) times
 * while l <= r: //how many times does the loop run???
 *      if S[l] != S[r]: return false //expensive???? ~5 atomic operations O(1)
 *      //loop code
 *      l++ //~3 atomic operations O(1)
 *      r--
 * 
 * return true
*/

//complexity is O(n)

// abc
// bob
// 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(char *str) {
    int l = 0;
    int r = strlen(str) -1;

    while (l <= r) {
        if (str[l] != str[r]) return false;
        
        l++;
        r--;
    }

    return true;

}


int main(int argc, char **argv) {

    if(isPalindrome(argv[1])) {
        printf("%s is a palindrome\n", argv[1]);
    }
    else {
        printf("%s is NOT a palindrome\n", argv[1]);
    }

    return EXIT_SUCCESS;
}