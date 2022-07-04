#include <iostream>
using namespace std;

struct DataUser{
    string nama, username, email, pass;
    DataUser *prev;
    DataUser *next;
};

DataUser *head, *tail, *cur, *newNode, *del, *afterNode;

bool validationOfDLL(){
    if (head == NULL){
        cout << "Double Linked List belum dibuat!" << endl;
        return false;
    }else{
        return true;
    }
}

void createDoubleLinkedList(string data[4]){
    head = new DataUser();
    head->nama = data[0];
    head->email = data[1];
    head->pass = data[2];
    head->username = data[3];

    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

int countDoubleLinkedList(){
    validationOfDLL();
    int sum = 0;
    cur = head;
    while (cur != NULL){
        sum++;
        cur = cur->next;
    }
    return sum;
}

void printDoubleLinkedList(){
    validationOfDLL();
    cout << "Jumlah data : " << countDoubleLinkedList() << endl;
    cur = head;
    while (cur != NULL){
        cout << "Nama : " << cur->nama << endl;
        cout << "Email : " << cur->email << endl;
        cout << "Pass : " << cur->pass << endl;
        cout << "Username : " << cur->username << endl << endl;

        cur = cur->next;
    }
}

void addFirstNode(string data[4]){
    validationOfDLL();
    newNode = new DataUser();
    newNode->nama = data[0];
    newNode->email = data[1];
    newNode->pass = data[2];
    newNode->username = data[3];

    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;   
}

void addLastNode(string data[4]){
    validationOfDLL();
    newNode = new DataUser();
    newNode->nama = data[0];
    newNode->email = data[1];
    newNode->pass = data[2];
    newNode->username = data[3];

    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;    
}

void addMiddleNode(string data[4], int position){
    validationOfDLL();
    if (position == 1){
        cout << "Posisi 1 bukan posisi tengah!" << endl;
    }else if(position < 1 || position > countDoubleLinkedList()){
        cout << "Posisi di luar jangkauan!" << endl;
    }else{
        newNode = new DataUser();
        newNode->nama = data[0];
        newNode->email = data[1];
        newNode->pass = data[2];
        newNode->username = data[3];

            //tranversing
        cur = head;
        int number = 1;
        while (number < position - 1){
            cur = cur->next;
            number++;
        }
        afterNode = cur->next;
        newNode->prev = cur;
        newNode->next = afterNode;
        cur->next = newNode;
        afterNode->prev = newNode;
    } 
}

void deleteFirstNode(){
    validationOfDLL();
    del = head;
    head = head->next;
    head->prev = NULL;
    delete del;
}

void deleteLastNode(){
    validationOfDLL();
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
}

void deleteMiddleNode(int position){
    validationOfDLL();
    if (position == 1 || position == countDoubleLinkedList()){
        cout << "Posisi "<< position << " bukan posisi tengah" << endl;
    }else if(position < 1 || position > countDoubleLinkedList()){
        cout << "Posisi diluar jangkauan" << endl;
    }else{
        int number = 1;
        cur = head;
        while (number < position - 1){
            cur = cur->next;
            number++;
        }
        del = cur->next;
        afterNode = del->next;

        cur->next = afterNode;
        afterNode->prev = cur;
        delete del;
    }
}

void changeFirstNode(string data[4]){
    validationOfDLL();
    head->nama = data[0];
    head->email = data[1];
    head->pass = data[2];
    head->username = data[3];
}

void changeLastNode(string data[4]){
    validationOfDLL();
    tail->nama = data[0];
    tail->email = data[1];
    tail->pass = data[2];
    tail->username = data[3];
}

void changeMiddleNode(string data[4], int position){
    validationOfDLL();
    if (position < 1 || position > countDoubleLinkedList()){
        cout << "Posisi di luar jangkauan!" << endl;
    }else if(position == 1 || position == countDoubleLinkedList()){
        cout << "Posisi " << position <<" bukan posisi tengah!" << endl;
    }else{
        cur = head;
        int number = 1;
        while (number < position){
            cur = cur->next;
            number++;
        }
        cur->nama = data[0];
        cur->email = data[1];
        cur->pass = data[2];
        cur->username = data[3];
    }
}

int main(){

    cout << "=====MEMBUAT NODE BARU=====" << endl << endl;

    string newData00[4] = {"Ikhwanul Abiyu", "ikhwanulabiyu@gmail.com", "qwerty123", "@ikhwanulabiyu"};
    createDoubleLinkedList(newData00);
    printDoubleLinkedList(); cout << endl;

    cout << "=====MENAMBAH NODE BARU DARI DEPAN=====" << endl << endl;

    string newData01[4] = {"Charles Leclerc", "charlesleclerc@gmail.com", "qwerty123", "@charlesleclerc"};
    string newData02[4] = {"Sebastian Vettel", "sebastianvettel@gmail.com", "qwerty123", "@sebastianvettel"};
    addFirstNode(newData01);
    addFirstNode(newData02);
    printDoubleLinkedList(); cout << endl;

    cout << "=====MEMBUAT NODE BARU DARI BELAKANG=====" << endl << endl;

    string newData03[4] = {"Carlos Sainz", "carlossainz@gmail.com", "qwerty123", "@carlossainz"};
    addLastNode(newData03);
    printDoubleLinkedList(); cout << endl;

    cout << "=====MENGHAPUS NODE DARI DEPAN=====" << endl << endl;

    deleteFirstNode();
    printDoubleLinkedList(); cout << endl;

    cout << "=====MENGHAPUS NODE DARI BELAKANG=====" << endl << endl;

    deleteLastNode();
    printDoubleLinkedList(); cout << endl;

    cout << "=====MENAMBAH NODE KE TENGAH=====" << endl << endl;

    string newData04[4] = {"Kimi Raikonnen", "kimiraikonnen@gmail.com", "qwerty123", "@kimiraikonnen"};
    string newData08[4] = {"Antonio Giovinazzi", "antoniogiovinazzi@gmail.com", "qwerty123", "@antoniogiovinazzi"};
    addMiddleNode(newData04, 2);
    addMiddleNode(newData08, 3);
    printDoubleLinkedList();
    
    cout << "=====MENGHAPUS DI TENGAH NODE====" << endl << endl;
    deleteMiddleNode(2);
    printDoubleLinkedList();

    cout << "=====MENGGANTI ISI AWAL NODE =====" << endl << endl;
    string newData05[4] = {"Max Verstappen", "maxverstappen@gmail.com", "qwerty123", "@maxverstappen33"};
    changeFirstNode(newData05);
    printDoubleLinkedList();

    cout << "=====MENGGANTI ISI AKHIR NODE =====" << endl << endl;
    string newData06[4] = {"Sergio Perez", "sergioperez@gmail.com", "qwerty123", "@sergioperez"};
    changeLastNode(newData06);
    printDoubleLinkedList();

    cout << "=====MENGGANTI ISI TENGAH NODE =====" << endl << endl;
    string newData07[4] = {"Pierre Gasly", "pierregasly@gmail.com", "qwerty123", "@likedbypierregasly"};
    changeMiddleNode(newData07, 2);
    printDoubleLinkedList();
    return 0;
}