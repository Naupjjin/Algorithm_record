#include <iostream>
#define NAUP std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)

struct Node{
    int data; // data
    Node* left; // Leaf left or right pointer
    Node* right; 
    Node* parent; // parent pointer
    int height; // node height on AVL tree

    // constructor
    Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr), height(0) {}
};

class AVLtree{
private:
    Node* root;

    // inorder traversal
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
    
    // Preorder traversal
    void preorder(Node* node) {
        if (node == nullptr) return;
        std::cout << node->data << " "; 
        preorder(node->left);          // Traverse left subtree
        preorder(node->right);         // Traverse right subtree
    }

    void _getRightRotation(){
        
    }

    void _getLeftRotation(){
        
    }
    
    void _getBalanceFactor(){
        
    }

public:
    
    void InsertNode(int value){
        Node* w_insert_node = new Node(value);
        if(root == nullptr){
            root = w_insert_node;
            return;
        }
        else{
            
            Node* current = root;
            Node* parent = nullptr;
            
            // find want to Insert Node's parent
            while(current != nullptr){
                parent = current;
                if(value < parent->data){
                    current = current->left;
                }
                else{
                    current = current->right;
                }
            }
            
            // Insert Node
            if(value < parent->data){
                parent->left = w_insert_node;
            } 
            else{
                parent->right = w_insert_node;
                
            }
            
            
        }
        
    }
    
    void DeleteNode(){
        
    }
    
    Node* SearchNode(){
        return root;
    }
    
    void printInOrder() {
        inorder(root);
    }
    
    void printPreOrder() {
        preorder(root);
    }

};

int main() {
    NAUP;
    AVLtree tree;
    
    tree.InsertNode(0);
    tree.InsertNode(2);
    tree.InsertNode(4);
    tree.InsertNode(1);
    tree.InsertNode(3);
    tree.printPreOrder();

    return 0;
}
