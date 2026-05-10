// Practical 8: Matrix class with Sum, Product, Transpose
// Exception handling for incompatible matrices; exceptions caught in main()

#include <iostream>
#include <stdexcept>
using namespace std;

class Matrix {
    int rows, cols;
    int data[10][10];

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                data[i][j] = 0;
    }

    void input() {
        cout << "Enter elements of " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                cout << "  [" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
    }

    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << "\t";
            cout << "\n";
        }
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    // a. Matrix addition — throws if dimensions don't match
    Matrix add(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument(
                "Matrix addition requires equal dimensions: "
                "(" + to_string(rows) + "x" + to_string(cols) + ") vs ("
                + to_string(other.rows) + "x" + to_string(other.cols) + ")"
            );

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    // b. Matrix multiplication — throws if cols of A != rows of B
    Matrix multiply(const Matrix& other) const {
        if (cols != other.rows)
            throw invalid_argument(
                "Matrix multiplication requires cols(A) == rows(B): "
                "cols=" + to_string(cols) + " but rows(B)=" + to_string(other.rows)
            );

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    // c. Transpose — always valid
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[j][i] = data[i][j];
        return result;
    }
};

int main() {
    int choice;

    do {
        cout << "\n========= Matrix Operations =========\n";
        cout << "1. Sum (A + B)\n";
        cout << "2. Product (A x B)\n";
        cout << "3. Transpose (A^T)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                int r1, c1, r2, c2;
                cout << "Matrix A — enter rows and cols: ";
                cin >> r1 >> c1;
                Matrix A(r1, c1);
                A.input();

                cout << "Matrix B — enter rows and cols: ";
                cin >> r2 >> c2;
                Matrix B(r2, c2);
                B.input();

                Matrix C = A.add(B);
                cout << "\nSum (A + B):\n";
                C.display();

            } else if (choice == 2) {
                int r1, c1, r2, c2;
                cout << "Matrix A — enter rows and cols: ";
                cin >> r1 >> c1;
                Matrix A(r1, c1);
                A.input();

                cout << "Matrix B — enter rows and cols: ";
                cin >> r2 >> c2;
                Matrix B(r2, c2);
                B.input();

                Matrix C = A.multiply(B);
                cout << "\nProduct (A x B):\n";
                C.display();

            } else if (choice == 3) {
                int r, c;
                cout << "Matrix A — enter rows and cols: ";
                cin >> r >> c;
                Matrix A(r, c);
                A.input();

                Matrix T = A.transpose();
                cout << "\nTranspose of A:\n";
                T.display();

            } else if (choice != 0) {
                cout << "Invalid choice.\n";
            }

        } catch (const invalid_argument& e) {
            cout << "\n[Exception caught in main()] " << e.what() << "\n";
        }

    } while (choice != 0);

    cout << "Program ended.\n";
    return 0;
}
