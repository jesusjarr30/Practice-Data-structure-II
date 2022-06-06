#include "FileList.h"

FileList::FileList(string filename_)
{
    this -> filename = filename_;
}

void FileList::add(Personaje obj){
	int contcad;

	 ofstream fout;
	 fout.open(filename,ios::binary|ios::app);
	 contcad = obj.get_nombre().length();
	 //Ingresar el espacio en bites de la cadena
	 fout.write((char*) &contcad, sizeof(int));
	 //Almacena de manera concecutiva la cadena
	 fout.write(obj.get_nombre().c_str(), contcad*sizeof(char));
	 contcad= obj.get_clase().length();
	 fout.write((char*)&contcad, sizeof(int));
	 fout.write(obj.get_clase().c_str(), contcad*sizeof(char));	 
	 contcad =obj.get_bando().length();
	 fout.write((char*)& contcad, sizeof(int));
	 fout.write(obj.get_bando().c_str(), contcad*sizeof(char));
	 contcad =obj.get_historial_misiones().length();
	 fout.write((char*)& contcad, sizeof(int));
	 fout.write(obj.get_historial_misiones().c_str(), contcad*sizeof(char));
	 contcad= obj.get_inventario().length();
	 fout.write((char*)& contcad, sizeof(int));
	 fout.write(obj.get_inventario().c_str(), contcad * sizeof(char));
	 
	 fout.write((char*) &obj.get_nivel(), sizeof(int));
	 fout.write((char*) &obj.get_experiencia(), sizeof(int));
}
void FileList::showall(){
	ifstream fin;
    fin.open(filename, ios::binary);
    if (!fin.is_open()){
        cout<<"no hay archivo."<<endl;
        return;
    }
	
	Personaje* obj;
	string nombre;
	string clase;
	string bando;
	string historial_misiones;
	string inventario;
	int nivel;
	int experiencia;
	int campoDimension;
	fin.read((char*) &campoDimension, sizeof(int));
    while(!fin.eof()){
        char cadAux[campoDimension+1];
        fin.read(cadAux, campoDimension*sizeof(char));
        cadAux[campoDimension] = '\0';
        nombre = cadAux;
        fin.read((char*) &campoDimension, sizeof(int));
        char cadAux2[campoDimension+1];
        fin.read(cadAux2, campoDimension*sizeof(char));
        cadAux2[campoDimension] = '\0';
        clase = cadAux2;
        fin.read((char*) &campoDimension, sizeof(int));
        char cadAux3[campoDimension+1];
        fin.read(cadAux3, campoDimension*sizeof(char));
        cadAux3[campoDimension] = '\0';
        bando = cadAux3;
        fin.read((char*) &campoDimension, sizeof(int));
        char cadAux4[campoDimension+1];
        fin.read(cadAux4, campoDimension*sizeof(char));
        cadAux4[campoDimension] = '\0';
        historial_misiones = cadAux4;
        
        fin.read((char*) &campoDimension, sizeof(int));
        char cadAux5[campoDimension+1];
        fin.read(cadAux5, campoDimension*sizeof(char));
        cadAux5[campoDimension] = '\0';
        inventario = cadAux5;
        fin.read((char*) &nivel, sizeof(int));
        fin.read((char*) &experiencia, sizeof(int));
        
        obj =new Personaje(nombre,clase,bando,historial_misiones,inventario,nivel,experiencia);
		cout<<obj->toString()<<endl;
	
		fin.read((char*) &campoDimension, sizeof(int));
	}
	system("pause");
}
Personaje *FileList::find(string busqueda){
	Personaje* obj;
	ifstream fin;
    fin.open(filename, ios::binary);
    if (!fin.is_open()){
        cout<<"no hay archivo."<<endl;
        obj=new Personaje();
        return obj;
    }
	string nombre;
	string clase;
	string bando;
	string historial_misiones;
	string inventario;
	int nivel;
	int experiencia;
	int campoDimension;
	fin.read((char*) &campoDimension, sizeof(int));
    while(!fin.eof()){
        char cadAux[campoDimension+1];
        fin.read(cadAux, campoDimension*sizeof(char));
        cadAux[campoDimension] = '\0';
        nombre = cadAux;
        if(nombre == busqueda){
        	
	        fin.read((char*) &campoDimension, sizeof(int));
	        char cadAux2[campoDimension+1];
	        fin.read(cadAux2, campoDimension*sizeof(char));
	        cadAux2[campoDimension] = '\0';
	        clase = cadAux2;
	        fin.read((char*) &campoDimension, sizeof(int));
	        char cadAux3[campoDimension+1];
	        fin.read(cadAux3, campoDimension*sizeof(char));
	        cadAux3[campoDimension] = '\0';
	        bando = cadAux3;
	        fin.read((char*) &campoDimension, sizeof(int));
	        char cadAux4[campoDimension+1];
	        fin.read(cadAux4, campoDimension*sizeof(char));
	        cadAux4[campoDimension] = '\0';
	        historial_misiones = cadAux4;
	        
	        fin.read((char*) &campoDimension, sizeof(int));
	        char cadAux5[campoDimension+1];
	        fin.read(cadAux5, campoDimension*sizeof(char));
	        cadAux5[campoDimension] = '\0';
	        inventario = cadAux5;
	        fin.read((char*) &nivel, sizeof(int));
	        fin.read((char*) &experiencia, sizeof(int));
	        
	        obj =new Personaje(nombre,clase,bando,historial_misiones,inventario,nivel,experiencia);
			return obj;
		}
		else{
			fin.read((char*) &campoDimension, sizeof(int));
	        char cadAux2[campoDimension+1];
	        fin.read(cadAux2, campoDimension*sizeof(char));
	        cadAux2[campoDimension] = '\0';
	        clase = cadAux2;
	        fin.read((char*) &campoDimension, sizeof(int));
	        char cadAux3[campoDimension+1];
	        fin.read(cadAux3, campoDimension*sizeof(char));
	        cadAux3[campoDimension] = '\0';
	        bando = cadAux3;
	        fin.read((char*) &campoDimension, sizeof(int));
	        char cadAux4[campoDimension+1];
	        fin.read(cadAux4, campoDimension*sizeof(char));
	        cadAux4[campoDimension] = '\0';
	        historial_misiones = cadAux4;
	        
	        fin.read((char*) &campoDimension, sizeof(int));
	        char cadAux5[campoDimension+1];
	        fin.read(cadAux5, campoDimension*sizeof(char));
	        cadAux5[campoDimension] = '\0';
	        inventario = cadAux5;
	        fin.read((char*) &nivel, sizeof(int));
	        fin.read((char*) &experiencia, sizeof(int));
	        
		}
	
		fin.read((char*) &campoDimension, sizeof(int));
		}
		obj=new Personaje();
		return obj;
	
}
bool FileList::find_nombre(string busqueda){
	Personaje *p;
	p=find(busqueda);
	p->toString();
	if(p->get_nombre()==busqueda){
		return true;//retorna verdadero cuando ya existe
	}
		
	return false;
}
void FileList::remove(string busqueda){
	FileList aux("auxiliar.bin");
	ifstream fin;
	fin.open(filename,ios::binary);
	Personaje *obj=nullptr;
	string nombre;
	string clase;
	string bando;
	string historial_misiones;
	string inventario;
	int nivel;
	int experiencia;
	int campoDimension;
		fin.read((char*) &campoDimension, sizeof(int));
    while(!fin.eof()){
        char cadAux[campoDimension+1];
        fin.read(cadAux, campoDimension*sizeof(char));
        cadAux[campoDimension] = '\0';
        nombre = cadAux;
        if(nombre != busqueda){
        	
	        fin.read((char*) &campoDimension, sizeof(int));
	        char cadAux2[campoDimension+1];
	        fin.read(cadAux2, campoDimension*sizeof(char));
	        cadAux2[campoDimension] = '\0';
	        clase = cadAux2;
	        fin.read((char*) &campoDimension, sizeof(int));
	        char cadAux3[campoDimension+1];
	        fin.read(cadAux3, campoDimension*sizeof(char));
	        cadAux3[campoDimension] = '\0';
	        bando = cadAux3;
	        fin.read((char*) &campoDimension, sizeof(int));
	        char cadAux4[campoDimension+1];
	        fin.read(cadAux4, campoDimension*sizeof(char));
	        cadAux4[campoDimension] = '\0';
	        historial_misiones = cadAux4;
	        
	        fin.read((char*) &campoDimension, sizeof(int));
	        char cadAux5[campoDimension+1];
	        fin.read(cadAux5, campoDimension*sizeof(char));
	        cadAux5[campoDimension] = '\0';
	        inventario = cadAux5;
	        fin.read((char*) &nivel, sizeof(int));
	        fin.read((char*) &experiencia, sizeof(int));
	        
	        obj =new Personaje(nombre,clase,bando,historial_misiones,inventario,nivel,experiencia);
	        aux.add(*obj);
		}
		else{
			fin.read((char*) &campoDimension, sizeof(int));
	        char cadAux2[campoDimension+1];
	        fin.read(cadAux2, campoDimension*sizeof(char));
	        cadAux2[campoDimension] = '\0';
	        clase = cadAux2;
	        fin.read((char*) &campoDimension, sizeof(int));
	        char cadAux3[campoDimension+1];
	        fin.read(cadAux3, campoDimension*sizeof(char));
	        cadAux3[campoDimension] = '\0';
	        bando = cadAux3;
	        fin.read((char*) &campoDimension, sizeof(int));
	        char cadAux4[campoDimension+1];
	        fin.read(cadAux4, campoDimension*sizeof(char));
	        cadAux4[campoDimension] = '\0';
	        historial_misiones = cadAux4;
	        
	        fin.read((char*) &campoDimension, sizeof(int));
	        char cadAux5[campoDimension+1];
	        fin.read(cadAux5, campoDimension*sizeof(char));
	        cadAux5[campoDimension] = '\0';
	        inventario = cadAux5;
	        fin.read((char*) &nivel, sizeof(int));
	        fin.read((char*) &experiencia, sizeof(int));
	        
		}
	
		fin.read((char*) &campoDimension, sizeof(int));
		}
	fin.close();
    std::remove(this->filename.c_str());
    rename(aux.filename.c_str(),this->filename.c_str());

}
