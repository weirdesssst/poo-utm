#include <iostream>
#include <cstring>
using namespace std;
struct Carte {
    char *denumire;
    char *autor;
    char *editura;
    int volumPagini;
    int anEditie;
};

// Funcție pentru setarea datelor unei cărți
void setareCarte(Carte &carte, const char *denumire, const char *autor, const char *editura, int volumPagini, int anEditie) {
    carte.denumire = new char[strlen(denumire) + 1];
    strcpy(carte.denumire, denumire);

    carte.autor = new char[strlen(autor) + 1];
    strcpy(carte.autor, autor);

    carte.editura = new char[strlen(editura) + 1];
    strcpy(carte.editura, editura);

    carte.volumPagini = volumPagini;
    carte.anEditie = anEditie;
}

// Funcție pentru eliberarea memoriei alocate pentru o carte
void eliberareMemorie(Carte &carte) {
    delete[] carte.denumire;
    delete[] carte.autor;
    delete[] carte.editura;
}

// Funcție pentru compararea a două cărți după denumire
bool comparareDenumire(const Carte &carte, const char *denumire) {
    return strcmp(carte.denumire, denumire) == 0;
}

int main() {
    Carte carte1, carte2;

    // Citirea datelor pentru Carte 1
    char denumire1[100], autor1[100], editura1[100];
    int volumPagini1, anEditie1;
    
    cout << "Introduceti datele pentru Carte 1:\n";
    
   cout << "Denumire: ";
   cin.getline(denumire1, sizeof(denumire1));
    
    cout << "Autor: ";
    cin.getline(autor1, sizeof(autor1));
    
    cout << "Editura: ";
    cin.getline(editura1, sizeof(editura1));
    
    cout << "Volum de pagini: ";
    cin >> volumPagini1;
    
    cout << "An de editie: ";
    cin >> anEditie1;

    setareCarte(carte1, denumire1, autor1, editura1, volumPagini1, anEditie1);

    // Citirea datelor pentru Carte 2
    char denumire2[100], autor2[100], editura2[100];
    int volumPagini2, anEditie2;
    
    cin.ignore(); // Ignorăm newline-ul rămas în buffer
    
    cout << "\nIntroduceti datele pentru Carte 2:\n";
    
    cout << "Denumire: ";
    cin.getline(denumire2, sizeof(denumire2));
    
    cout << "Autor: ";
    cin.getline(autor2, sizeof(autor2));
    
    cout << "Editura: ";
    cin.getline(editura2, sizeof(editura2));
    
    cout << "Volum de pagini: ";
    cin >> volumPagini2;
    
    cout << "An de editie: ";
    cin >> anEditie2;

    setareCarte(carte2, denumire2, autor2, editura2, volumPagini2, anEditie2);

    // Căutarea cărții după denumire
    char denumireCautata[100];
    
    cin.ignore(); // Ignorăm newline-ul rămas în buffer
    
   cout << "\nIntroduceti denumirea cartii cautate: ";
   cin.getline(denumireCautata, sizeof(denumireCautata));
    
    if (comparareDenumire(carte1, denumireCautata)) {
        cout << "Cartea cu denumirea \"" << denumireCautata << "\" a fost gasita:\n";
        cout << "Autor: " << carte1.autor << "\nEditura: " << carte1.editura
                  << "\nVolum de pagini: " << carte1.volumPagini << "\nAn de editie: " << carte1.anEditie << "\n";
    } else if (comparareDenumire(carte2, denumireCautata)) {
        cout << "Cartea cu denumirea \"" << denumireCautata << "\" a fost gasita:\n";
        cout << "Autor: " << carte2.autor << "\nEditura: " << carte2.editura
                  << "\nVolum de pagini: " << carte2.volumPagini << "\nAn de editie: " << carte2.anEditie << "\n";
    } else {
        cout << "Cartea cu denumirea \"" << denumireCautata << "\" nu a fost gasita.\n";
    }

    // Eliberarea memoriei
    eliberareMemorie(carte1);
    eliberareMemorie(carte2);

    return 0;
}
