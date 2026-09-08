#include <iostream>
#include <vector>
#include <string>
#include "utilities.h"

using namespace std;

void printResult(const string& testName, bool passed) {
    cout << testName << ": " << (passed ? "PASS" : "FAIL") << endl;
}

int main() {
    // Task 4 Test Cases
    printResult("Task 4 Test 1 (Beginning)", findPattern("hello world", "hello") == 0);
    printResult("Task 4 Test 2 (End)", findPattern("hello world", "world") == 6);
    printResult("Task 4 Test 3 (Not Present)", findPattern("hello world", "cpp") == -1);
    printResult("Task 4 Test 4 (Empty Pattern)", findPattern("hello world", "") == 0);

    return 0;
}