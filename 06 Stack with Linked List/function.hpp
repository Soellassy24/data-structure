#ifndef function_hpp
#define function_hpp

#include <iostream>
using namespace std;

struct Racer{
    string name;
    string team;

    Racer *next;
    Racer *prev;
};

const int maxStack = 5; //Limited number of datas in stack
Racer *head, *tail, *newNode, *cur, *del;

bool isEmpty(){
    if (head == NULL){
        return true;
    }else{
        return false;
    }
}

int count(){
    int val = 1;
    cur = head;
    while (cur != tail){
        cur = cur->next;
        val++;
    }
    return val;
}

bool isFull(){
    if (count() == maxStack){
        return true;
    }else{
        return false;
    }
}

void createNew(string name, string team){
    head = new Racer();
    head->name = name;
    head->team = team;

    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

void push(string name, string team){
    if (isFull()){
        cout << "Cannot add " << name << " from " << team << " because stack is full!" << endl;
    }else{
        if(isEmpty()){
            createNew(name, team);
        }else{
            newNode = new Racer();
            newNode->name = name;
            newNode->team = team;

            newNode->prev = tail;
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
    }
}

void pop(){
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
}

void peek(int pos){
    if (isEmpty()){
        cout << "Stack is empty!" << endl;
    }else{
        if (pos > count()){
            cout << "Position " << pos << " doesn't exist." << endl;
        }else{
            int val = 1;
            cur = tail;
            while (val < pos){
                cur = cur->prev;
                val++;
            }
            cout << "Driver number " << pos << " is : " << cur->name << endl;
            cout << "                     " << cur->team << endl;
        }   
    }
}

void change(string name, string team, int pos){
    if (isEmpty()){
        cout << "Stack is empty!" << endl;
    }else{
        if (pos > count() + 1){
            cout << "Position " << pos << " doesn't exist." << endl;
        }else{
            int val = 1;
            cur = tail;
            while (val < pos){
                cur = cur->prev;
                val++;
            }
            cur->name = name;
            cur->team = team;
        }   
    }
}

void display(){
    if (isEmpty()){
        cout << "Stack is empty!" << endl;
    }else{
        int val = 1;
        cur = tail;
        cout << "Number of racer(s) : " << count() << endl;
        while (cur != NULL){
            cout << val << ". " << cur->name << endl;
            cout << "   " << cur->team << endl;
            cur = cur->prev;
            val++;
        }
    }
}

void destroy(){
    cur = head;
    while (cur != NULL){
        del = cur;
        head = head->next;
        delete del;
        cur = cur->next;
    }
    
}

#endif