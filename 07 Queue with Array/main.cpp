#include <iostream>
#include "function.hpp"

int main(){
    enqueue("Juri Vips");
    enqueue("Felipe Drugovich");
    enqueue("Charles Leclerc");
    enqueue("Liam Lawson");
    enqueue("Sean Gelael");
    display();

    cout << "========================" << endl;

    dequeue();
    dequeue();
    display();

    cout << "========================" << endl;

    destroy();
    display();
}