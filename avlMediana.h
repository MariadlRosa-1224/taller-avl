#ifndef __AVLMEDIANA_H__
#define __AVLMEDIANA_H__

#include "ArbolAvl.h"
#include "muestra.h"
#include <list>
#include "NodoAvl.h"
#include <iostream>
#include <string>

template <class T>
class AvlMediana {
    protected:

        typename std::list<typename Muestra<T>::Muestra> datos;
        ArbolAvl<T> arbol;
        T mediana;
        int nivelMediana;
    public:
        AvlMediana();
        ~AvlMediana();
        T calcularMediana(); //Calcula la mediana del arbol y el nivel en el que se encuentra. Devuelve el valor de la mediana
        int getNivelMediana();
        void revisarAccion(typename std::list<typename Muestra<T>::Muestra> datos); // Inserta y/o elimina el dato de acuerdo a lo que diga la accion. A (insertar), E (eliminar)
        T getMediana();
        void setMediana(T mediana);
        void setNivelMediana(int nivelMediana);
        void setArbol(ArbolAvl<T> arbol);
        ArbolAvl<T> getArbol();
        void setDatos(typename std::list<typename Muestra<T>::Muestra> datos);
        typename std::list<typename Muestra<T>::Muestra> getDatos();
         void leerArchivo(std::string nombreArchivo); //lee un archivo de texto y guarda la accion y el dato.
};

#endif