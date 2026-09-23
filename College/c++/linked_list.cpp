#include <bits/stdc++.h>
using namespace std;
const int N= 1e6+5,MOD=1e9+7,INF=1e18+5;
#define leon ios_base::sync_with_stdio(false); cin.tie(nullptr);
class Node{
    public:
    int data;
    Node* next;
};
class singlelinkedlist{
    public:
    Node* head;
    Node* tail;
    int count = 0;
    singlelinkedlist(){//constructor
        head = NULL;
        tail = NULL;
        count = 0;
    }

    bool isempty() const {//o(1)
        return head == NULL;
    }
    void initializelist(){//O(1)
        head = NULL;
        tail = NULL;
        count = 0;
    }
    int length(){//O(n)
        Node* current = head;//start from head
        count = 0;
        while(current != NULL){//loop till the tail
            count++;
            current = current -> next;//move 
        }
        return count;
    }
    void deletefirst(){//O(1)
        if(isempty()) cout << "the list is empty, nothing to delete" << endl;
        else{
            Node* delptr = head;//to loop on the list
            head = head -> next;//move to the next node
            delete delptr;//delete the current node
        }
    }
    void deletelast(){//O(n)
        if(isempty()) cout << "the list is empty, nothing to delete" << endl;
        else if(head -> next == NULL) deletefirst();//if there is only one node
        else{
            Node* delptr = head;//to loop on the list
            Node* prev = NULL; //before the delptr to link it to the next node after deletion
            while(delptr -> next != NULL){
                prev = delptr ; 
                delptr = delptr -> next;
            }
            prev -> next = NULL;
            delete delptr;
        }
    }
    void destroylist(){//O(N)
        Node* current = head;
        while(current != NULL){
            Node* temp = current;//to loop on the list
            current = current -> next;//move to the next node
            delete temp;//delete the current node
        }
    }
    void insertFirst(int value){//O(1)
        Node* newnode = new Node();
        newnode -> data = value;
        if(isempty()){//here we are playing with pointers 
            newnode -> next = NULL;
            head = newnode;
        }
        else{
            newnode -> next = head;
            head = newnode;
        }
    }
    void insertlast(int value){//O(n)
        Node* newnode = new Node();
        newnode-> data = value;
        newnode -> next = NULL;
        if(isempty()){
            head = newnode;
            tail = newnode;
        }
        else{
            tail -> next = newnode;
            tail = newnode;
        }
    }
    int first() const{//O(1)
        if(isempty()){
            cout << "the list is empty" << endl;
            return -1;
        }
        return head -> data;
    }
    int last() const {//O(1)
        if(isempty()){
            cout << "the list is empty" << endl;
            return -1;
        }
        return tail != NULL ? tail->data : head->data;
    }
    void display(){
        Node* current = head;
        while(current != NULL){
            cout << current -> data << "->";
            current = current -> next;
        }
        cout << "NULL" << endl;
    }
    void displayList(){
        Node* current = head;
        while(current != NULL){
            cout << current -> data << "->";
            current = current -> next;
        }
        cout << "NULL" << endl;
    }
    bool isfound(int Value){//could be virtual if we want to use inheritance
        Node* current = head;//O(n)
        while(current != NULL){
            current = current -> next;
            if(current -> data == Value){
                cout << "Found" << endl;
                return true;                
            }
        }
        cout << "Not found" << endl;
        return false;
    }
    void insertitem(int item){// for sorted linked list XD O(n)
        Node* newnode = new Node();
        Node *current = head;
        Node* prev = NULL;
        bool found;
        newnode -> data = item;
        newnode -> next = NULL;
        if (isempty()){//case one if the list is empty
             head = newnode;//add to the beginning
        }
        else{
            current = head;
            found = false;
            while(current != NULL && !found){//to find the right place to insert the new node
                if (current -> data >= item) found = true;//if we found the right place to insert the new node
                else{
                    prev = current;
                    current = current -> next;
                }
            }
            if (current == head){// case two if the item is smaller than the head
                newnode -> next = head;//add to the beginning
                head = newnode;
            }
            else{ // case three if the item is bigger than the head 
                prev -> next = newnode;//add to the middle or the end
                newnode -> next = current;
            if(current == NULL) newnode -> next = NULL;//add to the end
            }
        }
    }
    void deleteItem(int item){//O(n)
        if(isempty()) cout << "the list is empty, nothing to delete" << endl;
        else {//case one if the item is in the head
             Node* delptr = head;
            if (item == head -> data){
                head = head-> next;
                delete delptr;
            }
            else{//case two if the item is in the middle or the end
                delptr = head;
                Node* prev = NULL; //before the delptr to link it to the next node after deletion
                while (delptr -> data != item){
                    prev = delptr ; //walks before the delptr to link it to the next node after deletion
                    delptr = delptr -> next;

                }
                prev -> next = delptr -> next;//link the previous node to the next node after deletion
                delete delptr;
            }
        }
    }
    void printreverse(Node* current){//O(n) time complexity and O(n) space complexity because of the recursion stack
        if(current == NULL) return;//when happens it means we reached the end of the list and we start printing from the end to the beginning
        printreverse(current -> next);//recursion to reach the end of the list
        cout << current -> data << "->";//starts when the base case is reached and we start printing from the end to the beginning
    }

    void distroylist(){
        Node* current = head;
        while(current != NULL){
            Node* temp = current;//to loop on the list
            current = current -> next;//move to the next node
            delete temp;//delete the current node
        }
    }
    ~singlelinkedlist(){//destructor same as distroylist O(n) time complexity
        Node* current = head;
        while(current != NULL){
            Node* temp = current;//to loop on the list
            current = current -> next;//move to the next node
            delete temp;//delete the current node
        }
    }
    void copylist(const singlelinkedlist& other){//O(n) time complexity 
        if(other.isempty()) head = NULL;
        else{
            Node* current = other.head;
            while(current != NULL){
                insertlast(current -> data);
                current = current -> next;
            }
        }
    }
    void reverseList(){//O(n) time complexity and O(1) space complexity
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(current != NULL){
            next = current -> next;//to save the next node before changing the current node's next pointer
            current -> next = prev;//reverse the current node's next pointer to point to the previous node
            prev = current;//move the previous node to the current node
            current = next;//move the current node to the next node
        }
        head = prev;//after the loop, the previous node will be the new head of the reversed list
    }

};
int main (){
    leon
    
}
//if i use templates :
//i'll write T data but before that i have to write template <typename T> before the class