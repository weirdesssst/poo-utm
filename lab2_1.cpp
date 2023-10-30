#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    int length;

public:
    String() : data(nullptr), length(0) {}

    String(const String& other) : data(nullptr), length(other.length) {
        if (length > 0) {
            data = new char[length + 1];
            strcpy(data, other.data);
        }
    }

    String(const char* str) : data(nullptr), length(0) {
        if (str) {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        }
    }

    ~String() {
        delete[] data;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            if (length > 0) {
                data = new char[length + 1];
                strcpy(data, other.data);
            } else {
                data = nullptr;
            }
        }
        return *this;
    }

    bool operator==(const String& other) const {
        return (length == other.length && strcmp(data, other.data) == 0);
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    int find(const String& substring) const {
        const char* result = strstr(data, substring.data);
        if (result) {
            return result - data;
        }
        return -1;
    }

    int count(char symbol) const {
        int count = 0;
        for (int i = 0; i < length; i++) {
            if (data[i] == symbol) {
                count++;
            }
        }
        return count;
    }

    int getLength() const {
        return length;
    }

    const char* c_str() const {
        return data;
    }
};

int main() {
    String str1, str2, str3;

    // Citirea de la tastatură
    std::cout << "Introduceti sirul 1: ";
    char input[100];
    std::cin.getline(input, sizeof(input));
    str1 = input;

    std::cout << "Introduceti sirul 2: ";
    std::cin.getline(input, sizeof(input));
    str2 = input;

    std::cout << "Introduceti sirul 3: ";
    std::cin.getline(input, sizeof(input));
    str3 = input;

    if (str1 == str2) {
        std::cout << "str1 este egal cu str2." << std::endl;
    } else {
        std::cout << "str1 nu este egal cu str2." << std::endl;
    }

    int index = str3.find("is");
    if (index != -1) {
        std::cout << "Substring gasit la indexul " << index << std::endl;
    } else {
        std::cout << "Substring-ul nu a fost gasit." << std::endl;
    }

    char symbol;
    std::cout << "Introduceti un caracter cautat in str3: ";
    std::cin >> symbol;
    int count = str3.count(symbol);
    std::cout << "Caracterul '" << symbol << "' apare de" << count << " ori." << std::endl;

    std::cout << "str1: " << str1.c_str() << std::endl;
    std::cout << "str2: " << str2.c_str() << std::endl;
    std::cout << "str3: " << str3.c_str() << std::endl;

    return 0;
}
