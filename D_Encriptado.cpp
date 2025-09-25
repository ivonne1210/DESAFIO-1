#include "D_Encriptado.h"
#include <cstddef>

unsigned char* desencriptado(const unsigned char* encrip, int rotacion, int clave, size_t n){
    unsigned char* salida = new unsigned char[n];
        for(unsigned int i = 0; i<n; i++){
            unsigned char aux = encrip[i] ^ clave;
            salida[i] = (aux >> rotacion) | (aux << (8 - rotacion));
        }
    return salida;
}