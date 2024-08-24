#include <iostream>

// JAMAIS RESSIGNIFIQUE O VALOR DO VECTOR, cleana ele
template <typename T>
struct Vector
{
    T* vector;
    int size = 0;

    ~Vector() {
        delete this->vector;
    }
};

template <typename T>
void adicionarElemento(Vector<T>& vector, T newElement);

template <typename T>
void limparVector(Vector<T>& vector);

int main()
{

    // adicionar int em um vector
    Vector<int> numeros = {new int[0]};
    adicionarElemento(numeros, 2);
    std::cout << numeros.vector[0] << '\n';
    adicionarElemento(numeros, 5);
    std::cout << numeros.vector[1] << '\n';
    std::cout << numeros.size << '\n';

    // cleanando esse vector
    limparVector(numeros);
    adicionarElemento(numeros, 7);
    std::cout << numeros.vector[0] << '\n';
    std::cout << numeros.size << '\n';

    // adicionar char a um vector
    Vector<char> chars = {new char[0]};
    adicionarElemento(chars, 'a');
    std::cout << "Variavel 0 de chars: " << chars.vector[0] << '\n';
    chars = {new char('e')};
    std::cout << "Variavel 0 de chars: " << chars.vector[0] << '\n';
}

template <typename T>
void adicionarElemento(Vector<T>& vector, T newElement)
{
    T *newArray = new T[vector.size + 1];

    for (int i = 0; i < vector.size; i++)
    {
        newArray[i] = vector.vector[i];
    }

    newArray[vector.size] = newElement;
    vector.size++;
    delete vector.vector;

    vector.vector = newArray;
}

template <typename T>
void limparVector(Vector<T>& vector) {
    delete vector.vector;
    vector.vector = new T[0];
    vector.size = 0;
}