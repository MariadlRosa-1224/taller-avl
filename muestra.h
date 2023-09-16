#ifndef __MUESTRA_H__
#define __MUESTRA_H__


template <class T>
class Muestra {
    protected:
        T accion;
        T dato;
    public:
         Muestra();
        ~Muestra();
        void setAccion(T accion);
        void setDato(T dato);
        T getDato();
        T getAccion();
       
};

#include "muestra.hxx"


#endif