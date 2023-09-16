#include "avlMediana.h"
#include "muestra.h"
#include "ArbolAvl.h"

template <class T>
AvlMediana<T>::AvlMediana(){ //constructor
    this->arbol = new ArbolAvl<T>();
    this->mediana = 0;
}

template <class T>
AvlMediana<T>::~AvlMediana(){ //destructor
    delete this->arbol;
}

template <class T>
T AvlMediana<T>::calcularMediana(){ //Calcula la mediana del arbol y el nivel en el que se encuentra. Devuelve el valor de la mediana
    int tamano = this->arbol->tamano();
    T mediana;
    nivelMediana = 0;
    if (tamano % 2 == 0)
    {
        int mitad = tamano / 2;
        int mitad2 = mitad + 1;
        //recorrer el arbol hasta encontrar en la posicion mitad y mitad2
        //luego sumar los valores en esas posiciones y dividirlos entre 2
    }
    else {
        int mitad = (tamano + 1) / 2;
        //recorrer el arbol hasta encontrar el elemento en la posicion mitad
    }

    nivelMediana = this->arbol->altura(mediana);
    setMediana(mediana);
    setNivelMediana(nivelMediana);

    return mediana;
}

template <class T>
int AvlMediana<T>::getNivelMediana(){ //Devuelve el nivel en el que se encuentra la mediana
    return this->nivelMediana;
}



template <class T>
void AvlMediana<T>::revisarAccion(list<Muestra> datos){ // Inserta y/o elimina el dato de acuerdo a lo que diga la accion. A (insertar), E (eliminar)


    //recorrer la lista de datos
    for (int i = 0; i < datos.size(); i++)
    {
        //si la accion es A, insertar el dato en el arbol
        if (datos[i].getAccion() == "A")
        {
            this->arbol->insertar(datos[i].getDato());
        }
        //si la accion es E, eliminar el dato del arbol
        else if (datos[i].getAccion() == "E")
        {
            this->arbol->eliminar(datos[i].getDato());
        }
    }
}

template <class T>
T AvlMediana<T>::getMediana(){ //Devuelve el valor de la mediana
    return this->mediana;
}

template <class T>
void AvlMediana<T>::setMediana(T mediana){ //Asigna el valor de la mediana
    this->mediana = mediana;
}


template <class T>
void AvlMediana<T>::setNivelMediana(int nivelMediana){ //Asigna el nivel en el que se encuentra la mediana
    this->nivelMediana = nivelMediana;
}   

template <class T>
void AvlMediana<T>::setArbol(ArbolAvl<T> arbol){ //Asigna el arbol
    this->arbol = arbol;
}   

template <class T>
ArbolAvl<T> AvlMediana<T>::getArbol(){ //Devuelve el arbol
    return this->arbol;
}

template <class T>
void AvlMediana<T>::setDatos(std::list<Muestra> datos){ //Asigna la lista de datos
    this->datos = datos;
}

template <class T>
std::list<Muestra> AvlMediana<T>::getDatos(){ //Devuelve la lista de datos
    return this->datos;
}


template <class T>
void Muestra<T>::leerArchivo(string nombreArchivo){ //lee un archivo de texto y guarda la accion y el dato.
    ifstream archivo;
    archivo.open(nombreArchivo);
    t linea;
    Muestra<T> temp;
    if (archivo.is_open())
    {
    while (archivo.getline(linea, 8))
    {
        string accion;
        string dato;
        getline(archivo, accion, ' ');
        getline(archivo, dato, ' ');
        temp->setAccion(accion);
        temp->setDato(dato);
        this->datos.insertar(temp);
    }
    archivo.close();
        
    }
}
