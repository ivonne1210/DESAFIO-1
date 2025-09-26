#include "Lectura.h"
#include <fstream>
#include <iostream>
using namespace std;

unsigned char *leerArchivo(const char *nombreArchivo, size_t &tamano)
{
    ifstream archivo(nombreArchivo, ios::binary | ios::ate);
    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return nullptr;
    }

    tamano = archivo.tellg();
    archivo.seekg(0, ios::beg);

    unsigned char *buffer = new unsigned char[tamano + 1]; // +1 solo si quieres poner un 0 final
    archivo.read(reinterpret_cast<char *>(buffer), tamano);

    buffer[tamano] = 0; // null-byte opcional, por si quieres tratarlo como texto
    archivo.close();

    return buffer;
}


