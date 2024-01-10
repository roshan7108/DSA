#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
    ~Node(){
        int value = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory free for node with data"<<value<<endl;
    }

};

void Print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getLen(Node* &head){
    Node* temp = head;
    int len=0;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtBegin(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}
void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}
void insertAtPosition(Node* &tail, Node* &head, int position, int d){
    if(position == 1){
        insertAtBegin(head,d);
        return;
    }
    Node* temp = head;
    int cnt=1;

    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }
    Node* NodeToInsert = new Node(d);
    NodeToInsert -> next = temp -> next;
    temp -> next -> prev = NodeToInsert;
    temp -> next = NodeToInsert;
    NodeToInsert -> prev = temp;
}

void deleteNode(int position, Node* &head){
    // Deleting 1st node
    if(position ==1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        // Deletinf any middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt<position){
            prev = curr;
            curr = curr ->next;
            cnt++;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    Print(head);
    insertAtBegin(head,12);
    Print(head);
    insertAtTail(tail,15);
    Print(head);
    // cout<<"head Element "<<head->data<<endl;
    // cout<<"Tail element "<<tail->data<<endl;

    insertAtPosition(tail ,head ,1 ,20);
    Print(head);
    insertAtPosition(tail ,head ,3 ,30);
    Print(head);

    deleteNode(3,head);
    Print(head);
    cout<<"length of linked list is "<<getLen(head)<<endl;
    
    return 0;
}