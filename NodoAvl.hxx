#include "NodoAvl.h"

template <class T>
NodoAvl<T>::NodoAvl() {
    this->desc.clear(); // Limpia la lista de descendientes.
}

template <class T>
NodoAvl<T>::~NodoAvl() {
    std::list<NodoAvl<T>*>::iterator it;
    for (it = desc.begin(); it != this->desc.end(); it++) {
        delete (*it);
    }
    this->descendientes.clear();
}

template <class T>
T NodoAvl<T>::getDato() {
    return this->dato; // Retorna el valor del nodo
}

template <class T>
void NodoAvl<T>:: setDato(T& val) {
    this->val = val; // Asigna el valor al nodo
}

template <class T>
NodoAvl<T>* NodoAvl<T>::getDescIzq() {
    return this->descIzq; // Retorna el nodo descendiente izquierdo
}

template <class T>
NodoAvl<T>* NodoAvl<T>::getDescDer() {
    return this->descDer; // Retorna el nodo descendiente derecho
}

template <class T>
void NodoAvl<T>::setDescIzq(NodoAvl<T>* nval) {
    this->descIzq = nval; // Asigna el nodo descendiente izquierdo
    this->descIzq->setPadre(this); // Asigna el padre del nodo descendiente izquierdo
}

template <class T>
void NodoAvl<T>::setDescDer(NodoAvl<T>* nval) {
    this->descDer = nval; // Asigna el nodo descendiente derecho
    this->descDer->setPadre(this); // Asigna el padre del nodo descendiente derecho
}

template <class T>
bool NodoAvl<T>::esHoja() {
    return (this->descIzq == NULL && this->descDer == NULL); // Retorna true si el nodo es hoja
}

template <class T>
bool NodoAvl<T>::esRaiz() {
    return (this->padre == NULL); // Retorna true si el nodo es raiz
}

