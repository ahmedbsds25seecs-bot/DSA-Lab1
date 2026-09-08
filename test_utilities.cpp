#include <iostream>
#include <vector>
#include <string>
#include "utilities.h"

using namespace std;

void printResult(const string& testName, bool passed) {
    cout << testName << ": " << (passed ? "PASS" : "FAIL") << endl;
}
int main() {
  
    int arr1[] = {1, 3, 3, 3, 2, 1, 4};
    vector<int> mode1 = findMode(arr1, 7);
    vector<int> exp1 = {3};
    printResult("Task 6 Test 1 (Unique Mode)", mode1 == exp1);

    int arr2[] = {1, 2, 2, 3, 3, 4};
    vector<int> mode2 = findMode(arr2, 6);
    vector<int> exp2 = {2, 3};
    printResult("Task 6 Test 2 (Multiple Modes)", mode2 == exp2);

    int arr3[] = {};
    vector<int> mode3 = findMode(arr3, 0);
    printResult("Task 6 Test 3 (Empty Array)", mode3.empty());

    return 0;
}