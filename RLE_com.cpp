#include "RLE_com.h"
#include <cstring>
using std::strlen;


char* comprimirRLE(const char* entrada) {
    unsigned int n = strlen(entrada);

    // Peor caso: cada caracter diferente → 2*n
    char* salida = new char[2 * n + 1];
    unsigned int longitud = 0;

    unsigned int i = 0;
    while (i < n) {
        char actual = entrada[i];
        int contador = 1;

        // contar repeticiones
        while (i + contador < n && entrada[i + contador] == actual) {
            ++contador;
        }

        salida[longitud++] = '0' + contador;

        // escribir el caracter
        salida[longitud++] = actual;

        // avanzar
        i += contador;
    }

    salida[longitud] = '\0';
    return salida;
}