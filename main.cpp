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
#include "D_Encriptado.h"
#include "RLE_descom.h"

using namespace std;

int main() {
    size_t tam, tam1, outTam, salTam;
    unsigned char* contenido = leerArchivo("ejemplo.txt", tam);
    unsigned char* encrip = leerArchivo("Encriptado1.txt", tam1);
    if (contenido && encrip) {
        unsigned char* compresion = comprimirRLE(contenido, tam, outTam);
        int rot, clave;
        bool estado = Buscar(compresion, encrip, outTam, tam1, rot, clave);

        if (estado){
            delete[] contenido;
            delete[] compresion;
            unsigned char* descrip = desencriptado(encrip, rot, clave, tam1);
            unsigned char* descom = descomprimirRLE(descrip, tam1, salTam);
            cout << descom;
        }
    
        delete[] contenido;
        delete[] compresion;
        delete[] encrip;
    }
    return 0;
}