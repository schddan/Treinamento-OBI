#include <iostream>

// JAMAIS RESSIGNIFIQUE O VALOR DO NEGOCIO, cleana ele
template <typename T>
struct Vector
{
    T* vector;
    int size;

    void clear() {
        delete this->vector;
        vector = new T[0];
        size = 0;
    }

    ~Vector() {
        delete this->vector;
    }
};

class String
{
private:
    int string_size = 0;

public:
    const char* string;

    String(const char* string)
    {
        this->string = string;
    }

    int size()
    {
        string_size = 0;
        for (int i = 0; string[i]; i++, string_size++);
        return string_size;
    }

    String& operator=(const char* string)
    {
        this->string = string;
        return *this;
    }
};

template <typename T>
void adicionarElemento(T *&array, int &size, T newElement);
const char* concatenarStrings(const char*& stringUm, const char*& stringDois);

int main()
{

    // adicionar int em um vector
    Vector<int> numeros = {new int[0]};
    adicionarElemento(numeros.vector, numeros.size, 2);
    std::cout << numeros.vector[0] << '\n';
    adicionarElemento(numeros.vector, numeros.size, 5);
    std::cout << numeros.vector[1] << '\n';

    // cleanando esse vector
    numeros.clear();
    adicionarElemento(numeros.vector, numeros.size, 7);
    std::cout << numeros.vector[0] << '\n';

    // adicionar char a um vector
    Vector<char> chars = {new char[0]};
    adicionarElemento(chars.vector, chars.size, 'a');
    std::cout << chars.vector[0] << '\n';

    // criar uma string
    String nome = "Gabriel";
    std::cout << nome.string << '\n';
    std::cout << nome.size() << '\n';

    // ressignificando essa string
    nome = "Daniel";
    std::cout << nome.string << '\n';
    std::cout << nome.size() << '\n';

    // ressignificando essa string
    nome = concatenarStrings(nome.string, nome.string);
    std::cout << nome.string << '\n';
    std::cout << nome.size() << '\n';
}

template <typename T>
void adicionarElemento(T *&array, int &size, T newElement)
{
    T *newArray = new T[size + 1];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }

    newArray[size] = newElement;
    size++;
    delete array;

    array = newArray;
}

const char* concatenarStrings(const char*& stringUm, const char*& stringDois)
{
    int sizeOne = 0;
    int sizeTwo = 0;

    for (int i = 0; stringUm[i]; i++, sizeOne++);
    for (int i = 0; stringDois[i]; i++, sizeTwo++);

    char *finalString = new char[sizeOne + sizeTwo + 1];

    for (int i = 0; i < sizeOne; i++)
    {
        finalString[i] = stringUm[i];
    }

    for (int i = sizeOne; i < sizeOne + sizeTwo; i++) {
        finalString[i] = stringDois[i - sizeOne];
    }

    finalString[sizeOne + sizeTwo] = '\0';

    return finalString;
}