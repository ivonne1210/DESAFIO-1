#include "Busqueda.h"
#include "Encriptado.h"
#include <cstring>
#include <cstdint>
#include <cstddef>
#include <cstdio> 


bool Buscar(const unsigned char* entrada, const unsigned char* encriptado, size_t nEntrada, size_t nEncrip,
            int &rotEncontrada, int&claveEncontrada) {

    for (int rot = 0; rot < 8; rot++) {
        for (int clave = 0; clave < 256; clave++) {
            unsigned char* candidata = encriptacion(entrada, rot, clave, nEntrada);

            for (size_t pos = 0; pos + nEntrada <= nEncrip; pos += 3) {
                if (matchComprimido(candidata, nEntrada, encriptado + pos, nEncrip - pos)) {
                    rotEncontrada = rot;
                    claveEncontrada = clave;
                    delete[] candidata;
                    return true;
                }
            }
        delete[] candidata;
        }
    }
return false;
}

bool matchComprimido(const unsigned char* pista, size_t nPista,
                     const unsigned char* texto, size_t nTexto) {

    size_t iP = 0, iT = 0;

    while (iP < nPista && iT < nTexto) {
        // comparar bloque completo (3 bytes)
        if (pista[iP]     != texto[iT]     ||
            pista[iP + 2] != texto[iT + 2]) {
            return false;
        }

        // avanzar en la pista y en el texto
        iP += 3;
        iT += 3;
    }

    // debe consumirse toda la pista
    return (iP >= nPista);
}