#include "Busqueda.h"
#include "Encriptado.h"
#include "D_Encriptado.h"
#include "LZ78_descomp.h"
#include <cstddef>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool BuscarRLE(const unsigned char *entrada,
            const unsigned char *encriptado,
            size_t nEntrada,
            size_t nEncrip,
            int &rotEncontrada,
            int &claveEncontrada)
{
    for (int rot = 0; rot < 8; rot++) {
        for (int clave = 0; clave < 256; clave++) {
            unsigned char *candidata = encriptacion(entrada, rot, clave, nEntrada);

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

bool matchComprimido(const unsigned char *pista,
                     size_t nPista,
                     const unsigned char *texto,
                     size_t nTexto)
{
    size_t iP = 0, iT = 0;

    while (iP < nPista && iT < nTexto) {
        // comparar bloque completo (3 bytes)
        if (pista[iP] != texto[iT] || pista[iP + 2] != texto[iT + 2]) {
            return false;
        }

        // avanzar en la pista y en el texto
        iP += 3;
        iT += 3;
    }

    // debe consumirse toda la pista
    return (iP >= nPista);
}

bool BuscarLZ(const unsigned char* encriptado,
              size_t nEncriptado,
              const unsigned char* pista,
              size_t nPista,
              int &rotEn,
              int &claveEn)
{
    for (int rot = 0; rot < 8; rot++) {
        for (int clave = 0; clave <= 255; clave++) {
            unsigned char *descrip = desencriptado(encriptado, rot, clave, nEncriptado);

            if (descrip[0] != 0x00) {
                delete[] descrip;
                continue;
            }

            size_t tReal;
            unsigned char* descom = descomprimirLZ78(descrip, nEncriptado, tReal);
            delete[] descrip;

            if (!descom || tReal == 0) {
                delete [] descom;
                continue;
            }

            bool encontrado = false;
            for (size_t pos = 0; pos + nPista <= tReal; pos++) {
                if (memcmp(descom + pos, pista, nPista) == 0) {
                    encontrado = true;
                    rotEn = rot;
                    claveEn = clave;
                    break;
                }
            }
            if (encontrado) {
                cout << descom << endl;
                delete[] descom;
                return true;
            }
            delete[] descom;
        }
    }
    return false;
}

