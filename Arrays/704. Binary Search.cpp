#include <iostream>
#include <vector>
using namespace std;

// Problem: Binary Search
// Description: Implement binary search to find the target element in a sorted array.
// Approach: Use a two-pointer technique to narrow the search space by halving it.
// Time Complexity: O(log n), where n is the size of the array.
// Space Complexity: O(1), as no additional space is used.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) { // Continue while the search range is valid (non-empty)
            int mid = left + (right - left) / 2; // Prevents potential overflow
            if (nums[mid] == target)
                return mid; // Target found, return the index
            else if (target > nums[mid])
                left = mid + 1; // Search the right half
            else
                right = mid - 1; // Search the left half
        }

        return -1; // Target not found
    }
};

