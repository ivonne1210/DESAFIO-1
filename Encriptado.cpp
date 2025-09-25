#include "Encriptado.h"
#include <cstring>

#include <iostream>
#include <cstring>
using std::strlen;
using namespace std;

unsigned char* encriptacion(const char* original,int desplazamiento,int clave){
    unsigned int n = strlen(original);
    unsigned char* salida = new unsigned char[n + 1];
    for(unsigned int i = 0; i<n; i++){
        char rotado = (original[i] << desplazamiento) | (original[i] >> (8 - desplazamiento));
        salida[i] = rotado ^ clave;
    }

    salida[n] = '\0';
    return salida;
}