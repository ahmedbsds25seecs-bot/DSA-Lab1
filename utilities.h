#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <string>
#include <map>

typedef std::vector<std::vector<int>> Matrix;

int add(int a, int b);
std::vector<int> findAllIndices(const int arr[], int size, int key);
int findPattern(const std::string& text, const std::string& pattern);
std::vector<std::vector<int>> generatePascalsTriangle(int numRows);
std::vector<int> findMode(const int arr[], int size);
Matrix multiplyNaive(const Matrix& A, const Matrix& B);
Matrix multiplyStrassen(const Matrix& A, const Matrix& B);

#endif