#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

void display(node* head, int& counter, int& sum) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        counter++;
        sum += temp->data;
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void displayRecursive(node* head) {
    if (head == nullptr) {
        cout << "NULL" << endl;
        return;
    }
    cout << head->data << " -> ";
    displayRecursive(head->next);
}

int main()
{
    node* head = new node{10, nullptr};
    head->next = new node{20, nullptr};
    head->next->next = new node{30, nullptr};

    int counter = 0;
    int sum = 0;

    cout << "\nDisplay" << endl;
    display(head, counter, sum);
    cout << "\nRecursive Display" << endl;
    displayRecursive(head);

    while (head != nullptr) {
        node* next = head->next;
        delete head;
        head = next;
    }

    cout << "There are " << counter << " Nodes" << endl;
    cout << "The Sum of Nodes: " << sum << endl;

    return 0;
}