#include "two_sum.h"

int two_sum(const int* nums, int n, int target, int* out_i, int* out_j) {

    // TODO: implement Two Sum.
    // Requirements:
    //  - find i < j such that nums[i] + nums[j] == target
    //  - store indices in *out_i and *out_j
    //  - return 1 if found; otherwise return 0

    // this is the O(N^2) solution

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] + nums[j] == target){
                *out_i = j;
                *out_j = i;
                return 1;
            }
        }
    }


    return 0;
}

//think about the time complexity and space complexity of your solution
