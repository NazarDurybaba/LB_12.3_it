#include <iostream>
#include <Windows.h>

using namespace std;

// ���������, �� ����������� ����� ��������������� ������
struct Node {
    int data;   // ��� �����
    Node* prev;   // �������� �� ��������� �����
    Node* next;   // �������� �� ��������� �����
};

// ������� ��� ��������� ��������������� ������ �� ����� ������ �������
Node* createList(int values[], int size) {
    Node* head = nullptr;  // ���������� �����
    Node* tail = nullptr;  // ʳ������ �����

    // ������ �� ������ �������
    for (int i = 0; i < size; i++) {
        // ��������� ������ �����
        Node* newNode = new Node(); // 1
        newNode->data = values[i];  // 2 ��������� �������� �����
        newNode->prev = nullptr;   // 3 ��������� �������� ��������� �� ��������� �����
        newNode->next = nullptr;   // 4 ��������� �������� ��������� �� ��������� �����

        // ��������, �� �� ������ ����� � ������
        if (head == nullptr) {
            head = newNode;  //5 ���� ���, �� ������������ ���� �� ����������� ��� � �������� �����
            tail = newNode; //6
        }
        else {
            tail->next = newNode;  // ��������� ������ ����� ���� �������� �����
            newNode->prev = tail;  // ������������ ��������� �� ��������� ����� ��� ������ �����
            tail = newNode;   // ������������ ������ ����� �� ��������
        }
    }

    return head;  // ���������� ��������� �� ���������� �����
}

// ������� ��� ��������� ������� �������� ������, ���� ���� �� ��������� � ������� ���������
void removeNextElements(Node* head, int targetValue) {
    Node* current = head; // �������� �����, ���� ������������

    // ������ �� ��� ������ � ������
    while (current != nullptr && current->next != nullptr) {
        // ��������, �� �������� ��������� ����� ������� � �������� ���������
        if (current->data == targetValue) {
            Node* temp = current->next; // ���������� �������� �� ��������� �����
            current->next = temp->next; // ������������ ��������� �� ��������� ����� ��� ��������� �����
            if (temp->next != nullptr) {
                temp->next->prev = current; // ������������ ��������� �� ��������� ����� ��� ���������� �����
            }
            delete temp; // ��������� ����������� �����
        }
        current = current->next; // ������� �� ���������� �����
    }
}

// ������� ��� ��������� ������� ��� ����� � ������
void printList(Node* head) {
    Node* current = head;  // ���������� �����

    // ������ �� ��� ������ � ������
    while (current != nullptr) {
        std::cout << current->data << " ";  // ��������� �������� ��������� �����
        current = current->next;   // ������� �� ���������� �����
    }

    std::cout << std::endl;  // ��������� ������� ������ ����� � ���� ������
}

// ������� ��� ��������� ������ ������ �� ��������� ���'��
void deleteList(Node* head) {
    Node* current = head;  // ���������� �����

    // ������ �� ��� ������ � ������
    while (current != nullptr) {
        Node* temp = current;   // ���������� �������� �� �������� �����
        current = current->next;   // ������� �� ���������� �����
        delete temp;   // ��������� ���'��, ��� ���� ������� ��� ��������� �����
    }
}

int main() {
    SetConsoleOutputCP(1251);
    int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };  // ����� ������� ��� ��������� ������
    int size = sizeof(values) / sizeof(values[0]);  // ����� ������

    Node* head = createList(values, size);  // ��������� ��������������� ������

    std::cout << "������ ��������:" << std::endl;
    printList(head);  // ��������� �������� ������

    int targetValue;
    std::cout << "������ ��������, �� ���� ���� �������� ��������: ";
    std::cin >> targetValue; // �������� �������� ������������

    removeNextElements(head, targetValue); // ��������� ��������, �� ������� �� ������� ���������

    std::cout << "������ �������� ���� ���������:" << std::endl;
    printList(head); // ��������� �������� ������ ���� ���������

    deleteList(head);  // ��������� ������ �� ��������� ���'��

    return 0;
}
