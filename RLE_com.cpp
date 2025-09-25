#include "RLE_com.h"
#include <cstring>
#include <cstddef>
using std::strlen;


unsigned char* comprimirRLE(const unsigned char* entrada, size_t n, size_t &outSize) {

    // Peor caso: cada caracter diferente → 2*n
    unsigned char* salida = new unsigned char[3 * n];
    outSize = 0;

    unsigned int i = 0;
    while (i < n) {

        char actual = entrada[i];
        int contador = 1;

        // contar repeticiones
        while (i + contador < n && entrada[i + contador] == actual) {
            ++contador;
        }

        salida[outSize++] = '\0';

        salida[outSize++] = (unsigned char)contador;

        // escribir el caracter
        salida[outSize++] = actual;

        // avanzar
        i += contador;
    }
    return salida;
}