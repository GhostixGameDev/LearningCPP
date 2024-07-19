//Pointer: Variable that stores the memory addres of another variable.
// "&" Address of operator.
// "*" Dereference of operator.
// "nullptr" Keyword that stands for null pointer literal
// Nullpointers are designed to determine whether of not an address was
// Succesfully assigned to a pointer.

#include <iostream>

int main(){

    //POINTERS
    std::string name = "Testy the variable";
    
    std::string *pName = &name; //Note that the pointer should be the same type as the stored address variable type.
    std::cout << "DIRECCION DE MEMORIA: \n";
    std::cout << pName << "\n";
    std::cout << "Valor dentro: \n";
    std::cout << *pName << "\n";

    std::string thisIsAnArray[3] = {"A", "B", "C"}; //Arrays are already memory addresses.
    //"std::string *pThisIsAnArray = &thisIsAnArray; This will throw an error, because we are trying to get
    //                                               The address of a memory address. Instead we have to do this.
    std::string *pThisIsAnArray = thisIsAnArray;
    std::cout << "DIRECCION DE MEMORIA: " << "\n";
    std::cout << pThisIsAnArray << "\n";
    std::cout << "Valor dentro del primer indice del vector: \n ";
    std::cout << *pThisIsAnArray << "\n"; //At the moment of calling an array pointer, it points to the first value in the array.
    std::cout << "Direccion de la ultima posicion del vector: \n ";
    std::cout << &pThisIsAnArray[(sizeof(thisIsAnArray) / sizeof(thisIsAnArray[0])) - 1] << "\n"; //Pointer to an specific array position
    std::cout << "Valor de la ultima posicion del vector: \n ";
    std::cout << *&pThisIsAnArray[(sizeof(thisIsAnArray) / sizeof(thisIsAnArray[0])) - 1] << "\n"; //Dereference to an specific array position

    //NULL POINTER EXAMPLE
    int *pointer = nullptr; //Here we declare a null pointer, so it doesnt point to anything.
    int imAVariable = 404;
    pointer = &imAVariable;
    if(pointer == nullptr){
        std::cout << "Oh oh, it seems that something went wrong! \n";
    }else{
        std::cout << "Yeeeii, our pointer was made correctly. It points to: ";
        std::cout << pointer << "\n";
    }
    std::cout << "Enter para cerrar.";
    std::string temp;
    std::cin >> temp;
    return 0; 
}