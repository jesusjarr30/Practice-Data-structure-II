#include "Graph.h"



int DynamicGraph::getVertexCount() const
{
    return vertexCount;
}

char &DynamicGraph::getVertexAt(int index)
{
	int count = 0;
    Vertex* aux = firstVertex;
    if (index < 0 || index >= vertexCount){
        cout<<"Index must be [0, vertexCount)"<<endl;
        return aux->data;
    }
    while(count < index){
        aux = aux->nextVertex;
        count++;
    }
    return aux->data;

}

bool DynamicGraph::existEdge(char data_1, char data_2)
{
    Vertex* v_1 = findVertex(data_1);
    Vertex* v_2 = findVertex(data_2);
    Edge* e = nullptr;
    if (v_1 && v_2)
        e = v_1->findEdge(v_2);

    return (bool)e;

}

int DynamicGraph::getWeightEdge(char data_1, char data_2)
{
    Vertex* v_1 = findVertex(data_1);
    Vertex* v_2 = findVertex(data_2);
    Edge* e = nullptr;
    if (v_1 && v_2)
        e = v_1->findEdge(v_2);
    if (!e)
        throw "Vertex does not exist";
    return e->weight;
}

DynamicGraph::DynamicGraph(char nombre_)
{
	nombre=nombre_;
    firstVertex = nullptr;
    vertexCount = 0;
  	set_visitados("A");
  	actual='A';
}

void DynamicGraph::addVertex(char data)
{
    Vertex* v = new Vertex(data);
    if (firstVertex){
        Vertex* aux = firstVertex;
        while(aux->nextVertex)
            aux = aux->nextVertex;
        aux->nextVertex = v;
    }
    else
        firstVertex = v;
    vertexCount++;
}

void DynamicGraph::addEdge(char data_1, char data_2, int weight)
{
    Vertex* v_1 = findVertex(data_1);
    Vertex* v_2 = findVertex(data_2);
    if (v_1 && v_2){

        v_1->addEdge(v_2, weight);
        v_2->addEdge(v_1, weight);
    }
    else
        throw "Vertex does not exist";
}

string DynamicGraph::toString()
{
    stringstream ss;
    Vertex* aux = firstVertex;
    while(aux){
        ss<<aux->toString()<<endl<<"|"<<endl;
        aux = aux->nextVertex;
    }
    return ss.str();
}
string DynamicGraph::toString2(){
	stringstream ss;
	int x=visitados.length();
	int i=0;
	
	while(i<=visitados.length()){
		Vertex* aux =firstVertex;	
		while(aux){
			if(aux->get_data()==visitados[i])
			ss<<aux->toString()<<endl;
			aux=aux->nextVertex;
		}
		i++;	
	}
	return ss.str();	
}
string DynamicGraph::lugares_adyacentes(){
	//cout<<"Entra a la funcion"<<endl;
	//system("pause");
	//cout<<"actual es "<<actual<<endl;
	stringstream ss;
	Vertex* aux=firstVertex;
	while(aux){
		if(aux->get_data()==actual)
			ss<<aux->toString();
		aux=aux->nextVertex;
	}
	return ss.str();
}

Vertex *DynamicGraph::findVertex(char data)
{
        Vertex* aux = firstVertex;
        while(aux){
            if (aux->data == data)
                return aux;
            aux = aux->nextVertex;
        }
        return nullptr;
}

void DynamicGraph::removeVertex(char e)
{
    Vertex* v_e = findVertex(e);
    if (v_e){
        Vertex* auxV = firstVertex;
        while(auxV){
            auxV->removeEdge(v_e);
            auxV = auxV->nextVertex;
        }

        Vertex* prev = previousVertex(v_e);
        if (prev){
            prev->nextVertex = v_e->nextVertex;
        }
        else{//delete first
            firstVertex = v_e->nextVertex;
        }
        delete v_e;
        vertexCount--;
    }
}

Vertex *DynamicGraph::previousVertex(Vertex *v)
{
    Vertex* aux = firstVertex;
    if (aux == v)
        return nullptr;
    while(aux->nextVertex != v){
        aux = aux->nextVertex;
    }
    return aux;
}


void DynamicGraph::removeEdge(char data_1, char data_2)
{
    Vertex* v_1 = findVertex(data_1);
    Vertex* v_2 = findVertex(data_2);
    if (v_1)
        if (v_2){
            v_1->removeEdge(v_2);
            v_2->removeEdge(v_1);
        }

}

Vertex::Vertex(char data)
{
    this->data = data;
    this->nextVertex = nullptr;
    this->firstEdge = nullptr;
    this->EdgesCount = 0;
}

void Vertex::addEdge(Vertex *destination, int weight)
{
    Edge* e = new Edge(destination, weight);
    if (firstEdge){
        Edge* aux = firstEdge;
        while(aux->nextEdge)
            aux = aux->nextEdge;
        aux->nextEdge = e;
    }
    else
        firstEdge= e;
    EdgesCount++;
}

string Vertex::toString()
{
    stringstream ss;
    Edge* aux = firstEdge;
    ss<<this->data;
    while(aux){
        ss<<"->"<<aux->toString();
        aux = aux->nextEdge;
    }
    return ss.str();
}

void Vertex::removeEdge(Vertex *v_e)
{
    Edge* auxE = findEdge(v_e);
    if (auxE){
        Edge* prevE = previousEdge(auxE);
        if (prevE){
            prevE->nextEdge = auxE->nextEdge;
        }
        else
            firstEdge = auxE->nextEdge;
        EdgesCount--;
        delete auxE;


    }


}
Vertex* Vertex::get_siguiente(){
	return nextVertex;
}
char Vertex::get_data(){
	return data;
}
Edge *Vertex::findEdge(Vertex *v_e)
{
    Edge* aux = firstEdge;
    while(aux){
        if (aux->destination == v_e)
            return aux;
        aux = aux->nextEdge;
    }
    return nullptr;
}

Edge *Vertex::previousEdge(Edge *e)
{
    Edge* aux = firstEdge;
    if (aux == e)
        return nullptr;
    while(aux->nextEdge != e){
        aux = aux->nextEdge;
    }
    return aux;
}
Edge *Vertex::get_firtsEdge(){
	return firstEdge;
}

Edge::Edge(Vertex *destination, int weight)
{
    this->weight = weight;
    this->nextEdge = nullptr;
    this->destination = destination;

}

string Edge::toString()
{
    stringstream ss;
    ss<<destination->data<<", "<<weight;
    return ss.str();
}
int Vertex::get_EdgesCount(){
	return EdgesCount;
}
char DynamicGraph::get_nombre(){
	return nombre;
}
Vertex* Edge::get_destination(){
	return destination;
}
Edge* Edge::get_nextEdge(){
	return nextEdge;
}
string Edge::recuperacadena(){
	string cadena;
	Vertex* v;
	Edge* auxe=v->get_firtsEdge();
		while(auxe){
	        	cadena+=auxe->toString();
	        	auxe = auxe->nextEdge;
    }
    return cadena;
}
char Edge::recuperades(){
	return destination->get_data();
}
void DynamicGraph::addEdge2(char data_1, char data_2, int weight)
{
    Vertex* v_1 = findVertex(data_1);
    Vertex* v_2 = findVertex(data_2);
    if (v_1 && v_2){

        v_1->addEdge(v_2, weight);
    }
    else
        throw "Vertex does not exist";
}
void DynamicGraph::set_visitados(string visi_){
	visitados=visi_;	
}
string DynamicGraph::toFile()
{
	system("pause");
	int cont=0;
	stringstream v;
	string cadena="";
	cadena+=nombre;
	cadena+='@';
	//cout<<"nombre"<<nombre<<endl;
    Vertex* aux = firstVertex;
    while(aux){//obtenemos los vetices
        cadena+=aux->get_data();
        cadena+=",";
        aux = aux->get_siguiente();
    }
    cadena+='@';
     aux = firstVertex;//reiniciamos el ciclo para ver los 
    //cout<<"la cadena es"<<cadena<<endl;
	//system("pause");
	while(aux){
		cadena+='|';
		cadena+=aux->get_data();
        
        Edge* auxe=aux->get_firtsEdge();
		while(auxe){
		
	//		cout<<"Entramos"<<endl;
			 
			 cadena+=auxe->recuperades();
			 
			 auxe = auxe->nextEdge;
			 if(auxe){
			 	//cadena+=',';
			 }
		}
		aux = aux->get_siguiente();
	}
	cadena+='@';
	cadena+=visitados;
	v<<cadena;
	return v.str();
}
void DynamicGraph::set_actual(char cambio){
	actual=cambio;
}
char DynamicGraph::get_actual(){
	return actual;
}
void DynamicGraph::despalzarse(char m){
	string cadena;
	Vertex* aux =firstVertex;
	while(aux){
		if(aux->get_data()==actual){
		Edge* auxe=aux->get_firtsEdge();
		while(auxe){
			 cadena+=auxe->recuperades();
			 
			 auxe = auxe->nextEdge;	
			}
		}
		aux=aux->get_siguiente();
	}
//	cout<<"La cadena es"<<cadena.length()<<endl;
	int x=0;
	//system("pause");
	while(x<=cadena.length()){
		if(cadena[x]==m){
			set_actual(m);	
			visitados+=m;
		}
		x++;
	}
//	cout<<"hola"<<endl;
}


//DynamicGraph::DynamicGraph(string cadena){
/*	int x=0;
	char v_1;
	int cont=0;
	int conta=0;
	string vv;
	cout<<"Ingresamos a la funcion"<<endl;
	nombre=cadena[0];
	
	/*while(x<=cadena.length()){
		if(cadena[x]=='|'){
			cont++;
			x++;
			v_1=cadena[x];
			x++;
			while(cadena[x]!='|'|| cadena[x]!='@'){
				addEdge2(v_1,cadena[x],2);
				x++;
			}
		}
		if(cadena[x]=='@')
			conta++;
		if(cadena[x]=='@'&&conta==2){
			x++;
			while(x<=cadena.length()){
				vv=cadena[x];
			}
			set_visitados(vv);
		}
			
	}			
		x++;
}*/
void DynamicGraph::load()
{
	/*
    for (int i = 0; i < g.getVertexCount(); i++)
        cadena+=getVertexAt(i)
    for (int i = 0; i < g.getVertexCount(); i++)
        for (int j = i+1; j < g.getVertexCount(); j++)
            if (g.existEdge(g.getVertexAt(i),g.getVertexAt(j)))
                addEdge(g.getVertexAt(i),g.getVertexAt(j),g.getWeight(g.getVertexAt(i),g.getVertexAt(j)));
*/
}
/*
int StaticGraph::getVertexCount() const
{
    return vertexCount;
}

char &StaticGraph::getVertexAt(int index)
{
    if (index < 0 || index >= vertexCount)
        cout<<"Index must be [0, vertexCount)"<<endl;
    return dictionary[index];
}

bool StaticGraph::existEdge(char data_1, char data_2)
{
    int v_1 = findVertex(data_1);
    int v_2 = findVertex(data_2);
    if (v_1 >= 0)
        if (v_2 >= 0)
            return edges[v_1][v_2];
    return false;

}

int StaticGraph::findVertex(char data)
{
    for(int i = 0; i < vertexCount; i++)
        if (dictionary[i] == data)
            return i;
    return -1;
}

int StaticGraph::getWeight(char data_1, char data_2)
{
    int v_1 = findVertex(data_1);
    int v_2 = findVertex(data_2);
    if (v_1 >= 0)
        if (v_2 >= 0)
            return weight[v_1][v_2];
    throw "Vertex does not exist";
}

StaticGraph::StaticGraph(int vertexCount)
{
    //    weight = new int*[vertexCount];
//    for(int i = 0; i < vertexCount; ++i)
//        weight[i] = new int[vertexCount];

//    edges = new bool*[vertexCount];
//    for(int i = 0; i < vertexCount; ++i)
//        edges[i] = new bool[vertexCount];

//    dictionary = new char[vertexCount];

//    for (int i = 0; i< vertexCount; i++)
//        for (int j = 0; j< vertexCount; j++){
//            weight[i][j] = 0;
//            edges[i][j] = false;
//        }
    for (int i = 0; i< 10; i++)
        for (int j = 0; j< 10; j++){
            weight[i][j] = 0;
            edges[i][j] = false;
        }
    this->vertexCount = vertexCount;



}

StaticGraph::StaticGraph()
{
    for (int i = 0; i< 10; i++)
        for (int j = 0; j< 10; j++){
            weight[i][j] = 0;
            edges[i][j] = false;
        }
    this->vertexCount = 0;
}

StaticGraph::StaticGraph(DynamicGraph g):StaticGraph(g.getVertexCount())
{
    for (int i = 0; i < vertexCount; i++){
        dictionary[i] = g.getVertexAt(i);

    }
    for (int i = 0; i < vertexCount; i++){
        for (int j = 0; j < vertexCount; j++){
            edges[i][j] = g.existEdge(dictionary[i], dictionary[j]);
            if (edges[i][j])
                weight[i][j] = g.getWeightEdge(dictionary[i], dictionary[j]);
        }
    }
}

string StaticGraph::toString()
{
    stringstream ss;
    for (int i = 0; i < vertexCount; i++){
            ss<<dictionary[i];
        for (int j = 0; j < vertexCount; j++){
            if (edges[i][j])
            ss<<"->"<<dictionary[j]<<", "<<weight[i][j];
        }
        ss<<endl;
        ss<<"|";
        ss<<endl;
    }
    return ss.str();
}

void StaticGraph::save()
{
    ofstream fout;
    fout.open("fichero.txt", ios::trunc );
    fout.write((char*)this, sizeof (StaticGraph));
    fout.close();

}

void StaticGraph::load()
{
    ifstream fin;
    fin.open("fichero.txt");
    fin.read((char*)this, sizeof (StaticGraph));
    fin.close();
}
*/
