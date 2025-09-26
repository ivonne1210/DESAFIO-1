#ifndef BUSQUEDA_H
#define BUSQUEDA_H
#include <cstddef>

bool Buscar(const unsigned char *entrada,
            const unsigned char *encriptado,
            size_t nEntrada,
            size_t nEncrip,
            int &rotEncontrada,
            int &claveEncontrada);
bool matchComprimido(const unsigned char *pista,
                     size_t nPista,
                     const unsigned char *texto,
                     size_t nTexto);

#endif
