#ifndef __AVLMEDIANA_H__
#define __AVLMEDIANA_H__

#include "ArbolAvl.h"
#include "muestra.h"
#include <list>
#include "NodoAvl.h"

template <class T>
class AvlMediana {
    protected:

        std::list<Muestra> datos;
        ArbolAvl<T> arbol;
        T mediana;
        int nivelMediana;
    public:
         MuestraAleatoria();
        ~MuestraAleatoria();
        T calcularMediana(); //Calcula la mediana del arbol y el nivel en el que se encuentra. Devuelve el valor de la mediana
        int getNivelMediana();
        void revisarAccion(list<Muesta> datos); // Inserta y/o elimina el dato de acuerdo a lo que diga la accion. A (insertar), E (eliminar)
        T getMediana();
        void setMediana(T mediana);
        void setNivelMediana(int nivelMediana);
        void setArbol(ArbolAvl<T> arbol);
        ArbolAvl<T> getArbol();
        void setDatos(std::list<Muestra> datos);
        std::list<Muestra> getDatos();
         void leerArchivo(string nombreArchivo); //lee un archivo de texto y guarda la accion y el dato.
};

#endif