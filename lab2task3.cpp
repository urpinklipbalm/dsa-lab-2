#include <iostream>
using namespace std;

int main() {
    int test = 9;
    int* ptr = &test;  
    
    // int* ptr = nullptr;  // Pointer initialized to nullptr
    
    // Check if the pointer is not null before dereferencing
    if (ptr != nullptr) {
        cout << "Value pointed by ptr: " << *ptr << endl;
    } else {
        cout << "Trying to dereference a null pointer!!" << endl;
        exit(1);  // Exit the program if dereferencing a null pointer is attempted
    }

    return 0;
}

