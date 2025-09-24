#include <iostream>
#include <fstream>
#include "RLE_descom.h"
#include <cstring>
using std::strlen;

char* descomprimirRLE(const char* entrada) {
    unsigned int n = strlen(entrada);

    // Peor caso: cada par número-caracter representa un solo caracter → n/2 repeticiones máximas
    // Pero como no sabemos cuántas repeticiones hay, asumimos una expansión máxima razonable
    char* salida = new char[n * 9 + 1]; // reserva generosa
    unsigned int longitud = 0;

    unsigned int i = 0;
    while (i < n) {
        // leer número
        char numero[20];
        int k = 0;
        while (i < n && isdigit(entrada[i]) && k < 19) {
            numero[k++] = entrada[i++];
        }
        numero[k] = '\0';
        int repeticiones = atoi(numero);

        // leer caracter
        if (i < n) {
            char caracter = entrada[i++];

            // escribir repeticiones
            for (int r = 0; r < repeticiones; ++r) {
                salida[longitud++] = caracter;
            }
        }
    }

    salida[longitud] = '\0';
    return salida;
}