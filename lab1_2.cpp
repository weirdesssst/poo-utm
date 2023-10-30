#include <iostream>

struct Vector {
    short* elements;
    int size;
};

// Funcție pentru inițializarea vectorului cu dimensiune dată
void initVector(Vector& vector, int size) {
    vector.elements = new short[size];
    vector.size = size;
}

// Funcție pentru eliminarea vectorului și eliberarea memoriei
void deleteVector(Vector& vector) {
    delete[] vector.elements;
    vector.size = 0;
}

// Funcție pentru modificarea dimensiunii vectorului
void resizeVector(Vector& vector, int newSize) {
    short* newElements = new short[newSize];

    // Copiem elementele din vectorul vechi în noul vector
    for (int i = 0; i < std::min(vector.size, newSize); i++) {
        newElements[i] = vector.elements[i];
    }

    delete[] vector.elements;  // Eliberăm memoria alocată inițial
    vector.elements = newElements;
    vector.size = newSize;
}

// Funcție pentru accesarea elementelor vectorului
short& getElement(Vector& vector, int index) {
    if (index >= 0 && index < vector.size) {
        return vector.elements[index];
    }
    // În caz de index invalid, vom returna primul element (0) pentru a evita erorile
    return vector.elements[0];
}

// Funcție pentru calcularea sumei elementelor pare ale vectorului
int sumOfEvenElements(Vector& vector) {
    int sum = 0;
    for (int i = 0; i < vector.size; i++) {
        if (vector.elements[i] % 2 == 0) {
            sum += vector.elements[i];
        }
    }
    return sum;
}

int main() {
    // Exemplu de inițializare a două vectori și adăugare de date în aceștia
    Vector vector1, vector2;
    initVector(vector1, 5);
    initVector(vector2, 3);

    for (int i = 0; i < vector1.size; i++) {
        vector1.elements[i] = i * 2;
    }

    for (int i = 0; i < vector2.size; i++) {
        vector2.elements[i] = i * 3 + 1;
    }

    // Afișăm elementele vectorilor
    std::cout << "Vector1: ";
    for (int i = 0; i < vector1.size; i++) {
        std::cout << vector1.elements[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector2: ";
    for (int i = 0; i < vector2.size; i++) {
        std::cout << vector2.elements[i] << " ";
    }
    std::cout << std::endl;

    // Modificăm dimensiunea vectorului 2
    resizeVector(vector2, 4);

    // Afișăm elementele vectorului 2 după modificare
    std::cout << "Vector2 (dupa modificare): ";
    for (int i = 0; i < vector2.size; i++) {
        std::cout << vector2.elements[i] << " ";
    }
    std::cout << std::endl;

    // Calculăm suma elementelor pare din vectorul 1
    int sumaPareVector1 = sumOfEvenElements(vector1);
    std::cout << "Suma elementelor pare din Vector1: " << sumaPareVector1 << std::endl;

    // Eliberăm memoria alocată pentru vectori
    deleteVector(vector1);
    deleteVector(vector2);

    return 0;
}
