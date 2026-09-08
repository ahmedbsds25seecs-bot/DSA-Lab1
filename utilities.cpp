#include "utilities.h"

int add(int a, int b) { return a + b; }

std::vector<int> findAllIndices(const int arr[], int size, int key) {
    std::vector<int> indices;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) indices.push_back(i);
    }
    return indices;
}

int findPattern(const std::string& text, const std::string& pattern) {
    if (pattern.empty()) return 0;
    int n = text.length(), m = pattern.length();
    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) j++;
        if (j == m) return i;
    }
    return -1;
}

std::vector<std::vector<int>> generatePascalsTriangle(int numRows) {
    std::vector<std::vector<int>> triangle;
    if (numRows <= 0) return triangle;
    for (int i = 0; i < numRows; ++i) {
        std::vector<int> row(i + 1, 1);
        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }
    return triangle;
}

std::vector<int> findMode(const int arr[], int size) {
    std::vector<int> modes;
    if (size <= 0) return modes;

    std::map<int, int> freqMap;
    int maxFreq = 0;

    for (int i = 0; i < size; ++i) {
        freqMap[arr[i]]++;
        if (freqMap[arr[i]] > maxFreq) {
            maxFreq = freqMap[arr[i]];
        }
    }

    for (const auto& pair : freqMap) {
        if (pair.second == maxFreq) {
            modes.push_back(pair.first);
        }
    }

    return modes;
}