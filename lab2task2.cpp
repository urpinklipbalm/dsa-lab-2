// Write a C++ program that dynamically allocates an array of integers based on user input, 
// calculates and prints the sum and average of the array elements, 
// and ensures proper memory deallocation.

#include <iostream>
using namespace std;

int sumarray(int *array, int arraysize){
    int sum = 0;
    for (int i = 0; i < arraysize; i++){
        sum += array[i];
    }
    return sum;
}

double averagearray( int *array, int arraysize){
    int sum = sumarray(array, arraysize);
    double average = static_cast<double>(sum/arraysize);
    return average;
}

int main(){

    //asking the user for the size of the array and storing it
    cout << "enter size of array: " << endl;
    int arraysize;
    cin >> arraysize;

    //if user inputs size of array as 0 or lower
    if (arraysize <= 0){
        cout << "unable to make array with this size." << endl;
        exit(1);
    }

    //dynamically allocating memory using pointers
    int *array = new int[arraysize];

    //filling up the array with user input
    for (int i =0; i< arraysize; i++){
        cout << "enter value at " << i << " position:" << endl;
        cin >> array[i];
    }

    //calculating the sum and average
    cout << "the sum of the array is " << sumarray(array, arraysize) << endl;
    cout << "the average of the array is " << averagearray(array, arraysize) << endl;

    //deallocating memory used up the array
    delete[] array;
    cout << "dynamic memory taken up by the array is freed successfully ;)" << endl;

    return 0;
}

