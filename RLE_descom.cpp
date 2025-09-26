#include "RLE_descom.h"
#include <cstddef> // size_t

unsigned char *descomprimirRLE(const unsigned char *entrada, size_t nEntrada, size_t &nSalida)
{
    size_t capacidad = 256 * (nEntrada / 3 + 1);
    unsigned char *salida = new unsigned char[capacidad];

    nSalida = 0;
    size_t i = 0;

    while (i + 2 < nEntrada) {
        unsigned char sep = entrada[i];
        unsigned char count = entrada[i + 1];
        unsigned char ch = entrada[i + 2];
        i += 3;

        if (sep != 0x00) {
            delete[] salida;
            return nullptr;
        }

        for (unsigned int r = 0; r < count; r++) {
            salida[nSalida++] = ch;
        }
    }

    return salida;
}
