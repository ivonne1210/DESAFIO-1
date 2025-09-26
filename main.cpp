#include "Busqueda.h"
#include "D_Encriptado.h"
#include "Encriptado.h"
#include "LZ78_com.h"
#include "RLE_com.h"
#include "RLE_descom.h"
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    size_t tam, tam1, outTam, salTam;
    unsigned char *contenido = leerArchivo("Pista3.txt", tam);
    unsigned char *encrip = leerArchivo("Encriptado3.txt", tam1);
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
    }
    return 0;
}
