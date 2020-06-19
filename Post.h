#ifndef POST_H
#define POST_H
#include "Comentario.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Post
{
	public:
		Post(string ,string);
		Post(string ,string,int,int);
		string getTitulo(){return titulo;}
		string getContenido(){return contenido;}
		int getLikes(){return likes;}
		int getHates(){return hates;}
		void setComentario(Comentario*);
		void setLikes();
		void setHates();
		vector<Comentario*> getComentarios(){return comentarios;}
	protected:
	   string titulo,contenido;
	   int likes,hates;
	   vector<Comentario*>comentarios;
};

#endif
