#include <cstddef>
#include <iostream>

// Descomprimir LZ78
unsigned char* descomprimirLZ78(const unsigned char* entrada, size_t n, size_t &k) {
    // Reservamos memoria para la salida (peor caso: n * 3)
    unsigned char* salida = new unsigned char[n * 3];
    k = 0;

    size_t pos = 0; // posición de lectura en entrada

    while (pos < n) {
        unsigned char sep = entrada[pos];
        unsigned char indice = entrada[pos + 1]; // índice de referencia
        unsigned char c = entrada[pos + 2];     // nuevo carácter
        pos += 3;

        // reconstruir cadena desde el índice
        unsigned char stack[1024]; // pila temporal para guardar la secuencia
        int top = 0;

        while (indice != 0) {
            unsigned char prev_indice = entrada[(indice * 3) - 2]; // índice anterior
            unsigned char prev_char   = entrada[(indice * 3)-1];     // carácter guardado

            stack[top++] = prev_char; // guardamos carácter en la pila
            indice = prev_indice;     // seguimos retrocediendo
        }

        // vaciar pila en salida
        while (top > 0) {
            salida[k++] = stack[--top];
        }

        // agregar el nuevo carácter
        salida[k++] = c;
    }

    salida[k] = '\0'; // terminamos con null
    return salida;
}
