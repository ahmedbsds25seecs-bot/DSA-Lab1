#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "utilities.h"

using namespace std;

void printResult(const string& testName, bool passed) {
    cout << testName << ": " << (passed ? "PASS" : "FAIL") << endl;
}

Matrix generateRandomMatrix(int n) {
    Matrix M(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            M[i][j] = rand() % 10;
    return M;
}

int main() {
    printResult("Task 2 (Add)", add(2, 3) == 5);

    int arr1[] = {10, 20, 30, 20, 40, 20};
    vector<int> res1 = findAllIndices(arr1, 6, 20);
    vector<int> expected1 = {1, 3, 5};
    printResult("Task 3 Test 1", res1 == expected1);

    vector<int> res2 = findAllIndices(arr1, 6, 99);
    printResult("Task 3 Test 2", res2.empty());

    int arr3[] = {};
    vector<int> res3 = findAllIndices(arr3, 0, 10);
    printResult("Task 3 Test 3", res3.empty());

    printResult("Task 4 Test 1", findPattern("hello world", "hello") == 0);
    printResult("Task 4 Test 2", findPattern("hello world", "world") == 6);
    printResult("Task 4 Test 3", findPattern("hello world", "cpp") == -1);
    printResult("Task 4 Test 4", findPattern("hello world", "") == 0);

    auto t0 = generatePascalsTriangle(0);
    printResult("Task 5 Test 1", t0.empty());

    auto t1 = generatePascalsTriangle(1);
    vector<vector<int>> exp1 = {{1}};
    printResult("Task 5 Test 2", t1 == exp1);

    auto t5 = generatePascalsTriangle(5);
    vector<int> row5_expected = {1, 4, 6, 4, 1};
    printResult("Task 5 Test 3", t5.size() == 5 && t5[4] == row5_expected);

    int modeArr1[] = {1, 3, 3, 3, 2, 1, 4};
    vector<int> mode1 = findMode(modeArr1, 7);
    vector<int> expMode1 = {3};
    printResult("Task 6 Test 1", mode1 == expMode1);

    int modeArr2[] = {1, 2, 2, 3, 3, 4};
    vector<int> mode2 = findMode(modeArr2, 6);
    vector<int> expMode2 = {2, 3};
    printResult("Task 6 Test 2", mode2 == expMode2);

    int modeArr3[] = {};
    vector<int> mode3 = findMode(modeArr3, 0);
    printResult("Task 6 Test 3", mode3.empty());

    Matrix A2 = {{1, 2}, {3, 4}};
    Matrix B2 = {{5, 6}, {7, 8}};
    printResult("Task 7 Test 1", multiplyStrassen(A2, B2) == multiplyNaive(A2, B2));

    Matrix A4 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    Matrix B4 = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };
    printResult("Task 7 Test 2", multiplyStrassen(A4, B4) == multiplyNaive(A4, B4));

    Matrix A_rand = generateRandomMatrix(4);
    Matrix B_rand = generateRandomMatrix(4);
    printResult("Task 7 Test 3", multiplyStrassen(A_rand, B_rand) == multiplyNaive(A_rand, B_rand));

    return 0;
}