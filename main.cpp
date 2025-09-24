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
    size_t tam, tam1;
    char* contenido = leerArchivo("ejemplo.txt", tam);
    char* encrip = leerArchivo("Encriptado3.txt", tam1);
    if (contenido && encrip) {
        char* compresion = comprimirRLE(contenido);
        bool estado = Buscar(compresion, encrip);
        cout << estado << endl;

        delete[] contenido;
        delete[] compresion;
    }
    return 0;
}