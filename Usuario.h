#ifndef USUARIO_H
#define USUARIO_H
#include "Post.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Usuario
{
	public:
		Usuario(string,string,string);
		string getNombre(){return nombre;}
		string getUsser(){return usser;}
		string getPassword(){return password;}
		vector<Post*>getPosts(){return Posts;}
		vector<Post*>getSigo(){return sigo;}
		void seguir(vector<Post*>&);
		void setPost(Post*);
	protected:
		string nombre,usser,password;
		vector<Post*>Posts;
		vector<Post*>sigo;
};

#endif
