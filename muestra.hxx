#include "muestra.h"
#include <iostream>
#include <fstream>

template <class T>
Muestra<T>::Muestra(){
    this->dato = NULL;
    this->accion = NULL;
}

template <class T>
Muestra<T>::~Muestra(){
    this->dato = NULL;
    this->accion = NULL;
}

template <class T>
T Muestra<T>::getDato(){
    return this->dato;
}

template <class T>
T Muestra<T>::getAccion(){
    return this->accion;
}

template <class T>
void Muestra<T>::setAccion(T accion){
    this->accion = accion;
}

template <class T>
void Muestra<T>::setDato(T dato){
    this->dato = dato;
}


