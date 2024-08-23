#include <iostream>

template <typename T>
void adicionarElemento(T*& array, int& size, T newElement);
void criarString(char*& string, int& size, const char* message);

int main() {
    char* string = new char[0];
    int sizeString = 7;

    criarString(string, sizeString, "Gabriel");

    string[1] = 'e';

    std::cout << string << '\n';
}

template <typename T>
void adicionarElemento(T*& array, int& size, T newElement) {
    T* newArray = new T[size + 1];

    for(int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }

    newArray[size] = newElement;
    size++;
    delete array;

    array = newArray;
}

void criarString(char*& string, int& size, const char* message) {
    for(int i = 0; i < size; i++) {
        string[i] = message[i];
    }

    string[size] = '\0';
}