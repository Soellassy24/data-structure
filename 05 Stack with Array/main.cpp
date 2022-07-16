#include <iostream>
using namespace std;

const int maxStack = 5; // maxStack as Max in pdf (must be const)
string racers[maxStack];
int dataCount = 0; //dataCount as Top in pdf

bool isStackFull(){
    if (dataCount == maxStack){
        return true;
    }
    return false;
}

bool isStackEmpty(){
    if (dataCount <= 0){
        return true;
    }
    return false;
}

int countStack(){
   if (isStackEmpty()){
        return 0;
   }else{
        return dataCount;
   }
}

void pushStack(string racer){
    if (isStackFull()){
        cout << "Stack is full" << endl;
    }else{
        racers[dataCount] = racer;
        dataCount++;
    }
}

void popStack(){
    if (isStackEmpty()){
        cout << "Stack is empty!" << endl;
    }else{
        racers[dataCount - 1] = "";
    }
}

void peekStack(int pos){
    if (isStackEmpty()){
        cout << "Stack is empty!" << endl;
    }else{
        int index = dataCount + 1;
        for (int i = 0; i < pos; i++){
            index--;
        }
        cout << "Stack data at position " << pos << " is " << racers[index] << endl;
    }
}

void changeStackData(string racer, int pos){
    if (isStackEmpty()){
        cout << "Stack is empty!" << endl;
    }else if(pos > countStack()){
        cout << "Number " << pos << " doesn't exist" << endl;
    }else{
        int index = dataCount;
        for (int i = 0; i < pos; i++){
            index--;
        }
        racers[index] = racer;
    }
}

void destroyStack(){
     for (int i = 0; i < dataCount; i++){
        racers[i] = "";
     }
}

void displayStack(){
    if(isStackEmpty()){
        cout << "Stack is empty!" << endl;
    }else{
        cout << "Data(s) in stack : " << endl;
        for (int i = maxStack - 1; i >= 0; i--){
            cout << racers[i] << endl;
        }
        cout << "==============================" << endl;
    }
}

int main(){
   
    pushStack("Timo Glock");
    pushStack("Narain Karthikeyan");
    pushStack("Jerome D'ambrosio");
    pushStack("Stoffel Vandoorne");
    displayStack();

    popStack();
    displayStack();

    changeStackData("Charles Pic", 3);
    displayStack();

    peekStack(3);
    cout << isStackEmpty() << endl;
    cout << isStackFull() << endl;

    destroyStack();
    displayStack();

    return 0;
}