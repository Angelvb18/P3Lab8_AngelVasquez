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
int main() {
	vector<Usuario*>listaUsuario;
	int opcion;
	string usuario , contrasena , nombre;
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
					if(usuario == listaUsuario[i]->getUsser() && contrasena == == listaUsuario[i]->getPassword()){
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
	
}
