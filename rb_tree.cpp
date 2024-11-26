#include <bits/stdc++.h>
#define mp std::make_pair
#define pr std::pair<int, int>
#define ll long long
#define NAUP std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)


enum Color { RED, BLACK };

struct Node {
    int data;           // Node value
    Color color;        // Node color (RED or BLACK)
    Node* left;         // left node
    Node* right;        // right node
    Node* parent;       // parent node

    // node constructor
    Node(int data) 
        : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {
            
        }
};

class RedBlackTree {
    private:
        // right rotation
        void right_rotation(){
            
        }
        
        // left rotation
        void left_rotation(){
            
        }
    
    public:
        
}


int main() {
    NAUP;


}