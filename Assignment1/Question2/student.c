#include "Student.h"

//Given an array nums of size n, return the majority element.

//The majority element appears more than ⌊n/2⌋ times.
//You may assume the majority element always exists in the array.

//Example 1:
//Input: nums = [3,2,3]
//Output: 3

//Example 2:
//Input: nums = [2,2,1,1,1,2,2]
//Output: 2


int majorityElement(int* nums, int numsSize) {
     // TODO: implement

     // most probably would not need this failsafe.
     if(numsSize == 0) return -1;


     // Would be interesting to do this with hash tables or random selection. 
     // This solution is posibble because 
     int guess = nums[0];
     int count = 1;

     for(int i = 0; i < numsSize; i++){
          if(guess == nums[i]){
               count++; 
          }else{
               count--;
               if(count < 0){
                    guess = nums[i];
                    count = 0;
               }
          }
     }
     return guess;
}
