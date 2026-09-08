#include "utilities.h"

int add(int a, int b) { 
    return a + b; 
}

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
        for (int j = 1; j < i; ++j) row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
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
        if (freqMap[arr[i]] > maxFreq) maxFreq = freqMap[arr[i]];
    }
    for (const auto& pair : freqMap) if (pair.second == maxFreq) modes.push_back(pair.first);
    return modes;
}

Matrix multiplyNaive(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

Matrix addMatrix(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix subMatrix(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

Matrix multiplyStrassen(const Matrix& A, const Matrix& B) {
    int n = A.size();
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int k = n / 2;
    Matrix A11(k, std::vector<int>(k)), A12(k, std::vector<int>(k)),
           A21(k, std::vector<int>(k)), A22(k, std::vector<int>(k));
    Matrix B11(k, std::vector<int>(k)), B12(k, std::vector<int>(k)),
           B21(k, std::vector<int>(k)), B22(k, std::vector<int>(k));

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            A11[i][j] = A[i][j];         A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];     A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];         B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];     B22[i][j] = B[i + k][j + k];
        }
    }

    Matrix P1 = multiplyStrassen(A11, subMatrix(B12, B22));
    Matrix P2 = multiplyStrassen(addMatrix(A11, A12), B22);
    Matrix P3 = multiplyStrassen(addMatrix(A21, A22), B11);
    Matrix P4 = multiplyStrassen(A22, subMatrix(B21, B11));
    Matrix P5 = multiplyStrassen(addMatrix(A11, A22), addMatrix(B11, B22));
    Matrix P6 = multiplyStrassen(subMatrix(A12, A22), addMatrix(B21, B22));
    Matrix P7 = multiplyStrassen(subMatrix(A11, A21), addMatrix(B11, B12));

    Matrix C11 = addMatrix(subMatrix(addMatrix(P5, P4), P2), P6);
    Matrix C12 = addMatrix(P1, P2);
    Matrix C21 = addMatrix(P3, P4);
    Matrix C22 = subMatrix(subMatrix(addMatrix(P5, P1), P3), P7);

    Matrix C(n, std::vector<int>(n, 0));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            C[i][j] = C11[i][j];         C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];     C[i + k][j + k] = C22[i][j];
        }
    }

    return C;
}