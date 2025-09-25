#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "LZ78_com.h"
#include "RLE_com.h"
#include "Encriptado.h"
#include "Busqueda.h"

using namespace std;

int main() {
    size_t tam, tam1, outTam;
    unsigned char* contenido = leerArchivo("ejemplo.txt", tam);
    unsigned char* encrip = leerArchivo("Encriptado3.txt", tam1);
    if (contenido && encrip) {
        unsigned char* compresion = comprimirRLE(contenido, tam, outTam);
        //bool estado = Buscar(compresion, encrip);

        //unsigned char* encriptado = encriptacion(compresion, 3, 0x40);

        for (size_t i = 0; i < outTam; i++) {
            printf("%02X ", compresion[i]);
        }
    printf("\n");
        delete[] contenido;
        delete[] compresion;
       // delete[] encriptado;
    }
    return 0;
}