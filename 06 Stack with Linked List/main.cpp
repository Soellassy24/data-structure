#include <iostream>
#include "function.hpp"
using namespace std;

int main(){
    push("Lando Norris", "McLaren Mercedes");
    push("Daniel Ricciardo", "Mclaren Mercedes");
    push("Esteban Ocon", "Alpine Renault");
    push("Mick Schumacher", "Haas Ferrari");
    push("Alexander Albon", "Williams Mercedes");
    push("Max Verstappen", "Red Bull Racing"); // not will be added because stack capacity is full
    
    display();

    cout << "============================" << endl;

    peek(2);

    cout << "============================" << endl;

    pop();
    display();

    cout << "============================" << endl;
    
    change("Valterri Bottas", "Alfa Romeo Ferrari", 1);
    display();

    cout << "============================" << endl;

    destroy();
    display();

    return 0;
}