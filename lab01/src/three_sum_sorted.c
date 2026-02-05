#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    if (!nums || !out_i || !out_j || n < 3) return 0;

    // TODO: implement rwo sum solution for sorted arrays.
    
    
    // We will use two pointers in this case
    for(int abs_pointer = 2; abs_pointer < n; abs_pointer++){

        int target = 0 - nums[abs_pointer];

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
                *out_k = abs_pointer;
                *out_i = left;
                *out_j = right;
                return 1;
            }

            if(current_sum < target){
                right++;
                if(right == abs_pointer){
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
                *out_k = abs_pointer;
                *out_i = i;
                *out_j = right;
                return 1;
            }
            
        }
}

    return 0;

}
