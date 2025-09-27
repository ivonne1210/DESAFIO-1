#ifndef BUSQUEDA_H
#define BUSQUEDA_H
#include <cstddef>

bool BuscarRLE(const unsigned char *entrada,
            const unsigned char *encriptado,
            size_t nEntrada,
            size_t nEncrip,
            int &rotEncontrada,
            int &claveEncontrada);

bool matchComprimido(const unsigned char *pista,
                     size_t nPista,
                     const unsigned char *texto,
                     size_t nTexto);

bool BuscarLZ(const unsigned char* encriptado,
              size_t nEncriptado,
              const unsigned char* pista,
              size_t nPista,
              int &rotEn,
              int &claveEn);

#endif
