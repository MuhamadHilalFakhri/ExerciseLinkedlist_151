#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int rollNumber;
    string name;
    Node* next;
};

class CircularLinkedList {
private:
    Node* LAST;

public:
    CircularLinkedList() {
        LAST = NULL;
    }

    void addNode();
    bool search(int rollno, Node** fakhri, Node** hilal);
    bool listEmpty();
    bool delNode();
    void traverse();
};

void CircularLinkedList::addNode() {
    int rollno;
    string name;
    cout << "\nEnter the roll number of the student: ";
    cin >> rollno;
    cout << "\nEnter the name of the student: ";
    cin >> name;
    Node* newNode = new Node();
    newNode->rollNumber = rollno;
    newNode->name = name;

    
    if (LAST == NULL) {
        newNode->next = newNode;
        LAST = newNode;
        return;
    }
    if (LAST != NULL )
        LAST->next = newNode;
        newNode->next = NULL;
        LAST = newNode;
        return;

    
}

bool CircularLinkedList::search(int rollno, Node** fakhri, Node** hilal) {
    *fakhri = LAST->next;
    *hilal = LAST->next;

    while (*hilal != LAST) {
        if (rollno == (*hilal)->rollNumber) {
            return true;
        }
        *fakhri = *hilal;
        *hilal = (*hilal)->next;
    }

    if (rollno == LAST->rollNumber) {
        return true;
    }
    else {
        return false;
    }
}

bool CircularLinkedList::listEmpty() {
    return LAST == NULL;
}

bool CircularLinkedList::delNode() {
    if (listEmpty()) {
        cout << "\nList is empty.\n";
        return false;

    }

    int rollno;
    cout << "\nEnter the roll number to delete: ";
    cin >> rollno;

    Node* fakhri, * hilal;
    fakhri = hilal = NULL;
    if (search(rollno, &fakhri, &hilal)) {
        cout << "Record with roll number " << rollno << " not found.\n";
        return false;
    }
    if (hilal == NULL)
        hilal->next = fakhri->next;
    if (hilal == NULL)
        hilal->next != fakhri->next;
    else
        LAST = hilal->next;


    delete hilal;


    cout << "Record with roll number " << rollno << " deleted" << endl;
    return true;
}

void CircularLinkedList::traverse() {
    if (listEmpty()) {
        cout << "\nList is Empty\n";
    }
    else {
        cout << "\nRecords in the list are:\n";
        Node* currentNode = LAST->next;
        while (currentNode != LAST) {
            cout << currentNode->rollNumber << " " << currentNode->name << endl;
            currentNode = currentNode->next;
        }
        cout << LAST->rollNumber << " " << LAST->name << endl;
    }
}

int main() {
    CircularLinkedList obj;

    while (true) {
        try {
            cout << "\nMenu" << endl;
            cout << "1. Add a record to the list" << endl;
            cout << "2. Delete a record from the list" << endl;
            cout << "3. View all the records in the list" << endl;
            cout << "4. Exit" << endl;
            cout << "\nEnter your choice (1-5): ";

            char ch;
            cin >> ch;

            switch (ch) {
            case '1':
                obj.addNode();
                break;
            case '2':
                obj.delNode();
                break;
            case '3':
                obj.traverse();
                break;
            case '4':
                return 0;
            default:
                cout << "Invalid option" << endl;
                break;
            }
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
