// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen
#include <stdio.h>

bool isValid(const char *s) {
    // TODO: Implement using a stack.
    //

    char stack[100000]; 
    int s_len = strlen(s);
    // printf("s_len: %d\n", s_len);
    int stack_pointer = 0;


    for(int i = 0; i < s_len; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            stack[stack_pointer] = s[i];
            stack_pointer++;
        }else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if(stack_pointer == 0){
                return false;
            }
            if(stack[stack_pointer - 1] != '(' && s[i] == ')'){
                return false;
            }
            if(stack[stack_pointer - 1] != '{' && s[i] == '}'){
                return false;
            }
            if(stack[stack_pointer - 1] != '[' && s[i] == ']'){
                return false;
            }
            stack_pointer--;
        }else{
            // Ignore
        }

    }

    if(stack_pointer == 0){
        return true;
    }else{
        return false;
    }
    // Recommended approach:
    // - Use a char array as a stack to store opening brackets.
    // - Scan the string from left to right:
    //   - If you see an opening bracket, push it.
    //   - If you see a closing bracket:
    //       * stack must not be empty
    //       * top of stack must match the closing bracket type
    //       * then pop
    // - At the end, stack must be empty.
    //
    // Helpful matching pairs:
    //   ')' matches '('
    //   ']' matches '['
    //   '}' matches '{'
    //
    // Corner cases:
    // - s == NULL -> return false
    // - odd length strings can’t be valid 
    //
    // Note:
    // - Input contains only bracket characters, per the prompt.

    (void)s; // remove after implementing
    return false; // placeholder
}
