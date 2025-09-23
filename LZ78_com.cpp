#include "LZ78_com.h"
#include <iostream>
#include <fstream>
using namespace std;

char* leerArchivo(const char* nombreArchivo, size_t &tamano) {
    ifstream archivo(nombreArchivo, ios::binary | ios::ate);
    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return nullptr;
    }

    tamano = archivo.tellg();
    archivo.seekg(0, ios::beg);

    char* buffer = new char[tamano + 1];
    archivo.read(buffer, tamano);
    buffer[tamano] = '\0';

    archivo.close();
    return buffer;
}

char* LZ78compresion(char *caracter1) {
    bool primero = true;
    if(primero){
        char * buffer = new char[2];
        buffer[0]=*caracter1;
        buffer[1] = '\0';
        primero = false;
    }
    return caracter1;
}
