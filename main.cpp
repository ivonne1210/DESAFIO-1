#include "Busqueda.h"
#include "D_Encriptado.h"
#include "Encriptado.h"
#include "Lectura.h"
#include "RLE_com.h"
#include "RLE_descom.h"
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <LZ78_comp.h>

using namespace std;

int main()
{
    size_t tam; //tam1, outTam,
    size_t salTam;
    unsigned char *contenido = leerArchivo("Pista2.txt", tam);

    /*unsigned char *encrip = leerArchivo("Encriptado3.txt", tam1);

    if (contenido && encrip) {
        unsigned char *compresion = comprimirRLE(contenido, tam, outTam);
        int rot, clave;
        bool estado = Buscar(compresion, encrip, outTam, tam1, rot, clave);


        if (estado) {
            delete[] contenido;
            delete[] compresion;
            unsigned char *descrip = desencriptado(encrip, rot, clave, tam1);
            unsigned char *descom = descomprimirRLE(descrip, tam1, salTam);
            cout << descom;
            delete[] descrip;
            delete[] descom;
        }
        delete[] encrip;
    }*/


    unsigned char *comprimido = comprimirLZ78(contenido, tam, salTam);
    unsigned char *encriptar = encriptacion(comprimido,3,0x5A,salTam);
    for (int var = 0; var < salTam; ++var) {
          printf("%02X",encriptar[var], " ");
    }

    delete[] comprimido;
    delete[] encriptar;

    return 0;
}
