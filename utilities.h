#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <string>

int add(int a, int b);

std::vector<int> findAllIndices(const int arr[], int size, int key);

int findPattern(const std::string& text, const std::string& pattern);

#endif