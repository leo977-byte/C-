#include <bits/stdc++.h>
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    int height;
    int level;
};
class AVL {
    public:
    Node* root;
    AVL() {
        root = NULL;
    }

    int height(Node* node) {
        if(node == NULL) return 0;
        return node -> height;
    }

    int getBalance(Node* node) {
        if(node == NULL) return 0;
        return height(node -> left) - height(node -> right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y -> left;
        Node* T2 = x -> right;

        x -> right = y;
        y -> left = T2;

        y -> height = 1 + max(height(y -> left), height(y -> right));
        x -> height = 1 + max(height(x -> left), height(x -> right));

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x -> right;
        Node* T2 = y -> left;

        y -> left = x;
        x -> right = T2;

        x -> height = 1 + max(height(x -> left), height(x -> right));
        y -> height = 1 + max(height(y -> left), height(y -> right));

        return y;
    }

    Node* insert(Node* node, int key) {
        if(node == NULL) {
            Node* newnode = new Node();
            newnode -> data = key;
            newnode -> left = NULL;
            newnode -> right = NULL;
            newnode -> height = 0; 
            return newnode;
        }
        if(key < node->data)
            node->left = insert(node->left, key);
        else if(key > node->data)
            node->right = insert(node->right, key);
        else 
            return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && key < node->left->data)
            return rightRotate(node);

        if (balance < -1 && key > node->right->data)
            return leftRotate(node);

        if (balance > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void calculatelevel(Node* node, int currentlevel) {
        if(node == NULL) return;
        node -> level = currentlevel;
        calculatelevel(node -> left, currentlevel + 1);
        calculatelevel(node -> right, currentlevel + 1);
    }

    int calculateheight(Node* node) {
        if(node == NULL) return 0;
        node -> height = 1 + max(calculateheight(node -> left), calculateheight(node -> right));
        return node -> height;  
    }

            // Finds the Successor (go right once in the delete function and then keep going left)
        Node* minValueNode(Node* node) {
            Node* current = node;
            while (current && current->left != NULL) {
                current = current->left;
            }
            return current;
        }

        // Finds the Predecessor (go left once in the delete function and then keep going right)
        Node* maxValueNode(Node* node) {
            Node* current = node;
            while (current && current->right != NULL) {
                current = current->right;
            }
            return current;
        }

    Node* deleteNode(Node* node, int key) {
        if(node == NULL) return node;
        if(key < node -> data)
            node -> left = deleteNode(node -> left, key);
        else if(key > node -> data)
            node -> right = deleteNode(node -> right, key);
        else {
            if(node -> left == NULL || node -> right == NULL) {//case1: node with only one child or no child
                Node* child = node -> left ? node -> left : node -> right;
                if(child == NULL) {//case2: no child
                    child = node;
                    node = NULL;
                }
                else {//case3: one child we want to replace the node with its child
                    Node* del = node;//we want to delete the current node after replacing it with its child
                    node = child; //replace the current node with its child
                    child = del;//we want to delete the current node after replacing it with its child
                }
                delete child;
            }
            else {//case4: node with two children we want to replace the node with its inorder successor which is the smallest node in the right subtree
                Node* child = minValueNode(node -> right);
                node -> data = child -> data;
                node -> right = deleteNode(node -> right, child -> data);
            }
        }
        if(node == NULL) return node;

        node -> height = 1 + max(height(node -> left), height(node -> right));
        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0)
            return rightRotate(node);

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0)
            return leftRotate(node);

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
};