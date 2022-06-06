#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <iostream>
#include <sstream>
using namespace std;


class Personaje
{
    private:
          string nombre;
          string clase;
          string bando;
          string historial_misiones;
          string inventario;
          int nivel;
          int experiencia;

    public:
    	Personaje();
        Personaje(string,string,string,string,string,int,int);
        string toString();
        string get_nombre();
        string get_clase();
        string get_bando();
        string get_historial_misiones();
        string get_inventario();
        int& get_nivel();
        int& get_experiencia();
        void set_nombre(string);
        void set_experiencia(int);
        void set_nivel(int);
        void set_historial(string);
        string imprime_historial();
        void mod_inventario();
        void mision();
        void aumento_exp(int);
        virtual ~Personaje();
};

#endif // PERSONAJE_H
