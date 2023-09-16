#ifndef __ARBOLAVl_H__
#define __ARBOLAVL_H__

#include "NodoAvl.h"

template <class T>
class ArbolAvl{
    protected:
        NodoAvl<T> *raiz;
    public:
        ArbolAvl();
        ~ArbolAvl();
        bool esVacio();
        T& datoRaiz();
        int altura();
        int altura(NodoAvl<T> *nval);
        int tamano(); // Cantidad de nodos 
        int tamano(NodoAvl<T> *nval);
        bool insertar(T val);
        bool eliminar(T val);
        NodoAvl<T> *buscar(T val);
        void preOrden();
        void preOrden(NodoAvl<T>* nodo);
        void inOrden();
        void inOrden(NodoAvl<T>* nodo);
        void postOrden();
        void postOrden(NodoAvl<T>* nodo);
        void nivelOrden();
        void setRaiz(NodoAvl<T> *nodo);
        bool validacionEquilibrio();
        bool validacionEquilibrio(NodoAvl<T> *nodo);
        void rotacionIzquierda(NodoAvl<T> *nodo); 
        void rotacionDerecha(NodoAvl<T> *nodo);
        void rotacionIzquierdaDerecha(NodoAvl<T> *nodo);
        void rotacionDerechaIzquierda(NodoAvl<T> *nodo);
};



#endif