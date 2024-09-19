#include <iostream>
using namespace std;

void dynamicmemarray(){

    int userinput;
    cout << "input the size of the array: ";
    cin >> userinput;

    //this dynamically allocates memory
    int *parray = new int[userinput];

    //fills in the array from 1 to n
    for (int i = 0; i< userinput; i++){
        parray[i] = i+1;
    }

    //displaying the array
    cout << "the elements of the array are: " << endl;
    for (int i = 0; i < userinput; i++){
        cout << parray[i] << endl;
        }

     //free dynamically allocated memory
    delete[] parray;
    cout << "dynamic memory taken up the array is freed succesfully :)" << endl;

    }

int main(){

    dynamicmemarray();
}