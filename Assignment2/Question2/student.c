/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int height_calc(struct TreeNode *root, int max, int min){
    if(root == NULL){
        // By Def.
        return 0;
    }else{
        if(root->val > max || root->val < min){
            return -1;
        }
        int left_height = height_calc(root->left, root->val - 1, min);
        int right_height = height_calc(root->right, max, root->val + 1);

        // Propogate the invalid flag
        if(left_height == -1 || right_height == -1){
            return -1;
        }
        
        // Checking BST requirements
        if(root->left != NULL){

            
            // if(root->left->val > max || root->left->val < min){
            //     return -1;
            // }

            // if(root->right != NULL){
            //     // if(root->right->val > max || root->right->val < min){
            //     //     return -1;
            //     // }


                // Checking Strict BST requirement
                if(root->right != NULL && root->right > root->left){
                    if((root->val == root->left->val) || (root->val == root->right->val)){
                        return -1;
                    }
                }else{
                    return -1;
                }
            // }
        }else{
            if(root->right != NULL){
                return -1;
            }
        }

        if(abs(left_height - right_height) <= 1){
            return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
        }else{
            return -1;
        }
    }
}

bool isAVL(struct TreeNode* root) {
    // TODO: implement
    // Hint: One common O(n) approach:
    // - Use a recursive helper that returns the subtree height,
    //   and returns -1 if subtree is invalid (BST violation or unbalanced).
    // (void)root;

    int height = height_calc(root, INT_MAX, INT_MIN);

    if(height == -1){
        return false;
    }else{
        return true;
    }
    return false;
}
