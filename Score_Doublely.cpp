#include <iostream>
using namespace std;

struct score{
    string name;
    int point;
};


class Node{
    public:
    score data;
    Node* next;
    Node* prev;

    Node(): next(NULL), prev(NULL){};
    Node(score val) : data(val), next(NULL),prev(NULL){};
};


class LinkedList{
    public: 
    Node* head;
    Node* tail;

    LinkedList(): head(NULL), tail(NULL) {};

    void insert(score val){
        Node* newnode = new Node(val);

        if(head == NULL){
            head = tail = newnode;
            return;
        }
        
        
        if (newnode->data.point > head->data.point) {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
            return;
        }

        
        Node* temp = head;
        while (temp->next != NULL && temp->next->data.point >= newnode->data.point) {
            temp = temp->next;
        }

        newnode->next = temp->next;
        newnode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newnode;
        } else {
            tail = newnode; 
        }

        temp->next = newnode;


        if (isTen()){
            if (tail == head) { 
                delete tail;
                head = tail = NULL;
            } else {
                Node* del = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete del;
            }
        }
    }

    void show(){
        Node* temp = head;
        cout<< "------------------------------" << endl;
        while(temp!= NULL){
            cout<< temp->data.name << " " << temp->data.point <<endl;
            temp = temp->next;
        }
    }

    bool isTen(){
        int count=0;
        Node* temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }

        return count >10;
    }
};




int main(){
    LinkedList node;
    score a[11];

    for(int i=0;i<11;i++){
        cin>> a[i].name >> a[i].point ;
        node.insert(a[i]);
    }

    node.show();    
}