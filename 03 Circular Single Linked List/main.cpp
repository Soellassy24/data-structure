#include <iostream>
using namespace std;

struct DriversData{
    string name, team;
    int number;

    DriversData *next;
};

DriversData *head, *tail, *cur, *newNode, *del, *before;

int countCSLL(){
    int num = 1;
    cur = head;
    while (cur->next != head){
        cur = cur->next;
        num++;
    }
    return num;
}

void createCSLL(string name, string team, int number){
    head = new DriversData();
    head->name = name;
    head->team = team;
    head->number = number;

    tail = head;
    tail->next = head;
}

void addFront(string name, string team, int number){
    if (head == NULL){
        cout << "Create CSLL First!" << endl;
    }else{
        newNode = new DriversData();
        newNode->name = name;
        newNode->team = team;
        newNode->number = number;

        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

void addLast(string name, string team, int number){
    if (head == NULL){
        cout << "Create CSLL First!" << endl;
    }else{
        newNode = new DriversData();
        newNode->name = name;
        newNode->team = team;
        newNode->number = number;

        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

void addMiddle(string name, string team, int number, int pos){
    if (head == NULL){
        cout << "Create CSLL First!" << endl;
    }else{
        if (pos == 1){
            cout << "Number 1 isn't middle position!" << endl;
        }else{
            newNode = new DriversData();
            newNode->name = name;
            newNode->team = team;
            newNode->number = number;

            int num = 1;
            cur = head;
            while (num < pos - 1){
                cur = cur->next;
                num++;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }
}

void delFront(){
    if (head == NULL){
        cout << "Create CSLL First!" << endl;
    }else{
        del = head;
        head = head->next;
        tail->next = head;
        delete del;
    }
}

void delLast(){
    if (head == NULL){
        cout << "Create CSLL First!" << endl;
    }else{
        del = tail;
        cur = head;
        while (cur->next != tail){
            cur = cur->next;
        }
        tail = cur;
        tail->next = head;
        delete del;
    }
}

void delMiddle(int pos){
    if (head == NULL){
         cout << "Create CSLL First!" << endl;
    }else{
        int num = 1;
        cur = head;
        while (num < pos - 1){
            cur = cur->next;
            num++;
        }
        del = cur->next;
        cur->next = del->next;
        delete del;
    }
}

void changeFirst(string name, string team, int number){
    head->name = name;
    head->team = team;
    head->number = number;
}

void changeLast(string name, string team, int number){
    tail->name = name;
    tail->team = team;
    tail->number = number;
}

void changeMiddle(string name, string team, int number, int pos){
    if (pos <= 1 || pos == countCSLL()){
        cout << "Number " << pos << " isn't middle position!" << endl;
    }else{
        int num = 1;
        cur = head;
        while (num < pos){
            cur = cur->next;
            num++;
        }
        cur->name = name;
        cur->team = team;
        cur->number = number;
    }
}

void printCSLL(){
    if (head == NULL){
        cout << "Create CSLL First!" << endl;
    }else{
        cout << countCSLL() << " Driver(s)" << endl << endl;
        cur = head;
        while (cur->next != head){
            cout << "Name : " << cur->name << endl;
            cout << "Team : " << cur->team << endl;
            cout << "Number : " << cur->number << endl;
            cur = cur->next;
        }
        cout << "Name : " << cur->name << endl;
        cout << "Team : " << cur->team << endl;
        cout << "Number : " << cur->number << endl;
    }
}

int main(){
    createCSLL("Sebastian Vettel", "Aston Martin Mercedes", 5);
    printCSLL();

    cout << endl << endl;

    changeFirst("Daniel Ricciardo", "McLaren Mercedes", 3);
    printCSLL();

    cout << endl << endl;

    addFront("Charles Leclerc", "Ferrari", 16);
    printCSLL();

    cout << endl << endl;

    addLast("Esteban Ocon", "Alpine Renault", 31);
    printCSLL();

    cout << endl << endl;

    changeLast("Mick Schumacher", "Haas Ferrari", 47);
    printCSLL();

    cout << endl << endl;

    changeMiddle("Lewis Hamilton", "Mercedes AMG", 44, 2);
    printCSLL();

    cout << endl << endl;

    addMiddle("George Russell", "Mercedes AMG", 63, 5);
    printCSLL();

    cout << endl << endl;

    delMiddle(6);
    printCSLL();

    cout << endl << endl;

    delFront();
    printCSLL();

    cout << endl << endl;

    delLast();
    printCSLL();
}