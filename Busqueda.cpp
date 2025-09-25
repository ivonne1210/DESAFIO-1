#include "Busqueda.h"
#include "Encriptado.h"
#include <cstring>
#include <cstdint>

bool Buscar(const char* entrada, const char* encriptado) {
    size_t nEntrada = strlen(entrada);
    size_t nEncrip  = strlen(encriptado);

    for (int rot = 0; rot < 8; rot++) {
        for (int clave = 0; clave < 256; clave++) {
            unsigned char* candidata = encriptacion(entrada, rot, clave);

            // Buscar candidata dentro de encriptado
            for (size_t pos = 0; pos + nEntrada <= nEncrip; pos++) {
                bool match = true;
                for (size_t j = 0; j < nEntrada; j++) {
                    if (candidata[j] != encriptado[pos + j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    delete[] candidata;
                    return true;
                }
            }
        delete[] candidata;
        }
    }
return false;
}