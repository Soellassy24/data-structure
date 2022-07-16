#include <iostream>
using namespace std;

struct DriversData{
    string name, team;

    DriversData *next;
    DriversData *prev;
};

DriversData *head, *tail, *newNode, *afterNode, *cur, *del;

int countCDLL(){
    int num = 1;
    if (head == NULL){
        cout << "Create CDLL First!" << endl;
    }else{
        cur = head;
        while (cur->next != head){
            cur = cur->next;
            num++;
        }
    }
    return num;
}

void createCDLL(string name, string team){
    head = new DriversData();
    head->name = name;
    head->team = team;
    head->prev = head;
    head->next = head;
    tail = head;
}

void addFirst(string name, string team){
    if (head == NULL){
        cout << "Make CDLL First!" << endl;
    }else{
        newNode = new DriversData();
        newNode->name = name;
        newNode->team = team;

        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;

        head = newNode;
    }
    
}

void addLast(string name, string team){
    if (head == NULL){
        cout << "Make CDLL First!" << endl;
    }else{
        newNode = new DriversData();
        newNode->name = name;
        newNode->team = team;

        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;

        tail = newNode;
    }
}

void addMiddle(string name, string team, int pos){
    if (head == NULL){
        cout << "Make CDLL First!" << endl;
    }else{
        if (pos == 1 || pos == countCDLL() + 1){
            cout << "Number " << pos << " isn't middle position!" << endl;
        }else if(pos < 1){
            cout << "Position out of range!" << endl;
        }else{
            newNode = new DriversData();
            newNode->name = name;
            newNode->team = team;
        
            cur = head;
            int num = 1;
            while (num < pos - 1){
                cur = cur->next;
                num++;
            }
            afterNode = cur->next;
            cur->next = newNode;
            afterNode->prev = newNode;
            newNode->prev = cur;
            newNode->next = afterNode;
        }
    }
}

void removeFirst(){
    if (head == NULL){
        cout << "Create CDLL First!" << endl;
    }else{
        del = head;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        delete del;
    }
}

void removeLast(){
    if (head == NULL){
        cout << "Create CDLL First!" << endl;
    }else{
        del = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete del;
    }
}

void removeMiddle(int pos){
    if (head == NULL){
        cout << "Create CDLL First!" << endl;
    }else{
        if (pos == 1 || pos == countCDLL() + 1){
            cout << "Number " << pos << " isn't middle position!" << endl;
        }else if(pos < 1){
            cout << "Position out of range!" << endl;
        }else{
            cur = head;
            int num = 1;
            while (num < pos - 1){
                cur = cur->next;
                num++;
            }
            del = cur->next;
            afterNode = del->next;
            cur->next = afterNode;
            afterNode->prev = cur;
            delete del;
        }
    }
}

void changeFirst(string name, string team){
    if (head == NULL){
        cout << "Create CDLL First!" << endl;
    }else{
        head->name = name;
        head->team = team;
    }
}

void changeLast(string name, string team){
    if (head == NULL){
        cout << "Create CDLL First!" << endl;
    }else{
        tail->name = name;
        tail->team = team;
    }
}

void changeMiddle(string name, string team, int pos){
    if (pos <= 1 || pos == countCDLL()){
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
    }
}

void printCDLL(){
    if (head == NULL){
        cout << "Create CDLL First!" << endl;
    }else{
        cout << "Driver Data(s) : " << countCDLL() << endl;
        cur = head;
        while (cur->next != head){
            cout << "Name : " << cur->name << endl;
            cout << "Team : " << cur->team  << endl << endl;
            cur = cur->next;
        }
        cout << "Name : " << cur->name << endl;
        cout << "Team : " << cur->team  << endl;
    }
}

int main(){
    createCDLL("Michael Schumacher", "Benetton Ford");
    printCDLL();

    cout << "======================================" << endl;

    addFirst("David Coulthard", "McLaren Mercedes");
    printCDLL();

    cout << "======================================" << endl;

    addLast("Giancarlo Fisichella", "Jordan Ford");
    printCDLL();

    cout << "======================================" << endl;

    addMiddle("Jos Verstappen", "Arrows Asiatech", 3);
    addMiddle("Jarno Trulli", "Toyota", 6);
    addMiddle("Fernando Alonso", "Renault Mild Seven", 4);
    printCDLL();

    cout << "======================================" << endl;

    removeFirst();
    printCDLL();

    cout << "======================================" << endl;

    removeLast();
    printCDLL();

    cout << "======================================" << endl;

    removeMiddle(6);
    printCDLL();

    cout << "======================================" << endl;

    changeFirst("Mika Hakkinen", "McLaren Mercedes");
    printCDLL();

    cout << "======================================" << endl;

    changeLast("Juan Pablo Montoya", "BMW Williams");
    printCDLL();

    cout << "======================================" << endl;

    changeMiddle("Nick Heidfeld", "Jordan Ford", 5);
    printCDLL();
}