#ifndef ENCRIPTADO_H
#define ENCRIPTADO_H
#include <cstddef>

unsigned char* encriptacion(const unsigned char* original,int desplazamiento,int clave, size_t n);

#endif