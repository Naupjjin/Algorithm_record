#include <stdio.h>
#include <stdlib.h>



typedef struct Node {
    int value;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = val;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int getHeight(Node* node) {
    return node ? node->height : 0;
}

int getBalanceFactor(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

void updateHeight(Node* node) {
    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    x->right = y;
    y->left = T;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    y->left = x;
    x->right = T;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* balance(Node* node) {
    updateHeight(node);
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1) {
        if (getBalanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }

    if (balanceFactor < -1) {
        if (getBalanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }

    return node;
}

Node* insertNode(Node* node, int value) {
    if (!node) return createNode(value);

    if (value < node->value) {
        node->left = insertNode(node->left, value);
    } else if (value > node->value) {
        node->right = insertNode(node->right, value);
    } else {
        return node;
    }

    return balance(node);
}

Node* findMin(Node* node) {
    while (node->left) node = node->left;
    return node;
}

Node* deleteNode(Node* node, int value) {
    if (!node) return NULL;

    if (value < node->value) {
        node->left = deleteNode(node->left, value);
    } else if (value > node->value) {
        node->right = deleteNode(node->right, value);
    } else {
        if (!node->left || !node->right) {
            Node* temp = node->left ? node->left : node->right;
            free(node);
            return temp;
        } else {
            Node* minNode = findMin(node->right);
            node->value = minNode->value;
            node->right = deleteNode(node->right, minNode->value);
        }
    }

    return balance(node);
}

void printNodeInfo(Node* node) {
    if (!node) return;

    printNodeInfo(node->left);

    char leftValue[20];  
    char rightValue[20]; 

    if (node->left) {
        snprintf(leftValue, sizeof(leftValue), "%d", node->left->value);
    } else {
        snprintf(leftValue, sizeof(leftValue), "NULL");
    }

    if (node->right) {
        snprintf(rightValue, sizeof(rightValue), "%d", node->right->value);
    } else {
        snprintf(rightValue, sizeof(rightValue), "NULL");
    }

    printf("Value: %d, Height: %d, Left: %s, Right: %s\n",
           node->value, node->height, leftValue, rightValue);

    printNodeInfo(node->right);
}


int main() {

    Node* root = NULL;
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 10);
    root = insertNode(root, 25);
    root = insertNode(root, 50);

    printf("------------:\n");
    printNodeInfo(root);

    printf("\n----------------:\n");
    root = deleteNode(root, 20);
    printNodeInfo(root);

    printf("\n---------------:\n");
    root = deleteNode(root, 30);
    printNodeInfo(root);

    return 0;
}
