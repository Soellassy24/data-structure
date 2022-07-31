#ifndef function_hpp
#define function_hpp

#include <iostream>
using namespace std;

const int maxQueue = 5; // Max number of queue
int front = 0, back = 0;
string dataDrivers[maxQueue];

bool isFull(){
    if (back == maxQueue){
        return true;
    }else{
        return false;
    }
}

bool isEmpty(){
    if (back == 0){
        return true;
    }else{
        return false;
    }   
}

int count(){
    int counter = 0;
    for (int i = 0; i < back; i++){
        counter++;
    }
    return counter;
}

void enqueue(string driver){
    if (isFull()){
        cout << "Queue is full" << endl;
    }else{
        if (isEmpty()){
            dataDrivers[0] = driver;
            front++;
            back++;
        }else{
            dataDrivers[back] = driver;
            back++;
        }
    }
}

void dequeue(){
    if (isEmpty()){
        cout << "No data enqueued at queue" << endl;
    }else{
        for (int i = 0; i < back; i++){
            dataDrivers[i] = dataDrivers[i+1];
        }
        back--;
    }
}

void display(){
    if (isEmpty()){
        cout << "No data enqueued at queue" << endl;
    }else{
        cout << "Number of queue : " << count() << endl;
        for (int i = 0; i < maxQueue; i++){
            if (dataDrivers[i] != ""){
                cout << i+1 << ". " << dataDrivers[i] << endl;
            }else{
                cout << i+1 << ". " << "No data" << endl;
            }
        }
    }
}

void destroy(){
    if (isEmpty()){
        cout << "No data enqueued at queue" << endl;
    }else{
        for (int i = 0; i < maxQueue; i++){
            if (back > 1){
                dataDrivers[back-1] = "";
                back--;
            }else if(back == 1){
                dataDrivers[back] = "";
                front = 0;
                back = 0;
            }
        }
    }
}
#endif