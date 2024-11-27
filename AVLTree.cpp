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
    
};

int main() {
    NAUP;
    

    return 0;
}
