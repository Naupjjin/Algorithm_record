#include <bits/stdc++.h>
#define mp std::make_pair
#define pr std::pair<int, int>
#define ll long long
#define NAUP std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)

struct Trie_node {
    bool isEndOfWord;
    int IDX;
    Trie_node* children[26];
    Trie_node() {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }

    ~Trie_node() {
        for (int i = 0; i < 26; ++i) {
            delete children[i];
        }
    }
};

struct Trie {
    Trie_node* root;

    Trie() {
        root = new Trie_node();
    }


    ~Trie() {
        delete root;
    }

    void node_insert(std::string& word, int idx) {
        Trie_node* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new Trie_node();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
        node->IDX = idx;
    }

    std::pair<bool, int> search(std::string& word) {
        Trie_node* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return {false, -1};
            }
            node = node->children[index];
        }
        return {node->isEndOfWord, node->IDX};
    }
};

int main() {
    int N;
    char words[101];  
    
    while (scanf("%d", &N) != EOF) {
        Trie* trie = new Trie();  
        int cnt = 1;
        
        for (int i = 0; i < N; i++) {
            scanf("%s", words);  
            std::string word(words);  
            std::pair<bool, int> ret_v = trie->search(word);
            
            if (ret_v.first == 0) {
                trie->node_insert(word, cnt);
                printf("New! %d\n", cnt);  
                cnt++;
            }
            else {
                printf("Old! %d\n", ret_v.second); 
            }
        }
        delete trie;  
    }
}