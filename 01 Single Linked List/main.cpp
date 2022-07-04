#include <iostream>
using namespace std;

//deklarasi single linked list
struct Buku{
    //komponen/member
    string judul, pengarang;
    int tahunTerbit;

    Buku *next;
};

Buku *head, *tail, *cur, *newNode, *del, *before;

//creating single linked list
void creatSingleLinkedList(string judul, string pengarang, int tahunTerbit){
    head = new Buku();
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tahunTerbit;
    head->next = NULL;
    tail = head;
}

int countSingleLinkedList(){
    cur = head;
    int count = 0;
    while (cur != NULL){
        count++;
        cur = cur->next;
    }
    return count;
}

//adding to first node
void addFirstNode(string judul, string pengarang, int tahunTerbit){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tahunTerbit;
    newNode->next = head;
    head = newNode;
}

//adding to last node
void addLastNode(string judul, string pengarang, int tahunTerbit){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tahunTerbit;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void addMiddleNode(string judul, string pengarang, int tahunTerbit, int position){
    if (position < 1 || position > countSingleLinkedList()){
        cout << "Posisi di luar jangkauan!" << endl;
    }else if(position == 1){
        cout << "Posisi bukan posisi tengah!" << endl;
    }else{
        newNode = new Buku();
        newNode->judul = judul;
        newNode->pengarang = pengarang;
        newNode->tahunTerbit = tahunTerbit;

        //melakukan tranversing
        cur = head;
        int number = 1;
        while (number < position - 1){
            cur = cur->next;
            number++;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}
//remove first node
void deleteFirstNode(){
    del = head;
    head = head->next;
    delete del;
}

//remove last node
void deleteLastNode(){
    del = tail;
    cur = head;
    while (cur->next != tail){
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

//remove any position of node
void deleteMiddleNode(int position){
    if (position < 1 || position > countSingleLinkedList()){
        cout << "Posisi di luar jangkauan!" << endl;
    }else if(position == 1){
        cout << "Posisi bukan posisi tengah!" << endl;
    }else{
        int number = 1;
        cur = head;
        while (number <= position){
            if (number == position-1){
                before = cur;
            }
            if (number == position){
                del = cur;
            }
            cur = cur->next;
            number++;
        }
        before->next = cur;
        delete del;
    }
}

void changeFirstNode(string judul, string pengarang, int tahunTerbit){
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tahunTerbit;
}

void changeLastNode(string judul, string pengarang, int tahunTerbit){
    tail->judul = judul;
    tail->pengarang = pengarang;
    tail->tahunTerbit = tahunTerbit;
}

void changeMiddleNode(string judul, string pengarang, int tahunTerbit, int position){
    if (position < 1 || position > countSingleLinkedList()){
        cout << "Posisi di luar jangkauan!" << endl;
    }else if(position == 1 || position == countSingleLinkedList()){
        cout << "Posisi bukan posisi tengah!" << endl;
    }else{
        cur = head;
        int number = 1;
        while (number < position){
            cur = cur->next;
            number++;
        }
        cur->judul = judul;
        cur->pengarang = pengarang;
        cur->tahunTerbit = tahunTerbit;
    }
}

//printing single linked list
void printSingleLinkedList(){
    cout << "Jumlah data ada : " << countSingleLinkedList() << endl << endl;
    cur = head;
    while (cur != NULL){
        cout << "Judul Buku : " << cur->judul << endl;
        cout << "Pengarang Buku : " << cur->pengarang << endl;
        cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;
        cout << endl;
        cur = cur->next;
    }
}

int main(){
    creatSingleLinkedList("Daun Ditiup", "Tere Tere", 2018);
    printSingleLinkedList();

    cout << "========SETELAH DITAMBAH DI DEPAN========" << endl << endl;

    addFirstNode("Darah Biru", "Rey Mysterio", 2009);
    printSingleLinkedList();

    cout << "========SETELAH DITAMBAH DI BELAKANG========" << endl << endl;

    addLastNode("Guide to F1", "Bernie Ecclestone", 2000);
    addLastNode("11.11", "Fiersa Besari", 2018);
    printSingleLinkedList();

    cout << "========SETELAH DIHAPUS DI DEPAN========" << endl << endl;

    deleteFirstNode();
    printSingleLinkedList();

    cout << "========SETELAH DIHAPUS DI BELAKANG========" << endl << endl;

    deleteLastNode();
    printSingleLinkedList();

    cout << "========SETELAH DITAMBAH DI INDEKS TERTENTU========" << endl << endl;

    addFirstNode("Bumi Manusia", "Pramudya Ananta Toer", 2005);
    addMiddleNode("Negeri 5 Menara", "Ahmad Fuadi", 2009, 2);
    printSingleLinkedList();

    cout << "========SETELAH DIHAPUS DI INDEKS TERTENTU========" << endl << endl;

    deleteMiddleNode(2);
    printSingleLinkedList();
    
    cout << "========SETELAH DIUBAH DI DEPAN========" << endl << endl;

    changeFirstNode("Sang Pemimpi", "Andrea Hirata", 2006);
    printSingleLinkedList();

    cout << "========SETELAH DIUBAH DI AKHIR========" << endl << endl;

    changeLastNode("I Am Zlatan", "Zlatan Ibrahimovic", 2018);
    printSingleLinkedList();

    cout << "========SETELAH DIUBAH DI INDEKS TERTENTU========" << endl << endl;

    changeMiddleNode("Sirah Nabawiyah", "Syaikh Shafiyyurahman Al-Mubarakfuri", 1996, 2);
    printSingleLinkedList();
}