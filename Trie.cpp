#include <bits/stdc++.h>
#define mp std::make_pair
#define pr std::pair<int, int>
#define ll long long
#define NAUP std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)

struct Trie_node {
    bool isEndOfWord;
    Trie_node* children[26];

    // Constructor
    Trie_node() {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

struct Trie {
    Trie_node* root;

    Trie() {
        root = new Trie_node();
    }

    void node_insert(std::string& word) {
        Trie_node* node = root;
        for (char c : word) {
            // Calculate the alphabet index
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                // Append new node to the current node
                node->children[index] = new Trie_node();
            }
            // Move to the next node
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool search(std::string& word) {
        Trie_node* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return node->isEndOfWord;
    }
};

int main() {
    NAUP;

    std::string words1 = "hello";
    std::string words2 = "hell";
    Trie trie;

    trie.node_insert(words1);
    std::cout << "Search 'hello': " << trie.search(words1) << std::endl;
    std::cout << "Search 'hell': " << trie.search(words2) << std::endl;
}
