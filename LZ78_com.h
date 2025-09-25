#ifndef LZ78_COM_H
#define LZ78_COM_H

#include <cstddef> // para size_t

unsigned char* leerArchivo(const char* nombreArchivo, size_t &tamano);
char* LZ78compresion(char *caracter1);

#endif