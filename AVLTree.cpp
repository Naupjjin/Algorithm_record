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

    void _Right_rotation(){
        
    }

    void _Left_rotation(){
        
    }
    
    void _cal_Balance_Factor(){
        
    }
    
    void getBalanceFactor(){
        
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

};

int main() {
    NAUP;
    AVLtree tree;
    
    tree.InsertNode(2);
    tree.InsertNode(5);
    tree.InsertNode(4);
    tree.InsertNode(15);
    tree.InsertNode(7);
    tree.printInOrder();

    return 0;
}
