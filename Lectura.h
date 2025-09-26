#ifndef LECTURA_H
#define LECTURA_H

#include <cstddef> // para size_t

unsigned char *leerArchivo(const char *nombreArchivo, size_t &tamano);
char *LZ78compresion(char *caracter1);

#endif
