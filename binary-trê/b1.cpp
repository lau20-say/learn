

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(struct Node* node) {
        if(node == NULL){
            return 0;
        }
        int leftHeight = height(node -> left);
        int rightHeight = height(node -> right);

        return 1 + max(leftHeight, rightHeight);
    }


    
};