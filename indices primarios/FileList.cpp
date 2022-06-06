#include "FileList.h"
FileList::FileList(string filename){
	this -> filename = filename;
	
}
void FileList::add(User obj){
	int fileindex;
	//cout<<"Entramos al archivo"<<endl;
	//cout<<"es "<<obj.toString();
	ofstream fout(filename, ios::binary | ios::app);
	fout.seekp(0,ios::end);
	fileindex= fout.tellp();
	fout.write((char*) &obj, sizeof(User));
	Index index(fileindex,obj.get_usuario());
	indexList.insertaordenado(index);
}
void FileList::showallorder(){
	User obj;
	string cadena;
	//cout<<"Entramos a show";
	ifstream fin(filename,ios::binary);
	for(int i= 0;i <= indexList.get_count();i++){
		//cout<<" La i es"<<i<<endl;
		Index indexobj=indexList[i];
		fin.seekg(indexobj.getIndex(), ios::beg);
		fin.read((char*) &obj,sizeof(User));
		cadena=indexobj.get_primarykey();
		if(cadena[0]!='@')
			cout<<obj.toString()<<endl;
		fflush(stdin);
	}
	system("pause");
		
}
void FileList::showallindex(){
	User obj;
	string cadena;
	//cout<<"Entramos a show";
	//ifstream fin(filename,ios::binary);
	for(int i= 0;i <= indexList.get_count();i++){
		//cout<<" La i es"<<i<<endl;
		Index indexobj=indexList[i];
		cadena=indexobj.get_primarykey();
		if(cadena[0]!='@')
			cout<<indexobj.toString();
		//fin.seekg(indexobj.getIndex(), ios::beg);
		//fin.read((char*) &obj,sizeof(User));
	}
	system("pause");
}
bool FileList::validacion_user(char usuario[20]){
	//convertir a char a string
	string aux_user;
	int i, longitud;
	longitud=strlen(usuario);
	for(i=0;i<longitud;i++){
		aux_user+=usuario[i];
	}
	for(int i= 0;i <= indexList.get_count();i++){
		Index indexobj=indexList[i];
		
		if(indexobj.get_primarykey() == aux_user)
	 		return false;
		}
	return true;	
}
void FileList::guardar_indices(){
	string cadena;
	ofstream fout("Indices.txt", ios::app);
	for(int i= 0;i <= indexList.get_count();i++){
		Index indexobj=indexList[i];	
		fout<<indexobj.guardar();
	}
}
void FileList::carga_indices(){
	//cout<<"enyramos a la carga"<<endl;
	ifstream fin("Indices.txt");
	if(!fin.fail()){
		string cadena;	
		while(getline(fin,cadena)){
			int posicion=0;
			int x=0;
			int longitud=0;
			string index="";
			string primaryKey="";
			string activo="";
			longitud=cadena.length();
			while(cadena[x]!='|'){
					index+=cadena[x];
					x++;
				}
				x++;
			while(x<longitud){	
				primaryKey+=cadena[x];
				x++;
				}
			posicion=stoi(index);
			Index obj(posicion,primaryKey);
			fflush(stdin);
			indexList.guardar_indices(obj);
		}
	}
}
bool FileList::inicio_seccion(string usuario, string password){
	string aux_usuario;
	string aux_password;
	User obj;
	//cout<<"Entramos a show";
	ifstream fin(filename,ios::binary);
	for(int i= 0;i <= indexList.get_count();i++){
		Index indexobj=indexList[i];
		fin.seekg(indexobj.getIndex(), ios::beg);
		fin.read((char*) &obj,sizeof(User));
		aux_usuario=indexobj.get_primarykey();
		aux_password=obj.get_password();
		if(usuario==aux_usuario){
			if(password == aux_password){
				return true;
			}
		}
	}
	return false;
}
void FileList::mostrar_uno(string usaurio){
	User obj;
	ifstream fin(filename,ios::binary);
	for(int i= 0;i <= indexList.get_count();i++){
		Index indexobj=indexList[i];
		fin.seekg(indexobj.getIndex(), ios::beg);
		fin.read((char*) &obj,sizeof(User));
		if(obj.get_usuario()==usaurio){
			cout<<obj.toString();
		}
			
	}
}
string FileList::modificar(string usuario,int opc,string aux_cadena){
	User obj;
	bool encontrado=false;
	ifstream fin(filename,ios::binary);
	for(int i= 0;i <= indexList.get_count();i++){
		Index indexobj=indexList[i];
		fin.seekg(indexobj.getIndex(), ios::beg);
		fin.read((char*) &obj,sizeof(User));
		if(obj.get_usuario()==usuario){
			if(opc==1){//buscar para ver que no ponga un usuario repetido
						for(int x= 0;x <= indexList.get_count();x++){
							Index indexobj2=indexList[x];
							if(indexobj2.get_primarykey()==aux_cadena){
									cout<<"Usuario ocupado"<<endl;
									system("pause");
									encontrado=true;	
								}		
				}
				if(!encontrado){
						obj.set_usuario(aux_cadena);	
						indexobj.set_primaryKey(aux_cadena);
						indexList[i].set_primaryKey(aux_cadena);
					}	
			}
			if(opc==2){
				obj.set_nombre(aux_cadena);
			}
			if(opc==3){
				obj.set_correo(aux_cadena);
			}
			if(opc==4){
				obj.set_password(aux_cadena);
			}
			}
		}
	fin.close();
	//hacer los remplzaso en el archivo
	
	User obj3;
	int fileindex;
	ifstream lectura(filename,ios::binary);
	ofstream fout("temporal.bin", ios::binary | ios::app);

	for(int i= 0;i <= indexList.get_count();i++){
		//cout<<" La i es"<<i<<endl;
		Index indexobj3=indexList[i];
		lectura.seekg(indexobj3.getIndex(), ios::beg);
		lectura.read((char*) &obj3,sizeof(User));
		//tengo el objeto obj
		//cout<<"enyramos a el cambio xd"<<endl;
		//cout<<obj.toString();
		//cout<<obj3.get_usuario()<<endl;
		//cout<<"el usuario es"<<usuario<<endl;
		//system("pause");
		if(usuario == obj3.get_usuario() ){
		//	system("pause");
			fout.seekp(0,ios::end);
			fileindex= fout.tellp();
			fout.write((char*) &obj, sizeof(User));
		}
		else{
				fout.seekp(0,ios::end);
				fileindex= fout.tellp();
				fout.write((char*) &obj3, sizeof(User));
		}
	}
	//system("pause");
	fout.close();
	lectura.close();
    remove("Fichero.bin");//eliminamos el archivo producto
    rename("temporal.bin","Fichero.bin");//Renombramos el archivo auxiliar (donde tenemos las modificaciones) por el de productos
    if(!encontrado){
    	usuario=aux_cadena;
    	
	}
    
	return usuario;	
}
void FileList::borrar_arch(){
	remove("Indices.txt");
}
void FileList::block_temporal(string usuario){	
	User obj;
	string aux_cadena="@";
	bool encontrado=false;
	ifstream fin(filename,ios::binary);
	for(int i= 0;i <= indexList.get_count();i++){
		Index indexobj=indexList[i];
		fin.seekg(indexobj.getIndex(), ios::beg);
		fin.read((char*) &obj,sizeof(User));
		if(obj.get_usuario()==usuario){
			aux_cadena+=usuario;
			indexList[i].set_primaryKey(aux_cadena);
	
		}
	}
}
void FileList::recupera_u(string aux){
	User obj;
	string aux_cadena="@";
	string modificar;
	bool encontrado=false;
	ifstream fin(filename,ios::binary);
	for(int i= 0;i <= indexList.get_count();i++){
		Index indexobj=indexList[i];
		fin.seekg(indexobj.getIndex(), ios::beg);
		fin.read((char*) &obj,sizeof(User));
		if(obj.get_usuario()==aux){
			indexList[i].set_primaryKey(aux);
		}
	}
}
void FileList::block_perma(string usuario){
		User obj;
	string aux_cadena="@";
	bool encontrado=false;
	ifstream fin(filename,ios::binary);
	for(int i= 0;i <= indexList.get_count();i++){
		Index indexobj=indexList[i];
		fin.seekg(indexobj.getIndex(), ios::beg);
		fin.read((char*) &obj,sizeof(User));
		if(obj.get_usuario()==usuario){
			aux_cadena+=usuario;
			indexList[i].set_primaryKey(aux_cadena);
	
		}
	}
}



