#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <iostream>
#include <string>
using namespace std;
class Comentario
{
	public:
		Comentario(string ,string);
		string getUsser(){return usser;}
		string getContenido(){return contenido;}
	protected:
		string usser,contenido;
		
};

#endif
