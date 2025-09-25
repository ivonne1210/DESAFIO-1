#include "LZ78_com.h"
#include <iostream>
#include <fstream>
using namespace std;

unsigned char* leerArchivo(const char* nombreArchivo, size_t &tamano) {
    ifstream archivo(nombreArchivo, ios::binary | ios::ate);
    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return nullptr;
    }

    tamano = archivo.tellg();
    archivo.seekg(0, ios::beg);

    unsigned char* buffer = new unsigned char[tamano + 1]; // +1 solo si quieres poner un 0 final
    archivo.read(reinterpret_cast<char*>(buffer), tamano);

    buffer[tamano] = 0; // null-byte opcional, por si quieres tratarlo como texto
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
