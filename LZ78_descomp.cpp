#include <cstddef>

// Descomprimir LZ78
unsigned char* descomprimirLZ78(const unsigned char* entrada, size_t n, size_t &k) {
    unsigned char* salida = new unsigned char[n * 3];
    k = 0;
    size_t pos = 0;

    while (pos + 2 < n) {
        unsigned char sep = entrada[pos];
        unsigned char indice = entrada[pos + 1];
        unsigned char c = entrada[pos + 2];
        pos += 3;

        unsigned char stack[1024];
        int top = 0;

        while (indice != 0) {

            if (indice >= pos / 3 || (indice * 3) >= n) {
                delete[] salida;
                return nullptr; // índice inválido
            }

            unsigned char prev_indice = entrada[(indice * 3) - 2];
            unsigned char prev_char   = entrada[(indice * 3) - 1];

            stack[top++] = prev_char;
            indice = prev_indice;
        }

        while (top > 0) {
            salida[k++] = stack[--top];
        }

        salida[k++] = c;
    }

    salida[k] = '\0';
    return salida;
}
