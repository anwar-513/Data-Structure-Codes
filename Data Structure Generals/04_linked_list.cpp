#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

void display(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data<<" "<<temp->next << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
};

int main()
{
    node* head = new node{10, nullptr};
    head->next = new node{20, nullptr};
    head->next->next = new node{30, nullptr};

    display(head);

    while (head != nullptr) {
        node* next = head->next;
        delete head;
        head = next;
    }

    return 0;
}