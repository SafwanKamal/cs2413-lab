#include "two_sum_sorted.h"
#include <stdio.h>

int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (!nums || !out_i || !out_j || n < 2) return 0;

    // TODO: implement rwo sum solution for sorted arrays.
    
    
    // We will use two pointers in this case

    int right = 1, left = 0;
    int current_sum = nums[right] + nums[left];

    // if(n < 2){
    //     // We cannot use the same entries twice. So, if arr size is 1 or 0, return 0.
    //     return 0;
    // }

    while (left < right)
    {
        current_sum = nums[right] + nums[left];

        if(current_sum == target){
            *out_i = left;
            *out_j = right;
            return 1;
        }

        if(current_sum < target){
            right++;
            if(right == n){
                right--;
                break;
            }
        }

        if(current_sum > target){
            right--;
            left++;
            if(right < left){
                break;
            }
            // while(current_sum > target){
            //     left++;
            //     current_sum = nums[right] + nums[left];
            // }
        }
    }
    // If the right pointer reaches the end of the array, we go through till the penultimate index with the left pointer
    for(int i = left; i < right; i++){
        current_sum = nums[right] + nums[i];
        if (current_sum == target)
        {
            *out_i = i;
            *out_j = right;
            return 1;
        }
        
    }

    return 0;
}
// think about the time complexity and space complexity of your solution

