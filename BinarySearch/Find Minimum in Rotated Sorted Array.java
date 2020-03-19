/**
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0

*/

class Solution {
    public int findMin(int[] nums) {
        int start = 0, end = nums.length-1;
	// loop invariant: 1. low < high
        //                 2. mid != high and thus A[mid] != A[high] (no duplicate exists)
        //                 3. minimum is between [low, high]
        // The proof that the loop will exit: after each iteration either the 'high' decreases
        // or the 'low' increases, so the interval [low, high] will always shrink.
        while(start < end) {
            int mid = start + (end-start)/2;
            if(nums[mid] < nums[end])// the mininum is in the left part
                end = mid;
            else
                start = mid+1;
        }
        return nums[start];
    }
}