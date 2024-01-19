/**
 * Input: array nums[0..n-1], int target
 * Output: True if 2 numbers in array that sum to target, otherwise false
 * 
 * for x in nums[0..n-1]: worst case O(n)
 *    for y in nums[0..n-1]: worst case runs exactly n times O(n)
 *        if x + y == target: return true //~5 prim ops  O(1)
 * 
 * return false
*/

/**
 * Input: array nums[0..n-1], int target
 * Output: True if 2 numbers in array that sum to target, otherwise false
 * 
 * for x in nums[0..n-1]: //O(n)
 *    for y in nums[x+1..n-1]: //O(n)
 *        if x + y == target: return true //O(1)
 * 
 * return false
*/

// 1 + 2 + 3 + 4 +...+ n
// (n(1 + n)) / 2
// (n^2)/2 + n/2