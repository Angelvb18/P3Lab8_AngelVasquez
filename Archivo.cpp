#include "Archivo.h"
#include <sstream>
using std::stringstream;
Archivo::Archivo(string pFileName)
{
	fileName = pFileName;
}
bool Archivo::guardarUsuarios(vector<Usuario*>usuarios){
	if(outputFile.is_open()){
		
		for (int i = 0 ; i < usuarios.size() ; i++){
			outputFile << usuarios[i]->getNombre() <<';'<<usuarios[i]->getUsser()<<';'<<usuarios[i]->getPassword() <<';';
			for(int j = 0 ; j < usuarios[i]->getPosts().size() ; j++ ){
				outputFile << usuarios[i]->getPosts()[j]->getTitulo() <<','<<usuarios[i]->getPosts()[j]->getContenido()<<','<<usuarios[i]->getPosts()[j]->getLikes()
				<<','<< usuarios[i]->getPosts()[j]->getHates() << ','<<'|';
			}
			if(i != usuarios.size()-1){
				outputFile << '\n';
			}
		}
		return true;
	}else
		return false;
}
bool Archivo::cerrarEscritura(){
	outputFile.close();
	return !outputFile.is_open();
}
bool Archivo::abrirEscritura(){
	outputFile.open(fileName.c_str());
	return outputFile.is_open();
}
vector<Usuario*> Archivo::leerUsuario(){
	ifstream inputFile("Usuarios.csv");
	vector<Usuario*>retval;
	if(inputFile.is_open()){
		while(!inputFile.eof()){
			string name,usuario,contra,titulo,contenido,post,likess,hatess;
			vector<string>posts;
			int like,hate;
			string buffer;
			getline(inputFile,buffer);
			stringstream myStream;
			myStream << buffer;
			getline(myStream,name,';');
			getline(myStream,usuario,';');
			getline(myStream,contra,';');
			getline(myStream,post,';');
			Usuario* usuariocargado = new Usuario(name,usuario,contra);
			string auxiliar = "";
			for(int i = 1 ; i < post.size() ; i++){
				if(post[i] == '|' ){
					posts.push_back(auxiliar);
					auxiliar = "";
				}else{
					auxiliar+=post[i];
				}
			}
			int cont = 1;
			auxiliar = "";
			for(int i = 0 ; i < posts.size() ; i++){
               for(int j = 0 ; j < posts[i].size() ; j++){
               		if(posts[i][j] == ','){
						if(cont == 1){
							titulo = auxiliar;
						}else{
							if(cont == 2 ){
								contenido = auxiliar;
							}else{
								if(cont == 3){
									likess = auxiliar;
								}else{
									if(cont == 4){
										hatess = auxiliar;
									}
								}
								
							}
						}
						auxiliar = "";
						if(cont == 4){
							stringstream myStream2(likess);
							myStream2 >> like;
							stringstream myStream3(hatess);
							myStream2 >> hate;
							usuariocargado->setPost(new Post(titulo,contenido,like,hate));
							
							cont = 1;
						}else{
							cont++;
						}
				}else{
					auxiliar+=posts[i][j];
				}		              		
			}
		}
			retval.push_back(usuariocargado);	
		}
		inputFile.close();
		return retval;	
	}else{
		inputFile.close();
		std::cout << "Exlente";
		return retval;
	}
}
