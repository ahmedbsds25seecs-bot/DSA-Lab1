#include "utilities.h"

int add(int a, int b) {
    return a + b;
}

std::vector<int> findAllIndices(const int arr[], int size, int key) {
    std::vector<int> indices;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            indices.push_back(i);
        }
    }
    return indices;
}

int findPattern(const std::string& text, const std::string& pattern) {
    if (pattern.empty()) return 0; // Empty pattern edge case
    
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            return i; // Pattern match found at index i
        }
    }
    return -1; // Pattern not found
}