#include "Encriptado.h"
#include <cstddef>
#include <cstring>

unsigned char *encriptacion(const unsigned char *original, int desplazamiento, int clave, size_t n)
{
    unsigned char *salida = new unsigned char[n];
    for (unsigned int i = 0; i < n; i++) {
        char rotado = (original[i] << desplazamiento) | (original[i] >> (8 - desplazamiento));
        salida[i] = rotado ^ clave;
    }
    return salida;
}
