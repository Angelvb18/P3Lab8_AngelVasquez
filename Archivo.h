#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "Usuario.h"
#include "Post.h"
#include "Comentario.h"
#include<iostream>
#include<vector>
using std::vector;
#include <string>
using std::string;
#include <fstream>
using std::ofstream;
using std::ifstream;
class Archivo
{
	public:
		Archivo(string);
		bool guardarUsuarios(vector<Usuario*>);
		bool abrirEscritura();
		bool cerrarEscritura();
		void abirLectura();
		void cerrarLectura();
		vector<Usuario*> leerUsuario();
	protected:
		string fileName;
		ofstream outputFile;
		ifstream inputFile;
		int modoEscritura;
};

#endif
