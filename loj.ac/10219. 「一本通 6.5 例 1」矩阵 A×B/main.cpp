#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Matrix {
    int row, col;
    int* data;

    Matrix(int row, int col)
        : row(row),
          col(col),
          data(static_cast<int*>(memset(malloc(sizeof(int) * row * col),
                                        0,
                                        sizeof(int) * row * col))) {}
    Matrix(const Matrix& other)
        : row(other.row),
          col(other.col),
          data(static_cast<int*>(memcpy(malloc(sizeof(int) * row * col),
                                        other.data,
                                        sizeof(int) * row * col))) {}
    ~Matrix() { free(data); }

    inline int& at(int i, int j) { return data[i * row + j]; }
    inline const int& at(int i, int j) const { return data[i * row + j]; }
};

Matrix operator*(const Matrix& a, const Matrix& b) {
    Matrix c(a.row, b.col);
    for (int i = 0; i < a.row; ++i)
        for (int j = 0; j < b.col; ++j)
            for (int k = 0; k < b.col; ++k)
                c.at(i, j) += a.at(i, k) + b.at(k, j);
}

int main() {}