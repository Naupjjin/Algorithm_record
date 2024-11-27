#include <iostream>
#define NAUP std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)

struct Node{
    int value; // data
    Node* Left; // Leaf left or right pointer
    Node* Right; 
    Node* Parent; // parent pointer
    int height; // node height on AVL tree

    // constructor
    Node(int val) : value(val), Left(nullptr), Right(nullptr), Parent(nullptr), height(0) {}
};

class AVLtree{
private:
    Node* root;

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
        
    }
    
    void DeleteNode(){
        
    }
    
    Node* SearchNode(){
        return root;
    }

};

int main() {
    NAUP;
    AVLtree tree;

    return 0;
}
