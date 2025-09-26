#include <cstddef>
#include <LZ78_comp.h>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>


unsigned char* comprimirLZ78(const unsigned char* entrada, size_t n, size_t &pos_salida) {
    unsigned char* salida = new unsigned char[3 * n];
    pos_salida =0 ;

    // Diccionario: guardamos hasta n frases
    const unsigned char* diccionario[256]; // punteros a frases
    size_t longitudes[256];                // longitudes de cada frase
    size_t dict_size = 0;

    size_t i = 0;
    while (i < n) {
        int indice = 0;  // índice encontrado en el diccionario
        size_t len = 0;

        // Buscar la coincidencia más larga en el diccionario
        for (size_t d = 0; d < dict_size; ++d) {
            size_t l = 0;
            while (l < longitudes[d] && i + l < n && entrada[i + l] == diccionario[d][l]) {
                ++l;
            }
            if (l == longitudes[d] && l > len) {
                indice = d + 1; // índices desde 1
                len = l;
            }
        }

        // El siguiente carácter que extiende la frase
        unsigned char nuevoChar = (i + len < n) ? entrada[i + len] : 0;

        // Guardar en salida: [indice][caracter][\0]
        salida[pos_salida++] = '\0';
        salida[pos_salida++] = (unsigned char)indice;
        salida[pos_salida++] = nuevoChar;


        // Agregar nueva frase al diccionario
        if (dict_size < 256 && i + len < n) {
            diccionario[dict_size] = entrada + i;
            longitudes[dict_size] = len + 1;
            dict_size++;
        }

        i += len + 1;
    }

    return salida;
}
