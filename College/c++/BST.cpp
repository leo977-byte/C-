#include <bits/stdc++.h>
using namespace std;
const int N= 1e6+5,MOD=1e9+7,INF=1e18+5;
#define leon ios_base::sync_with_stdio(false); cin.tie(nullptr);
class Node{
    public:
    int data;
    Node* left;
    Node* right;

};
class BinarySearchTree{
    public:
    Node* root;    
    Node* left;
    Node* right;

    int cnt = 0;
    BinarySearchTree(){
        root = NULL;
    }
    void insert(int value){
        Node* newNode = new Node();
        newNode -> data = value;
        newNode -> left = NULL;
        newNode -> right = NULL;

        if(root == NULL) {
            root = newNode;  
            cnt ++;
        }
        else{
            Node* current = root;
            while(true){
                if(value < current -> data){
                    if(current -> left == NULL){
                        current -> left = newNode;
                        cnt ++;
                        break;
                    }
                    else current = current -> left;
                }
                else{
                    if(current -> right == NULL){
                        current -> right = newNode;
                        cnt ++;
                        break;
                    }
                    else current = current -> right;
                }
            }
        }

    }
    void height (Node* node, int& h){//h is passed by reference to keep track of the height as we traverse the tree
        if(node == NULL) return;
        h++;//increment height for each level of the tree
        height(node -> left, h);//recursively calculate the height of the left and right subtrees
        height(node -> right, h);
    }
    void inorder(Node* node){
        if(node == NULL) return;
        inorder(node -> left);
        cout << node -> data << " ";
        inorder(node -> right);
    }
    void preorder(Node* node){
        if(node == NULL) return;
        cout << node -> data << " ";
        preorder(node -> left);
        preorder(node -> right);
    }
    void postorder(Node* node){
        if(node == NULL) return;
        postorder(node -> left);
        postorder(node -> right);
        cout << node -> data << " ";
    }
    void BFS(Node* node){
        if(node == NULL) return;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* current = q.front();
            q.pop();
            cout << current -> data << " ";
            if(current -> left != NULL) q.push(current -> left);
            if(current -> right != NULL) q.push(current -> right);
        }
    }
};















