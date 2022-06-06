#include "Personaje.h"
Personaje::Personaje(){
	nombre="";
	clase="";
	bando="";
	historial_misiones="";
	inventario="";
	nivel=0;
	experiencia=0;
}
Personaje::Personaje( string nombre_, string clase_,string bando_, string historial_misiones_,string inventario_,int nivel_,int experiencia_)
{
    this ->nombre = nombre_;
    this -> clase = clase_;
    this ->bando= bando_;
    this ->historial_misiones=historial_misiones_;
    this ->inventario = inventario_;
    this ->nivel = nivel_;
    this ->experiencia = experiencia_;
}


string Personaje::toString(){
	stringstream ss;
	ss<<"Nombre                "<<nombre<<endl; 
	ss<<"Historial de misiones "<<historial_misiones<<endl;
	ss<<"Clase                 "<<clase<<endl;
	ss<<"Bando                 "<<bando<<endl;
	ss<<"Inventario            "<<inventario<<endl;
	ss<<"Nivel                 "<<nivel<<endl;
	ss<<"Experiencia           "<<experiencia<<endl;
	return ss.str();
	
}
string Personaje::get_nombre(){
	return nombre;
}
string Personaje::get_clase(){
	return clase;
}
string Personaje::get_bando(){
	return bando;
}
string Personaje::get_historial_misiones(){
	return historial_misiones;
}
string Personaje::get_inventario(){
	return inventario;
}
int& Personaje::get_nivel(){
	return nivel;
}
int& Personaje::get_experiencia(){
	return experiencia;
}
void Personaje::set_nombre(string cadena){
	nombre= cadena;
}
void Personaje::set_experiencia(int aux){
	experiencia=aux;
}
void Personaje::set_nivel(int aux){
	nivel = nivel + aux;
}
string Personaje::imprime_historial(){
	system("cls");
	stringstream ss;
	int cont=0;
	string aux;
	ss<<"El historial de misiones    "<<endl;
	int largo=historial_misiones.length();
		for(int x=0;x<=largo;x++){
			if(inventario[x]!='|'){
				aux+=historial_misiones[x];
				
			}
			else{
				ss<<aux<<endl;
				aux="";
			}
		}
	
	return ss.str();
}
void Personaje::mod_inventario(){
	stringstream ss;
	int cont=0;
	
	string aux;
	int opc;
	int opc2;
		fflush(stdin);
		string inv1="";
		string inv2="";
		string inv3="";
		int numero=0;
		system("cls");
		cout<<"El inventario contiene"<<endl;
		int largo=inventario.length();
		for(int x=0;x<=largo;x++){
			if(inventario[x]=='|'){
				cont++;
				}
		}
		for(int x=0;x<=largo;x++){
			if(inventario[x]!='|'){
				aux+=inventario[x];
			}
			
			else{
				aux+='|';
				numero=numero+1;
				cout<<numero<<" "<<aux<<endl;
				if(numero==1){
					inv1=aux;
				}
				if(numero==2){
					inv2=aux;
				}
				if(numero==3){
					inv3=aux;
				}
				aux="";
			}
			
		}cout<<"\n\n\n";
		cout<<"Numero"<<numero<<endl;
		cout<<"Desea hacer alfuna operacion en el inventario"<<endl;
		cout<<"1. Agregar cosas al invetario"<<endl;
		cout<<"2. Quitar objetos del inventario"<<endl;
		cout<<"3. regresar"<<endl;
		cout<<"Ingrese opcion"<<endl;
		cin>>opc;
		switch(opc){
			case 1:

				if(clase=="Unidad de infanteria")
				{
					cout<<"Las siguentes armas estan disponibles para todos los bandos"<<endl;
					cout<<"Armas de inicio"<<endl;
					cout<<"1. Fusil semiautomatico M1 Garand 7.62 x63 mm |"<<endl;
					cout<<"2. Subfusil Sten calibre 9 x 19 mm |"<<endl;
					cout<<"3. Rifle de cerrojo Arisaka Tipo 30 |"<<endl;
					cout<<"4. Sub ametralladora kalashnikov 1942 (AK42) |"<<endl;
					cout<<"5. Fusil de asalto MP44 calibre 7,92 x calibre 7,92 x 33 mm Kurz |"<<endl;
					cout<<"6. Subfusil Beretta MAB 38 calibre 9 x 19 mm parabellum |"<<endl;
					cout<<"7. PPsh 41 (Union Sovietica) | Requiere nivel 2"<<endl;
					cout<<"8. Orita M1941 (Rumania) |Requiere nivel 5"<<endl;
					cout<<"9. Thompson (Estados Unidos) | Requiere nivel 10"<<endl;				
					cout<<"Ingrese el numero del arma que desea agregar"<<endl;
					cin>>opc2;
					if(numero<=2){
						switch(opc2){
							case 1:
								if("Fusil semiautomatico M1 Garand 7.62 x63 mm |"==inv1){
									cout<<"El arma ya esta en el inventario"<<endl;
									break;
								}
								if("Fusil semiautomatico M1 Garand 7.62 x63 mm |"==inv2){
									cout<<"El arma ya esta en el inventario"<<endl;
									break;
								}
								
								if("Fusil semiautomatico M1 Garand 7.62 x63 mm |"==inv3){
									cout<<"El arma ya esta en el inventario"<<endl;
									break;
								}
								//agregar el arma
								if(numero==1){
									inv2="Fusil semiautomatico M1 Garand 7.62 x63 mm |";
									inventario="";
									inventario+=inv1;
									inventario+=inv2;
								}
								if(numero == 2){
									inv3="Fusil semiautomatico M1 Garand 7.62 x63 mm |";
										inventario="";
										inventario+=inv1;
										inventario+=inv2;
										inventario+=inv3;
								}
								break;
							case 2:
								if("Subfusil Sten calibre 9 x 19 mm |"==inv1){
									cout<<"El arma ya esta en el inventario"<<endl;
									break;
								}
								if("Subfusil Sten calibre 9 x 19 mm |"==inv2){
									cout<<"El arma ya esta en el inventario"<<endl;
									break;
								}
								
								if("Subfusil Sten calibre 9 x 19 mm |"==inv3){
									cout<<"El arma ya esta en el inventario"<<endl;
									break;
								}
								//agregar el arma
								if(numero==1){
									inv2="Subfusil Sten calibre 9 x 19 mm |";
									inventario="";
									inventario+=inv1;
									inventario+=inv2;
								}
								if(numero ==2){
									inv3="Subfusil Sten calibre 9 x 19 mm |";
										inventario="";
										inventario+=inv1;
										inventario+=inv2;
										inventario+=inv3;
								}
								break;
							case 3:
									if("Rifle de cerrojo Arisaka Tipo 30 |"==inv1){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									if("Rifle de cerrojo Arisaka Tipo 30 |"==inv2){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									
									if("Rifle de cerrojo Arisaka Tipo 30 |"==inv3){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									//agregar el arma
									if(numero==1){
										inv2="Rifle de cerrojo Arisaka Tipo 30 |";
										inventario="";
										inventario+=inv1;
										inventario+=inv2;
										
									}
									if(numero==2){
										inv3="Rifle de cerrojo Arisaka Tipo 30 |";
											inventario="";
											inventario+=inv1;
											inventario+=inv2;
											inventario+=inv3;
									}
									break;
							case 4:
									if("Sub ametralladora kalashnikov 1942 (AK42) |"==inv1){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									if("Sub ametralladora kalashnikov 1942 (AK42) |"==inv2){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									
									if("Sub ametralladora kalashnikov 1942 (AK42) |"==inv3){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									//agregar el arma
									if(numero==1){
										inv2="Sub ametralladora kalashnikov 1942 (AK42) |";
										inventario="";
										inventario+=inv1;
										inventario+=inv2;
									}
									if(numero==2){
											inv3="Sub ametralladora kalashnikov 1942 (AK42) |";
												inventario="";
												inventario+=inv1;
												inventario+=inv2;
												inventario+=inv3;
											}
									break;
							case 5:
									if("Fusil de asalto MP44 calibre 7,92 x calibre 7,92 x 33 mm Kurz |"==inv1){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									if("Fusil de asalto MP44 calibre 7,92 x calibre 7,92 x 33 mm Kurz |"==inv2){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									
									if("Fusil de asalto MP44 calibre 7,92 x calibre 7,92 x 33 mm Kurz |"==inv3){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									//agregar el arma
									if(numero==1){
										inv2="Fusil de asalto MP44 calibre 7,92 x calibre 7,92 x 33 mm Kurz |";
										inventario="";
										inventario+=inv1;
										inventario+=inv2;
									}
									if(numero==2){
											inv3="Fusil de asalto MP44 calibre 7,92 x calibre 7,92 x 33 mm Kurz |";
												inventario="";
												inventario+=inv1;
												inventario+=inv2;
												inventario+=inv3;
											}
									break;
							case 6:
									if("Subfusil Beretta MAB 38 calibre 9 x 19 mm parabellum |"==inv1){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									if("Subfusil Beretta MAB 38 calibre 9 x 19 mm parabellum |"==inv2){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									
									if("Subfusil Beretta MAB 38 calibre 9 x 19 mm parabellum |"==inv3){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									//agregar el arma
									if(numero==1){
										inv2="Subfusil Beretta MAB 38 calibre 9 x 19 mm parabellum |";
										inventario="";
										inventario+=inv1;
										inventario+=inv2;
									}
									if(numero==2){
											inv3="Subfusil Beretta MAB 38 calibre 9 x 19 mm parabellum |";
												inventario="";
												inventario+=inv1;
												inventario+=inv2;
												inventario+=inv3;
											}
									break;
							case 7:
									if("PPsh 41 (Union Sovietica) |"==inv1){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									if("PPsh 41 (Union Sovietica) |"==inv2){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									
									if("PPsh 41 (Union Sovietica) |"==inv3){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									//Validar nivel
									if(nivel>=2){
										//agregar el arma
										if(numero==1){
											inv2="PPsh 41 (Union Sovietica) |";
											inventario="";
											inventario+=inv1;
											inventario+=inv2;
										}
										if(numero==2){
											inv3="PPsh 41 (Union Sovietica) |";
												inventario="";
												inventario+=inv1;
												inventario+=inv2;
												inventario+=inv3;
											}
									}
									else{
										cout<<"No cuenta con el nivel suficiente para agregar esta arma"<<endl;
									}
									break;
							case 8:
									if("Orita M1941 (Rumania) |"==inv1){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									if("Orita M1941 (Rumania) |"==inv2){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									
									if("Orita M1941 (Rumania) |"==inv3){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									//Validar nivel
									if(nivel>=5){
										//agregar el arma
										if(numero==1){
											inv2="Orita M1941 (Rumania) |";
											inventario="";
											inventario+=inv1;
											inventario+=inv2;
										}
										if(numero==2){
											inv3="Orita M1941 (Rumania) |";
												inventario="";
												inventario+=inv1;
												inventario+=inv2;
												inventario+=inv3;
											}
									}
									else{
										cout<<"No cuenta con el nivel suficiente para agregar esta arma"<<endl;
									}
									break;
							case 9:
									if("Thompson (Estados Unidos) |"==inv1){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									if("Thompson (Estados Unidos) |"==inv2){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									
									if("Thompson (Estados Unidos) |"==inv3){
										cout<<"El arma ya esta en el inventario"<<endl;
										break;
									}
									//Validar nivel
									if(nivel>=10){
									
										//agregar el arma
										if(numero==1){
											inv2="Thompson (Estados Unidos) |";
											inventario="";
											inventario+=inv1;
											inventario+=inv2;
										}
										if(numero==2){
										inv3="Thompson (Estados Unidos) |";
											inventario="";
											inventario+=inv1;
											inventario+=inv2;
											inventario+=inv3;
										}
									}
									else{
										cout<<"No cuenta con el nivel suficiente para agregar esta arma"<<endl;
									}
									break;	
						}
						
					}
					else{
						cout<<"Solo puede guardar tres armas en su inventario "<<endl;
						cout<<"Necesita eliminar un arma"<<endl;
					}
						
				}
				if(clase == "Unidad blindada"){
					cout<<"Los sigueintes tanques estan disponibles"<<endl;
					cout<<"1.Tanque M4 sherman |"<<endl;
					cout<<"2.Tanque Churchill Mk I |"<<endl;
					cout<<"3.Tanque  Tipo 97 Chi-Ha |"<<endl;
					cout<<"4.Tanque KV-1 |"<<endl;
					cout<<"5.Tanque Panzer IV |"<<endl;
					cout<<"6.Tanque M15/42 |"<<endl;
					cout<<"7.Tanque T34 (Union sovietica) |Requiere nivel 2"<<endl;
					cout<<"8.Tanque Tiger 1 (Alamania) | Requiere nivel 10"<<endl;
					cout<<"9.Tanque Pantera (Alemania) |Requiere nivel 20"<<endl;
					cin>>opc2;
					if(numero<=2){
						switch(opc2){
							case 1:
								if("Tanque M4 sherman |"==inv1){
									cout<<"El tanque ya esta en el inventario"<<endl;
									break;
								}
								if("Tanque M4 sherman |"==inv2){
									cout<<"El tanque ya esta en el inventario"<<endl;
									break;
								}
								
								if("Tanque M4 sherman |"==inv3){
									cout<<"El tanque ya esta en el inventario"<<endl;
									break;
								}
								//agregar el arma
								if(numero == 1){
									inv2="Tanque M4 sherman |";
									inventario="";
									inventario+=inv1;
									inventario+=inv2;
								}
								if(numero == 2){
									inv3="Tanque M4 sherman |";
										inventario="";
										inventario+=inv1;
										inventario+=inv2;
										inventario+=inv3;
								}
								break;
							case 2:
								if("Tanque Churchill Mk I |"==inv1){
									cout<<"El tanque ya esta en el inventario"<<endl;
									break;
								}
								if("Tanque Churchill Mk I |"==inv2){
									cout<<"El tanque ya esta en el inventario"<<endl;
									break;
								}
								
								if("Tanque Churchill Mk I |"==inv3){
									cout<<"El tanque ya esta en el inventario"<<endl;
									break;
								}
								//agregar el arma
								if(numero==1){
									inv2="Tanque Churchill Mk I |";
									inventario="";
									inventario+=inv1;
									inventario+=inv2;
								}
								if(numero ==2){
									inv3="Tanque Churchill Mk I |";
										inventario="";
										inventario+=inv1;
										inventario+=inv2;
										inventario+=inv3;
								}
								break;
							case 3:
									if("Tanque  Tipo 97 Chi-Ha |"==inv1){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									if("Tanque  Tipo 97 Chi-Ha |"==inv2){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									
									if("Tanque  Tipo 97 Chi-Ha |"==inv3){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									//agregar el arma
									if(numero==1){
										inv2="Tanque  Tipo 97 Chi-Ha |";
										inventario="";
										inventario+=inv1;
										inventario+=inv2;
										
									}
									if(numero==2){
										inv3="Tanque  Tipo 97 Chi-Ha |";
											inventario="";
											inventario+=inv1;
											inventario+=inv2;
											inventario+=inv3;
									}
									break;
							case 4:
									if("Tanque KV-1 |"==inv1){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									if("Tanque KV-1 |"==inv2){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									
									if("Tanque KV-1 |"==inv3){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									//agregar el arma
									if(numero==1){
										inv2="Tanque KV-1 |";
										inventario="";
										inventario+=inv1;
										inventario+=inv2;
									}
									if(numero==2){
										inv3="Tanque KV-1 |";
											inventario="";
											inventario+=inv1;
											inventario+=inv2;
											inventario+=inv3;
										}
									break;
							case 5:
									if("Tanque Panzer IV |"==inv1){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									if("Tanque Panzer IV |"==inv2){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									
									if("Tanque Panzer IV |"==inv3){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									//agregar el arma
									if(numero==1){
										inv2="Tanque Panzer IV |";
										inventario="";
										inventario+=inv1;
										inventario+=inv2;
									}
									if(numero==2){
										inv3="Tanque panzer IV |";
											inventario="";
											inventario+=inv1;
											inventario+=inv2;
											inventario+=inv3;
										}
									break;
							case 6:
									if("Tanque M15/42 |"==inv1){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									if("Tanque M15/42 |"==inv2){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									
									if("Tanque M15/42 |"==inv3){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									//agregar el arma
									if(numero==1){
										inv2="Tanque M15/42 |";
										inventario="";
										inventario+=inv1;
										inventario+=inv2;
									}
									if(numero==2){
										inv3="Tanque M15/42 |";
											inventario="";
											inventario+=inv1;
											inventario+=inv2;
											inventario+=inv3;
										}
									break;
							case 7:
									if("Tanque T34 (Union sovietica) |"==inv1){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									if("Tanque T34 (Union sovietica) |"==inv2){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									
									if("Tanque T34 (Union sovietica) |"==inv3){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									//Validar nivel
									if(nivel>=2){
										//agregar el arma
										if(numero==1){
											inv2="Tanque T34 (Union sovietica) |";
											inventario="";
											inventario+=inv1;
											inventario+=inv2;
										}
										if(numero==2){
										inv3="Tanque T34 (Union sovietica) |";
											inventario="";
											inventario+=inv1;
											inventario+=inv2;
											inventario+=inv3;
										}
										//inventario+=inv3;
									}
									else{
										cout<<"No cuenta con el nivel suficiente para agregar este tanque"<<endl;
									}
									break;
							case 8:
									if("Tanque Tiger 1 (Alemania) |"==inv1){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									if("Tanque Tiger 1 (Alemania) |"==inv2){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									
									if("Tanque Tiger 1 (Alemania) |"==inv3){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									//Validar nivel
									if(nivel>=10){
										//agregar el arma
										if(numero==1){
											inv2="Tanque Tiger 1 (Alemania) |";
											inventario="";
											inventario+=inv1;
											inventario+=inv2;
										}
										if(numero==2){
										inv3="Tanque Tiger 1 (Alemania) |";
											inventario="";
											inventario+=inv1;
											inventario+=inv2;
											inventario+=inv3;
										}
									}
									else{
										cout<<"No cuenta con el nivel suficiente para agregar esta arma"<<endl;
									}
									break;
							case 9:
									if("Tanque Pantera (Alemania) |"==inv1){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									if("Tanque Pantera (Alemania) |"==inv2){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									
									if("Tanque Pantera (Alemania) |"==inv3){
										cout<<"El tanque ya esta en el inventario"<<endl;
										break;
									}
									//Validar nivel
									if(nivel>=20){
									
										//agregar el arma
										if(numero==1){
											inv2="Tanque Pantera (Alemania) |";
											inventario="";
											inventario+=inv1;
											inventario+=inv2;
										}
										if(numero==2){
										inv3="Tanque Pantera (Alemania) |";
											inventario="";
											inventario+=inv1;
											inventario+=inv2;
											inventario+=inv3;
										}
									}
									else{
										cout<<"No cuenta con el nivel suficiente para agregar esta arma"<<endl;
									}
									break;	
						}
						
					}
					else{
						cout<<"Solo puede guardar tres tanques en su inventario "<<endl;
						cout<<"Necesita eliminar un arma"<<endl;
					}
						}
				break;
			case 2:
				//borrar
				cout<<"Ingrese numero del objeto del inventario que desea borrar"<<endl;
				cin>>opc2;
				cout<<"Numero es "<<numero<<endl;
				if(numero<=1){
					cout<<"Su inventario no puede quedar vacio porfavor ingrese mas elemntos antes de borrar su unica arma o tanque"<<endl;
				}
				else{
					inventario="";
					if(opc2==1){
						inventario+=inv2;
						inventario+=inv3;
					}
						else
						if(opc2==2){
							inventario+=inv1;
							inventario+=inv3;
						}
							else
							if(opc2==3){
								inventario+=inv1;
								inventario+=inv2;
							}
						
					
				}
				break;
		}
}
void Personaje::mision(){
	int cont=0;
	int num=0;
	int opc;
	string rival;
	string aux;
	int numero=0;
	string inv1;
	string inv2;
	string inv3;
	string arma;
	system("cls");
	cout<<"Mision"<<endl;
	cout<<"Tenemos que elegir el arma o tanque que llevarmeos a la guerra "<<endl;
		int largo=inventario.length();
		for(int x=0;x<=largo;x++){
			if(inventario[x]=='|'){
				cont++;
				}
		}
		for(int x=0;x<=largo;x++){
			if(inventario[x]!='|'){
				aux+=inventario[x];
			}
			
			else{
				aux+='|';
				numero=numero+1;
				cout<<numero<<" "<<aux<<endl;
				if(numero==1){
					inv1=aux;
				}
				if(numero==2){
					inv2=aux;
				}
				if(numero==3){
					inv3=aux;
				}
				aux="";
			}
		}
			cout<<"Ingresa opcion"<<endl;
			cin>>opc;
				cout<<"A continucacion se tendra que enfrentar con una unidad enemiga "<<endl;
				cout<<"El juego consiste en altidud de los disparos "<<endl;
				cout<<"En un rango de 1 a 10 tendra que selecionar tres ubicaciones en los cuales ustad puede recibir daños"<<endl;
				cout<<"A continuacion tendra que selecionar un numero del 1 al 10 donde usted realizara el disparo"<<endl;
				cout<<"El primero en asertar 3 disparos sera el ganador"<<endl;
				if(clase == "Unidad de infanteria"){
					num=1+rand()%(9);
					switch(num){
						case 1:
							rival="El enmegio esta equipado con un Fusil semiautomatico M1 Garand 7.62 x63 mm ";
							break;
						case 2:
							rival="El enemigo esta equipado con Subfusil Sten calibre 9 x 19 mm ";
							break;
						case 3:
							rival="El enemigo esta equipado con  Rifle de cerrojo Arisaka Tipo 30 ";
							break;
						case 4:
								rival="El enemigo esta equipado con  Sub ametralladora kalashnikov 1942 (AK42) ";
							break;
						case 5:
							rival="El enemigo esta equipado con Fusil de asalto MP44 calibre 7,92 x calibre 7,92 x 33 mm Kurz";
							break;
						case 6:
							rival="El enemigo esta equipado con Subfusil Beretta MAB 38 calibre 9 x 19 mm parabellum";
							break;
						case 7:
							rival="El enemigo esta equipado con PPsh 41 (Union Sovietica)";
							break;
						case 8:
							rival="El enemigo esta equipado con Orita M1941 (Rumania)";
							break;
						case 9:
							rival="El enemigo esta equipado con Thompson (Estados Unidos)";
							break;
					}				
				}
				else{
					num=1+rand()%(9);
					switch(num){
						case 1:
							rival="El enmegio esta equipado con un Tanque M4 sherman";
							break;
						case 2:
							rival="El enemigo esta equipado con un  Tanque Churchill Mk I ";
							break;
						case 3:
							rival="El enemigo esta equipado con un Tanque Tipo 97 Chi-Ha";
							break;
						case 4:
								rival="El enemigo esta equipado con un  Tanque KV-1";
							break;
						case 5:
							rival="El enemigo esta equipado con un Tanque Panzer IV";
							break;
						case 6:
							rival="El enemigo esta equipado con un Tanque M15/42";
							break;
						case 7:
							rival="El enemigo esta equipado con un Tanque T34 (Union sovietica)";
							break;
						case 8:
							rival="El enemigo esta equipado con un Tanque Orita M1941 (Rumania)";
							break;
						case 9:
							rival="El enemigo esta equipado con un Tanque Pantera (Alemania)";
							break;
						}
					
				}	
				if(opc==1){
					arma=inv1;
				}else
					if(opc==2){
						arma=inv2;
					}else
						if(opc==3){
							arma=inv3;
						}
				cout<<rival<<endl;
				cout<<"Buena suerte"<<endl;
				bool asierto=false;
				int disparo;
				int dis=0;
				int dise=0;
				int defensa[3];
				int defensa_ene[3];
				string cadena;
				//Ingresar posiciones de las nuiodades
				for(int x=0;x<3;x++){
					cout<<"Ingrese posiciones vulnarables del 1 al 10"<<endl;
					cin>>defensa[x];
				}
				//Ingresar posiciones del enemigo
					for(int x=0;x<3;x++){
					
					defensa_ene[x]=1+rand()%(10);
				}	
				while(dis!=3 and dise !=3){
					system("cls");
					cout<<"Impactos recibidos "<<dise<<"/3"<< arma <<endl;
					cout<<"Impactos al enemigo "<<dis<<"/3  "<< rival <<endl;
					cout<<"Ingrese posicion de el primer disparo(1 a 10)"<<endl;
					cin>>disparo;
					for(int x=0;x<3;x++){
						if(disparo== defensa_ene[x])
						{
							cout<<"Disparo asertado"<<endl;
							dis++;
							system("pause");
							asierto = true;
							}
						}
						if(asierto==false){
							cout<<"Fallamos el disparo"<<endl;
							system("pause");
						}
						asierto = false;
					
					disparo=1+rand()%(10);
					for(int x=0;x<3;x++){
						if(disparo== defensa[x])
						{
							cout<<"El enemigo a dañado nuestra unidad"<<endl;
							dise++;
							system("pause");
							asierto=true;
						}
						
					}
						if(asierto==false){
							cout<<"El enemigo fallo el disparo"<<endl;
							system("pause");
						}
						asierto = false;
				}
				if(dis==3){
					system("cls");
					cout<<"Buen trabajo eleiminamos al enemigo"<<endl;
					cout<<"Usted a gando 5 pts. de experiencia"<<endl;
					cadena="Vicoria obtuvimos 5 puntos de exp";
					cadena+="|";
					set_historial(cadena);
					aumento_exp(5);
				}
				else
				{
					system("cls");
					cout<<"Parece que el enemigo a ganado :("<<endl;
					cout<<"Ustede obtuvo u punto de experiencia"<<endl;
					cadena="Derrota, perdimos solo obtuvimos 1 punto de exp";
					cadena="|";
					aumento_exp(1);
					set_historial(cadena);
				}
				//enivia rlo que se tiene que agrega
}
void Personaje::set_historial(string cadena){
	historial_misiones+=cadena;
}
void Personaje::aumento_exp(int aux){
	int cont;
	int residuo;
	int aux_experiencia=get_experiencia();
	aux_experiencia=aux_experiencia+aux;
	cont=aux_experiencia/10; 	//resulado de la divicon
	residuo=aux_experiencia % 10;//residuo que se modifica en aux experiencia
	if(cont>0){
		set_nivel(cont);
	}
	experiencia=residuo;
	
	
}
Personaje::~Personaje()
{
    //dtor
}
