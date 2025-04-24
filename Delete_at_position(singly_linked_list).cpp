#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* insert_end(Node* head, int val) {
    Node* new_node = new Node(val);
    if (!head) return new_node;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new_node;
    return head;
}

Node* create_list() {
    Node* head = NULL;
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        head = insert_end(head, val);
    }
    return head;
}

void print_list(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* delete_at_position(Node* head, int k) {
    if (head == NULL || k <= 0) return head;

    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* cur = head;
    for (int i = 1; cur != NULL && i < k - 1; i++) {
        cur = cur->next;
    }

    if (cur != NULL && cur->next != NULL) {
        Node* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
    }

    return head;
}

int main() {
    Node* head = create_list();
    cout << "Original list: ";
    print_list(head);

    int k;
    cout << "Enter position to delete: ";
    cin >> k;

    head = delete_at_position(head, k);
    cout << "List after deletion: ";
    print_list(head);

    return 0;
}
