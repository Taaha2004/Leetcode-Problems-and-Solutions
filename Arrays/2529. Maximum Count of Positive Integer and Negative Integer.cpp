#include <iostream>
#include <vector>
using namespace std;
/*
    Problem: Find the maximum count of either positive or negative numbers in a sorted array.

    Approaches:
    1. Linear Approach (O(n)):
       - Traverse the array once and count the number of positive and negative numbers.
       - Return the maximum of the two counts.
       - While simple, this approach is less efficient for larger arrays.

    2. Binary Search Approach (O(log n)):
       - Since the array is sorted, we can use binary search to:
         a. Find the index of the last negative number.
         b. Find the index of the first positive number.
       - Using these indices, calculate the counts of negatives and positives.
       - Return the maximum of the two counts.

    Time Complexity:
    - Binary Search Approach: O(log n) as we perform two independent binary searches.

    Space Complexity:
    - Binary Search Approach: O(1) since no additional data structures are used.

    */

class Solution {
public:
    
    int maximumCount(vector<int>& nums) {
        // Edge case: If the first element is positive, the array has no negative numbers.
        // If the last element is negative, the array has no positive numbers.
        // In both cases, the maximum count is the size of the array.
        if (nums[0] > 0 || nums[nums.size() - 1] < 0) 
            return nums.size();

        // Binary search approach to find counts of negatives and positives.
        int left = 0, right = nums.size() - 1;
        int last_neg = -1; // Initialize the index of the last negative number as -1 (none found yet).

        // Binary search to find the last negative number
        while (left <= right) {
            int mid = left + (right - left) / 2; // Avoid overflow when calculating mid
            if (nums[mid] < 0) {
                last_neg = mid; // Update last negative index
                left = mid + 1; // Search the right half for more negatives
            } else {
                right = mid - 1; // Search the left half for negatives
            }
        }

        left = 0, right = nums.size() - 1;
        int first_pos = nums.size(); // Initialize the index of the first positive number as out of bounds.

        // Binary search to find the first positive number
        while (left <= right) {
            int mid = left + (right - left) / 2; // Avoid overflow when calculating mid
            if (nums[mid] > 0) {
                first_pos = mid; // Update first positive index
                right = mid - 1; // Search the left half for smaller positives
            } else {
                left = mid + 1; // Search the right half for positives
            }
        }

        // Calculate counts of negatives and positives
        int neg_count = last_neg + 1; // Count of negative numbers
        int pos_count = nums.size() - first_pos; // Count of positive numbers

        // Return the maximum of the two counts
        return max(neg_count, pos_count);
    }
};
