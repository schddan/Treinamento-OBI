#include <iostream>

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

const char* concatenarStrings(const char*& stringUm, const char*& stringDois);

int main()
{

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