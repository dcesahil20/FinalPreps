#include <iostream>
using namespace std;



class Node{
    public:
        int data;
        Node* next;

    Node(int x){
        this->data = x;
        this->next = NULL;
    }
};

Node *takeInput(){

    int data;
    cin >> data;

    //take input jabtk -1 ni input hojata user se

    Node *head = NULL;

    while(data!=-1){
        
        Node* newNode = new Node(data);

        if(head==NULL){
            head = newNode;
        }

        else{
            Node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cin >> data;
    }

    return head;


}


void printLL(Node* head){
    while(head!=NULL){
        cout << head->data << "--> ";
        head = head->next;
    }
}


int main(){

    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    printLL(a);

    Node *head = takeInput();
    printLL(head);
    
}