#ifndef __NODOAVL_H__
#define __NODOAVL_H__

#include <list>

template < class T >
class NodoAvl {
    protected:
        T dato;
        NodoAvl<T>* descIzq;
        NodoAvl<T>* descDer;
    public:
    NodoAvl();
    NodoAvl(T& dato);
    ~NodoAvl();
    T getDato();
    void setDato(T& val);
    NodoAvl<T>* getDescIzq();
    NodoAvl<T>* getDescDer();
    void setDescIzq(NodoAvl<T>* nval);
    void setDescDer(NodoAvl<T>* nval);
    bool esHoja();
    bool esRaiz();
    NodoAvl<T>* getPadre();
};

#include "NodoAvl.hxx"

#endif