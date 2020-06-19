#include <iostream>
#include <string>
#include <string>
#include <vector>
using namespace std;
#include "Usuario.h"
#include "Post.h"
#include "Comentario.h"
#include "Archivo.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Inicio(vector<Usuario*>& , Usuario*&);
Archivo* archivo = new Archivo("Usuarios.csv"); 
void Leercadenas(string&,string&);
int main() {
	vector<Usuario*>listaUsuario;
	int opcion;
	string usuario , contrasena , nombre;
	listaUsuario =archivo->leerUsuario();
	do{
		cout << "1.Ingresar\n2.Registrar\n3.Salir\nIngrese una opcion:";
		cin>>opcion;
		switch(opcion){
			case 1:{
				cout << "Usuario:";
				cin >> usuario;
				cout << "Contraseña:";
				cin >> contrasena;
				int posicion = -1;
				for(int i = 0 ; i < listaUsuario.size() ; i++){
					if(usuario == listaUsuario[i]->getUsser() && contrasena == listaUsuario[i]->getPassword()){
					     posicion = i;
					}
				}
				if(posicion != -1){
					Inicio(listaUsuario,listaUsuario[posicion]);
				}else{
					cout << "Contrasena o Usuario no valido" << endl;
				}
				break;
			}
			case 2:{
			    cout << "Usuario:";
				cin >> usuario;
				cout << "Contraseña:";
				cin >> contrasena;
				cout << "Nombre:";
				cin >> nombre;
				listaUsuario.push_back(new Usuario(nombre,usuario,contrasena));
				archivo->abrirEscritura();
				archivo->guardarUsuarios(listaUsuario);
				archivo->cerrarEscritura();				
				break;
			}	
			case 3:{
				cout << "Adios" << endl;
				break;
			}	
			default:{
				break;
			}
		}
	}while(opcion!=3);
}
void Inicio(vector<Usuario*>& Lista, Usuario*& Yo){
	cout << "Bienvenido " << Yo->getNombre() << endl;
    
	int opcion2,sigoA =-1;
	do{
		cout << "1.Crear post\n2.Comentar post\n3.Dar like\n4.Dar hate\n5.Seguir usuario\n6.Dejar de seguir a un usuario\n7.Salir\nIngrese una opcion:";
		cin >> opcion2;
		switch(opcion2){
			case 1:{
			    string titulo,contenido;
				Leercadenas(titulo,contenido);
				Yo->setPost(new Post(titulo,contenido));
				archivo->abrirEscritura();
				archivo->guardarUsuarios(Lista);
				archivo->cerrarEscritura();
				break;
			}
			case 2:{
				if(sigoA != -1){
					int posipost;
					for(int i = 0 ; i <Lista[sigoA]->getPosts().size() ; i++){
						cout << i <<"."<<Lista[sigoA]->getPosts()[i]->getTitulo() << " " << Lista[sigoA]->getPosts()[i]->getContenido() << endl;
					}
					cout << "Numero de post:";
					cin >> posipost;
					string a ;
					cout << "Contenido:";
	                getline(cin,a);
	                getline(cin,a);
	                Lista[sigoA]->getPosts()[posipost]->setComentario(new Comentario(Yo->getUsser(),a));
	                archivo->abrirEscritura();
				    archivo->guardarUsuarios(Lista);
				    archivo->cerrarEscritura();
				}else{
					cout << "No sigue a nadie"<<endl;
				}
				break;
			}
			case 3:{
				if(sigoA != -1){
					int posipost;
					for(int i = 0 ; i <Lista[sigoA]->getPosts().size() ; i++){
						cout << i <<"."<<Lista[sigoA]->getPosts()[i]->getTitulo() << " " << Lista[sigoA]->getPosts()[i]->getContenido() << endl;
					}
					cout << "Numero de post:";
					cin >> posipost;
					Lista[sigoA]->getPosts()[posipost]->setLikes();
					archivo->abrirEscritura();
				    archivo->guardarUsuarios(Lista);
				    archivo->cerrarEscritura();
				}else{
					cout << "No sigue a nadie"<<endl;
				}
				break;
			}
			case 4:{
				if(sigoA != -1){
					int posipost;
					for(int i = 0 ; i <Lista[sigoA]->getPosts().size() ; i++){
						cout << i <<"."<<Lista[sigoA]->getPosts()[i]->getTitulo() << " " << Lista[sigoA]->getPosts()[i]->getContenido() << endl;
					}
					cout << "Numero de post:";
					cin >> posipost;
					Lista[sigoA]->getPosts()[posipost]->setHates();
					archivo->abrirEscritura();
					archivo->guardarUsuarios(Lista);
					archivo->cerrarEscritura();
				}else{
					cout << "No sigue a nadie"<<endl;
				}
				break;
			}
			case 5:{
				for(int i = 0 ; i < Lista.size() ; i++){
					cout << i <<"."<< Lista[i]->getNombre() << endl;
				}
				do{
					cout << "Ingrese  el numero de quien va a seguir:";
					cin >> sigoA;
				}while(sigoA >= Lista.size() || sigoA < 0);
				break;
			}
			case 6:{
				if(sigoA != -1){
					sigoA = -1;
				}else{
					cout << "No sigue a nadie"<<endl;
				}
				break;
			}
			case 7:{
				cout << "Adios"<< endl;
				break;
			}
		}
	}while(opcion2!=7);
}
void Leercadenas(string&a,string& b){
	cout << "Titulo:";
	getline(cin,a);
	getline(cin,a);
	cout << "Contenido:";
	getline(cin,b);
}
