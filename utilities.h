#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <string>
#include <map>

int add(int a, int b);

std::vector<int> findAllIndices(const int arr[], int size, int key);

int findPattern(const std::string& text, const std::string& pattern);

std::vector<std::vector<int>> generatePascalsTriangle(int numRows);

std::vector<int> findMode(const int arr[], int size);

#endif