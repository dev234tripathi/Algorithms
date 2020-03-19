/**
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

int search(vector<int>& nums, int target) {
      int l = 0, r = nums.size()-1;
    while (l<=r) {
        int mid = (r-l)/2+l;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < nums[r]) {
            if (nums[mid]<target && target<=nums[r])
                l = mid+1;
            else
                r = mid-1;
        } else {
            if(nums[l]<=target && target<nums[mid])
                r = mid-1;
            else
                l = mid+1;
        }
    }
    return -1;
    }