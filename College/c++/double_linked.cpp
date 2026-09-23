#include <bits/stdc++.h>
using namespace std;
const int N= 1e6+5,MOD=1e9+7,INF=1e18+5;
#define leon ios_base::sync_with_stdio(false); cin.tie(nullptr);
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
};
class doublelinkedlist{
    public:
    Node* first;
    Node* last;
    int count = 0;
    doublelinkedlist(){//constructor
        first = NULL;
        last = NULL;
        count = 0;
    }
    bool isempty() const {
        return first == NULL;//no need for the last
    }
    void insertFirst(int value){//O(1)
        Node* newnode = new Node();
        newnode -> data = value;
        if(isempty()){
            newnode -> next = NULL;
            newnode -> prev = NULL;
            first = last = newnode;
        }
        else{
            newnode -> next = first;
            first -> prev = newnode;
            first = newnode;
        }
    }
    void insertlast(int value){//O(1)
        Node* newnode = new Node();
        newnode-> data = value;
        newnode -> next = NULL;
        if(isempty()){
            newnode -> prev = NULL;
            first = last = newnode; 
        }
        else{
            last -> next = newnode;
            newnode -> prev = last;
            last = newnode;
        }
    }
    void deletelast(){
        if(isempty()) cout << "the list is empty nothing to delete" << endl;
        else if(first == last){
            delete first;
            first = last = NULL;
        }
        else{
            Node* temp = last;
            last = last -> prev;
            last -> next = NULL;
            delete temp;
        }   
    }
    void display(){
        Node* current = first;
        while(current != NULL){
            cout << current -> data << "->";
            current = current -> next;
        }
        cout << "NULL" << endl;
    }
    void displayreverse(){
        Node* current = last;
        while(current != NULL){
            cout << current -> data << "->";
            current = current -> prev;
        }
        cout << "NULL" << endl;
    }
    void intsertAfter(int value, int item){//O(n)
        if(isempty()) cout << "the list is empty, nothing to insert after" << endl;
        else {
            Node* newnode = new Node();
            newnode -> data = value;
            Node* current = first;
            while(current != NULL && current -> data != item){
                current = current -> next;
            }
            if(current == NULL) cout << "item not found in the list" << endl;
            else{
                newnode -> next = current -> next;
                newnode -> prev = current;
                if(current -> next != NULL) current -> next -> prev = newnode;
                current -> next = newnode;
                if(current == last) last = newnode;
            }
        }
    }
    void insertBefore(int value, int item){//O(n) the only diff. is the direction of pointers
        if(isempty()) cout << "the list is empty, nothing to insert before" << endl;
        else {
            Node* newnode = new Node();
            newnode -> data = value;
            Node* current = first;
            while(current != NULL && current -> data != item){
                current = current -> next;
            }
            if(current == NULL) cout << "item not found in the list" << endl;
            else{
                newnode -> next = current;
                newnode -> prev = current -> prev;
                if(current -> prev != NULL) current -> prev -> next = newnode;
                current -> prev = newnode;
                if(current == first) first = newnode; //if we are inserting before the first node
            }
        }
    }
    void size(){
        int count = 0;
        Node* current = first;
        while(current != NULL){
            count++;
            current = current -> next;
        }
        cout << "the size of the list is: " << count << endl;

    }
    void reverse(){
        Node* current = first;
        Node* temp = NULL;
        while(current != NULL){
            temp = current -> prev;//to swap the next and prev pointers
            current -> prev = current -> next;
            current -> next = temp;
            current = current -> prev;//move to the next node which is the previous node before swapping
        }
        if(temp != NULL) first = temp -> prev;//to update the first pointer after reversing


    }

};
//making a stack from a double linked list
class stack{
    public:
    doublelinkedlist l;
    void push(int value){
        l.insertFirst(value);
    }
    void pop(){
        if(l.isempty()) cout << "the stack is empty nothing to pop" << endl;//case1: empty stack
        else{
            Node* temp = l.first;
            l.first = l.first -> next;
            if(l.first != NULL) l.first -> prev = NULL;//if the stack is not empty after popping
            else l.last = NULL;//if the stack becomes empty after popping
            delete temp;
        }
    }

    void displayreverse(){
        l.displayreverse();
    }   
    void top(){
        if(l.isempty()) cout << "the stack is empty no top element" <<endl;
        else cout << l.first -> data << endl;
    }

};
class queue{
    public:
    doublelinkedlist l;
    void enqueue(int value){
        l.insertlast(value);
    }
    void dequeue(){
        if(l.isempty()) cout << "the queue is empty nothong to dequeue" << endl;//case1: empty queue
        else{
            Node* temp = l.first;
            l.first = l.first -> next;
            if(l.first != NULL) l.first -> prev = NULL;
            else l.last = NULL;
            delete temp;
        }
    }
    void display(){
        l.display();
    }
};
//circular queue using double linked list
class circularqueue{
    public:
    doublelinkedlist l;
    void enqueue(int value){
        l.insertlast(value);
        if(l.first != NULL) l.last -> next = l.first;
    }
    void dequeue(){
        if(l.isempty()) cout << "the queue is empty nothong to dequeue" << endl;//case1: empty queue
        else{
            Node* temp = l.first;
            l.first = l.first -> next;
            if(l.first != NULL) {
                l.first -> prev = NULL;
                l.last -> next = l.first;//stay circular
            }
            else l.last = NULL;
            delete temp;
        }
    }
    void display(){
        if(l.isempty()) cout << "the queue is empty nothing to display" << endl;
        else{
            Node* current = l.first;
            while (current != l.last) {
                cout << current -> data << "->";
                current = current -> next;
            }
            cout << "NULL" << endl;
        }
    }
};
int main (){
    leon

     doublelinkedlist l;
        l.insertFirst(5);
        l.insertFirst(10);
        l.insertFirst(15);
        l.insertlast(88);
        l.display();
            l.displayreverse();
            l.intsertAfter(20, 10);
            l.display();
            l.insertBefore(25, 88);
            l.display();
     return 0;
}