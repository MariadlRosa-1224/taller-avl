#ifdef MUESTRA_H
#define MUESTRA_H


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

#include "Muestra.hxx"


#endif