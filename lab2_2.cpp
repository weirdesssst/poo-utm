#include <iostream>
#include <cstdlib>
#include <stdexcept>

class Matrix {
private:
    double* data;
    int rows;
    int cols;
    int errorCode;

public:
    // Constructorul implicit
    Matrix() : data(nullptr), rows(0), cols(0), errorCode(0) {}

    // Constructor pentru o matrice pătrată
    Matrix(int n) : data(nullptr), rows(n), cols(n), errorCode(0) {
        if (n <= 0) {
            errorCode = -1; // Cod de eroare pentru dimensiuni incorecte
            return;
        }
        data = new double[n * n];
    }

    // Constructor pentru o matrice dreptunghiulară
    Matrix(int rows, int cols) : data(nullptr), rows(rows), cols(cols), errorCode(0) {
        if (rows <= 0 || cols <= 0) {
            errorCode = -1; // Cod de eroare pentru dimensiuni incorecte
            return;
        }
        data = new double[rows * cols];
    }

    // Destructor
    ~Matrix() {
        delete[] data;
    }

    // Funcții pentru accesarea și modificarea elementelor matricei
    double get(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw std::out_of_range("Indicii specificati nu sunt in limitele matricei.");
        }
        return data[i * cols + j];
    }

    void set(int i, int j, double value) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            throw std::out_of_range("Indicii specificati nu sunt in limitele matricei.");
        }
        data[i * cols + j] = value;
    }

    // Funcții pentru adunare și scădere de matrici
    Matrix add(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Dimensiunile matricelor nu corespund.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.set(i, j, get(i, j) + other.get(i, j));
            }
        }
        return result;
    }

    Matrix subtract(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Dimensiunile matricelor nu corespund.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.set(i, j, get(i, j) - other.get(i, j));
            }
        }
        return result;
    }

    // Funcții pentru înmulțire de matrici și cu un număr
    Matrix multiply(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Numarul de coloane din prima matrice nu corespunde numarului de randuri din a doua matrice.");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                double sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += get(i, k) * other.get(k, j);
                }
                result.set(i, j, sum);
            }
        }
        return result;
    }

    Matrix multiply(double scalar) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.set(i, j, get(i, j) * scalar);
            }
        }
        return result;
    }

    // Funcție pentru afișarea matricei
    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << get(i, j) << ' ';
            }
            std::cout << std::endl;
        }
    }

    // Funcție pentru a verifica codul de eroare
    int getErrorCode() const {
        return errorCode;
    }
};

int main() {
    // Exemplu de utilizare a clasei Matrix
    Matrix mat1(2, 2);
    mat1.set(0, 0, 1);
    mat1.set(0, 1, 2);
    mat1.set(1, 0, 3);
    mat1.set(1, 1, 4);

    Matrix mat2(2, 2);
    mat2.set(0, 0, 5);
    mat2.set(0, 1, 6);
    mat2.set(1, 0, 9);
    mat2.set(1, 1, 8);

    // Adunare
    Matrix resultAdd = mat1.add(mat2);
    std::cout << "Matricea rezultat dupa adunare:\n";
    resultAdd.print();

    // Scădere
    Matrix resultSubtract = mat1.subtract(mat2);
    std::cout << "Matricea rezultat dupa scadere:\n";
    resultSubtract.print();

    // Înmultire
    Matrix mat3(2, 3);
    mat3.set(0, 0, 1);
    mat3.set(0, 1, 2);
    mat3.set(0, 2, 3);
    mat3.set(1, 0, 9);
    mat3.set(1, 1, 5);
    mat3.set(1, 2, 6);

    Matrix resultMultiply = mat1.multiply(mat3);
    std::cout << "Matricea rezultat dupa inmultire:\n";
    resultMultiply.print();

    // Înmulțire cu scalar
    Matrix resultScalar = mat1.multiply(2.0);
    std::cout << "Matricea rezultat dupa inmultire cu scalar:\n";
    resultScalar.print();
    return 0;
}