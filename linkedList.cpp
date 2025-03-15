#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int coef;
    int poly;
    Node* next;

    Node(): next(NULL){};
    Node(int c,int p): coef(c), poly(p) ,next(NULL){};
};

class Polynomial{
    public:
    Node* head;

    Polynomial(): head(NULL) {};

    void insert(int c,int p){
        Node* newnode = new Node(c,p);
        if (head == NULL){
            head = newnode;
        }else{
            Node* temp = head;
            while(temp->next !=NULL){
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    void print() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->coef << "x^" << temp->poly;
            if (temp->next != NULL) {
                cout << " + ";
            }
            temp = temp->next;
        }
        cout << endl;
    }


    Polynomial add(Polynomial&node){
        Polynomial result;
        Node *temp1 = head;
        Node *temp2 = node.head;
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->poly == temp2->poly) {
                result.insert(temp1->coef + temp2->coef, temp1->poly);
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp1->poly > temp2->poly) {
                result.insert(temp1->coef, temp1->poly);
                temp1 = temp1->next;
            } else {
                result.insert(temp2->coef, temp2->poly);
                temp2 = temp2->next;
            }
        }
        while (temp1 != NULL) {
            result.insert(temp1->coef, temp1->poly);
            temp1 = temp1->next;
        }
        while (temp2 != NULL) {
            result.insert(temp2->coef, temp2->poly);
            temp2 = temp2->next;
        }
        return result;
    }

    Polynomial multiplication(Polynomial&p) {
        Polynomial result;
        Node *temp1 = head;
        Node *temp2 = p.head;
        while (temp1 != NULL) {
            while (temp2 != NULL) {
                result.insert(temp1->coef * temp2->coef, temp1->poly + temp2->poly);
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
            temp2 = p.head;
        }
        return result;
    }
};


int main(){
    Polynomial p1;
    p1.insert(2, 3);
    p1.insert(3, 2);
    p1.insert(4, 1);
    p1.insert(5, 0);
    p1.print();
    Polynomial p2;
    p2.insert(1, 2);
    p2.insert(2, 1);
    p2.insert(3, 0);
    p2.print();
    Polynomial p3 = p1.add(p2);
    p3.print();
    Polynomial p4 = p1.multiplication(p2);
    p4.print();
    return 0;
}