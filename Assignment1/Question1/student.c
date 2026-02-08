#include "Student.h"
#include <stdio.h>
//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n:
//nums1 has length m + n
//The first m values in nums1 are real elements
//The last n values in nums1 are placeholders (0)
//nums2 has length n
//Goal: Merge nums2 into nums1 so that nums1 becomes one sorted array.
//Return: Nothing (modify nums1 in-place).

//Example:
//Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//Output: nums1 = [1,2,2,3,5,6]
//Explanation: The arrays we are merging are [1,2,3] and [2,5,6].

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

 // TODO: implement
 
    nums1Size = (int)nums1Size;
    nums1Size = (int)nums2Size;
    //printf("%d, %d, %d, %d\n", n, m, nums1Size, nums2Size);
    int rightnums1 = m - 1;
    int rightnums2 = n - 1;

    for(int i = m + n - 1; i > 0; i--){
        if(rightnums1 < 0 || rightnums2 < 0){
            break;
        }
        if(nums1[rightnums1] < nums2[rightnums2]){
            nums1[i] = nums2[rightnums2];
            rightnums2--;
        }else{
            nums1[i] = nums1[rightnums1];
            rightnums1--;
        }
    }

    while(rightnums2 >= 0){
        nums1[rightnums2] = nums2[rightnums2];
        rightnums2--;
    }
}
