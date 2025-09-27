#include "Busqueda.h"
#include "D_Encriptado.h"
#include "Lectura.h"
#include "RLE_com.h"
#include "RLE_descom.h"
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int cantidad = 0;
    cout << "Ingrese el numero de documentos a desencriptar: ";
    cin >> cantidad;
    cout << endl;
    for(int i=1; i<=cantidad; i++){
        char nombrePista[64], nombreEncrip[64];
        sprintf(nombrePista, "Pista%d.txt", i);
        sprintf(nombreEncrip, "Encriptado%d.txt", i);
        cout << "\n=== Texto " << i << " ===" << endl;
        size_t tam, tam1, outTam, salTam;
        unsigned char *contenido = leerArchivo(nombrePista, tam);
        unsigned char *encrip = leerArchivo(nombreEncrip, tam1);

        if (contenido && encrip) {
            int rot, clave;
            bool estado = BuscarLZ(encrip, tam1, contenido, tam, rot, clave);
            if (estado) {
                cout << "Compresion: LZ78" << endl;
                cout << "Rotacion: " << rot << endl;
                cout << "Clave: " << clave << endl;
                delete [] contenido;
                delete [] encrip;
            }
            else{
                unsigned char *compresion = comprimirRLE(contenido, tam, outTam);
                bool estado_RLE = BuscarRLE(compresion, encrip, outTam, tam1, rot, clave);

                if(estado_RLE){
                    delete[] contenido;
                    delete[] compresion;
                    unsigned char *descrip = desencriptado(encrip, rot, clave, tam1);
                    unsigned char *descom = descomprimirRLE(descrip, tam1, salTam);
                    cout << descom << endl;
                    cout << "Compresion: RLE" << endl;
                    cout << "Rotacion: " << rot << endl;
                    cout << "Clave: " << clave << endl;
                    delete[] descrip;
                    delete[] descom;
                    delete[] encrip;
                }
                else{
                    cout << "No se encontro un metodo compatible con una clave y rotacion."<<endl;
                    delete[] encrip;
                    delete[] contenido;
                }
            }
        }
    }
    return 0;
}
