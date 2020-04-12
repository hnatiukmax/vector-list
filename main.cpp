#include <iostream>
#include "vector/Vector.h"
#include "vector/Vector.cpp"

using namespace std;

int main() {
    int arr[] = {5,2,3};
    int arr1[] = {5,1,3};
    Vector<int> vec(arr,3);
    Vector<int> vec1(arr1,3);

    Vector adding = vec + vec1;
    Vector difference = vec - vec1;
    Vector multiplying = vec * vec1;
    Vector division = vec / vec1;

    cout << "Adding: " << adding << endl;
    cout << "Difference: " << difference << endl;
    cout << "Multiplying: " << multiplying << endl;
    cout << "Division: " << division << endl;

    Vector<int> inputVector(3);
    cin >> inputVector;

    inputVector.add(3);
    cout << inputVector;

    return 0;
}