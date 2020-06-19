#include "Usuario.h"
Usuario::Usuario(string name,string user,string contrasena){
    nombre = name;
    usser = user;
    password = contrasena;
}
void Usuario::setPost(Post* nuevo){
	Posts.push_back(nuevo);
}
void Usuario::seguir(vector<Post*>& postsegido){
    sigo = postsegido;
}
