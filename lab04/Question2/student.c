#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#define INF 1000000
/*
Question 2: Symmetric Tree

Given the root of a binary tree, check whether it is symmetric
around its center.

A tree is symmetric if the left subtree is a mirror reflection
of the right subtree.

Examples:

Example 1:
Input:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
Output: true

Example 2:
Input:
        1
       / \
      2   2
       \   \
       3    3
Output: false

Function to complete:
    bool isSymmetric(struct TreeNode* root);

Note:
- An empty tree is considered symmetric.
- You should compare the left subtree and right subtree
  as mirror images.
*/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int left[1000], right[1000];

void flipTree(struct TreeNode* root){
  if(root != NULL){
    flipTree(root->left);
    flipTree(root->right);

    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
  }else{
    return;
  }
}

void flattenTree(int currentIDX, struct TreeNode* root, int *ara){
  if(root == NULL){
    return;
  }else{
    ara[currentIDX] = root->val;
    flattenTree(2 * currentIDX + 1, root->left, ara);
    flattenTree(2 * currentIDX + 2, root->right, ara);
  }
}

void initializer(int *ara){
  for(int i = 0; i < 1000; i++){
    ara[i] = INF;
  }
}

bool isSymmetric(struct TreeNode* root) {
  // TODO: implement
  if(root == NULL){
    return true;
  }
  initializer(left);
  initializer(right);
  flipTree(root->right);
  flattenTree(0, root->left, left);
  flattenTree(0, root->right, right);
  
  for(int i = 0; i < 1000; i++){
    // printf("%d %d ", left[i], right[i]);
    if(left[i] != right[i]){
      return false;
    }
  }
  return true;
}