#include "Student.h"
#include <stdlib.h>

//You are given a large integer represented as an integer array digits, where:

//digits[i] is the i-th digit of the integer
//digits are ordered from most significant to least significant
//there are no leading 0s (except the number 0 itself in some of our tests)
//Goal: Add 1 to the number and return the resulting digits array.

//Example 1:
//Input: digits = [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.
//Incrementing by one gives 4321 + 1 = 4322.
//Thus, the result should be [4,3,2,2].

//Example 2:
//Input: digits = [9]
//Output: [1,0]
//Explanation: The array represents the integer 9.
//Incrementing by one gives 9 + 1 = 10.
//Thus, the result should be [1,0].

//Return value (int*): the output digits array.
//Output parameter (returnSize): set *returnSize to the number of digits in the returned array.

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // TODO: implement

    int carry = 0;
    int exception_flag = 1;
    int stored_digit_size = digitsSize;

    // Cannot do the addition in-place, because of memory freeing issues. So allocating memory here for a duplicate.
    int *output = (int*)malloc((digitsSize + 1) * sizeof(int));

    // One exceptional case: 99999...999 that increases the number size. We check that first.

    for(int i = 0; i < digitsSize; i++){
        if(digits[i] != 9){
            exception_flag = 0;
        }
    }

    if(exception_flag){
        output[0] = 1;
        for(int i = 1; i < digitsSize + 1; i++){
            output[i] = 0;
        }
        *returnSize = digitsSize + 1;
        
        // free(output);
        return output;
    }else{
        // Here we go from right to left (LSD to MSD). A 10 is the only exceptional case. 
        digitsSize--;
        digits[digitsSize] += 1;

        if(digits[digitsSize] == 10){
            digits[digitsSize] = 0;
            carry = 1;
        }
        output[digitsSize] = digits[digitsSize];
        digitsSize--;
        for(int i = digitsSize; i >= 0; i--){
            digits[i] = digits[i] + carry;
            if(digits[i] == 10){
                digits[i] = 0;
                carry = 1;
            }else{
                carry = 0;
            }
            output[i] = digits[i];
        }
        *returnSize = stored_digit_size;
        
        
        // free(output);
        return output;
    }

}

