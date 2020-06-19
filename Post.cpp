#include "Post.h"
Post::Post(string titulo , string contenido){
	this->titulo = titulo;
	this->contenido = contenido;
	likes = 0;
	hates = 0;
}
Post::Post(string titulo , string contenido , int like , int hate){
	this->titulo = titulo;
	this->contenido = contenido;
	likes = like;
	hates = hate;
}
void Post::setComentario(Comentario* nuevo){
	comentarios.push_back(nuevo);
}
void Post::setLikes(){
	likes++;
}
void Post::setHates(){
	hates++;
}
