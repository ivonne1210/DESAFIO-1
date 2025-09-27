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
#include "LZ78_descomp.h"

using namespace std;

int main()
{
    size_t tam; //tam1, outTam,
    size_t salTam;
    unsigned char *contenido = leerArchivo("Encriptado2.txt", tam);

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


    unsigned char *comprimido = desencriptado(contenido, 3,0x5A, tam);
    unsigned char *encriptar = descomprimirLZ78(comprimido, tam, salTam);
    cout << encriptar;
    delete[] comprimido;
    delete[] encriptar;


    return 0;
}
