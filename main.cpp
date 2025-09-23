#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "LZ78_com.h"
#include "RLE_com.h"

using namespace std;

int main() {
    size_t tam;
    char* contenido = leerArchivo("ejemplo.txt", tam);
    if (contenido) {
        char* compresion = comprimirRLE(contenido);

        cout << "Contenido (" << tam << " bytes):\n";
        cout << compresion << endl;
        delete[] contenido;
    }
    return 0;
}