#include "ArbolAvl.h"
#include "NodoAvl.h"
#include <iostream>
#include <queue>

template <class T>
ArbolAvl<T>::ArbolAvl(){
    raiz = NULL;
}

template <class T>
ArbolAvl<T>::~ArbolAvl(){
    if (   this->raiz != NULL){
    delete this->raiz;
    this->raiz = NULL;
    }
}

template <class T>
bool ArbolAvl<T>::esVacio(){
    return (this->raiz) == NULL;
}

template < class T>
T& ArbolAvl<T>::datoRaiz(){
    return this->raiz->getDato();
}


// recurrente
 template <class T>
    int ArbolAvl<T>::altura(){
        if (this->esvacio())
        {
            return -1;
        }
        
        return this->altura(this->raiz);
    }

//recursivo
template <class T>
int ArbolAvl<T>::altura(NodoAvl<T>* nodo){
    int valt;

    if (nodo->esHoja())
    {
        valt = 0;
    }
    else {
        int valt_izd = -1;
        int valt_der = -1;
        if(nodo->getDescIzq() != NULL){
            valt_izd = this->altura(nodo->getDescIzq());
        }
        if(nodo->getDescDer() != NULL){
            valt_izd = this->altura(nodo->getDescDer());
        }
        if (valt_izd > valt_der)
        {
            valt = valt_izd + 1;
        }
        else{
            valt = valt_der + 1;
        }
    }
    return valt;

}

//recurrente
template <class T>
int ArbolAvl<T>::tamano(){
    //1. verificar si el arbol esta vacio
    if (this->esVacio()){
        return 0;
    }
    
    return this->tamano(this->raiz);
}

template <class T>
int ArbolAvl<T>::tamano(NodoAvl<T>* nodo){
    //1. verificar si el nodo es hoja
    if (nodo->esHoja()){
        return 1;
    }
    //2. llamar a tamano sobre hijo izquierdo
    int tam_izq = 0;
    if (this->raiz->getDescIzq() != NULL){
        tam_izq = this->tamano(this->raiz->getDescIzq()); //devolvera 1 si es hoja, 0 si no lo es, y asi sucesivamente
    }
    //3. llamar a tamano sobre hijo derecho
    int tam_der = 0;
    if (this->raiz->getDescDer() != NULL){
        tam_der = this->tamano(this->raiz->getDescDer());
    }

    //4.  retornar la suma de los tamaños de los subarboles mas 1
    return tam_izq + tam_der + 1;
}
//iterativo
template<class T>
bool ArbolAvl<T>::insertar(T val){
    NodoAvl<T>* nodo = this->raiz;
    NodoAvl<T>* padre = this->raiz;
    bool insertado = false;
    bool duplicado =false;

    while (nodo != NULL ){ 
        padre = nodo;
        if (val < nodo->getDato()){
            nodo = nodo->getDescIzq();
        }
        else if (val > nodo->getDato()){
            nodo = nodo->getDescDer();
        }
        else{
            duplicado = true;
            break;
        }
    }

    if (!duplicado){
        NodoAvl<T>* nuevo = new NodoAvl<T>(val); //val se pasa como parametro de constructot
        if (nuevo != NULL) {
            if (val < padre->getDato()){ 
                padre->setDescIzq(nuevo); //si val es menor que el dato del padre, se inserta a la izquierda 
            }
            else{
                padre->setDescDer(nuevo); //si val es mayor que el dato del padre, se inserta a la derecha
            }
        }
        insertado = true;
    }

    validacionEquilibrio();

    return insertado;

}

//iteratico
template<class T>
bool ArbolAvl<T>::eliminar(T val){
    NodoAvl<T>* nodo = this->raiz;
    NodoAvl<T>* padre = this->raiz;
    bool eliminado = false;
    bool duplicado =false;

    while (nodo != NULL ){ 
        padre = nodo;
        if (val < nodo->getDato()){
            nodo = nodo->getDescIzq();
        }
        else if (val > nodo->getDato()){
            nodo = nodo->getDescDer();
        }
        else{

            if (nodo->esHoja()){

                //hacer que el padre apunte a NULL
                if (val < padre->getDato()){
                    padre->setDescIzq(NULL);
                }
                else{
                    padre->setDescDer(NULL);
                }

            }

            //Nodo tiene solo un hijo izquierdo
            
            if(nodo->getDescIzq() != NULL && nodo->getDescDer() == NULL){
                //hacer que el padre apunte al hijo izquierdo del nodo
                if (val < padre->getDato()){
                    padre->setDescIzq(nodo->getDescIzq());
                }else{
                    padre->setDescDer(nodo->getDescIzq());
                }

            }

            //Nodo tiene solo un hijo derecho

            if (nodo->getDescIzq() == NULL && nodo->getDescDer() != NULL){
                //hacer que el padre apunte al hijo derecho del nodo
                if (val < padre->getDato()){
                    padre->setDescIzq(nodo->getDescDer());
                }else{
                    padre->setDescDer(nodo->getDescDer());
                }
            }
            
            //Nodo tiene dos hijos

            if (nodo->getDescIzq() != NULL && nodo->getDescDer() != NULL)
            {
                // busca en el subarbol derecho el menor de los mayores
                NodoAvl<T>* menorMayor = nodo->getDescDer();
                NodoAvl<T>* padreMenorMayor = nodo;
                while (menorMayor->getDescIzq() != NULL)
                {
                    padreMenorMayor = menorMayor;
                    menorMayor = menorMayor->getDescIzq();
                }
                // intercambia los valores del nodo a eliminar con el menor de los mayores
                T valTemp = nodo->getDato();
                nodo->setDato(menorMayor->getDato());
                menorMayor->setDato(valTemp);
                // elimina el menor de los mayores
                if (menorMayor->getDescDer() != NULL)
                {
                    padreMenorMayor->setDescIzq(menorMayor->getDescDer()); // el menor de los mayores no tiene hijo izquierdo
                }
                else
                {
                    padreMenorMayor->setDescIzq(NULL);
                }
            }
            
            

            eliminado = true;
            break;
        }
    }


    
    return eliminado;
}

//iterativo
template<class T>
NodoAvl<T> *ArbolAvl<T>::buscar(T val){
    NodoAvl<T>* nodo = this->raiz;
    bool encontrado = false;

    while (nodo != NULL && !encontrado){
        if (val < nodo->getDato()){
            nodo = nodo->getDescIzq();
        }
        else if (val > nodo->getDato()){
            nodo = nodo->getDescDer();
        }
        else{
            encontrado = true;
        }
    }
    return encontrado ? nodo : NULL;
}

//recurrente
template<class T>
void ArbolAvl<T>::preOrden(){
    if (!this->esVacio()){
        this->preOrden(this->raiz);
    }
}

template<class T> 
void ArbolAvl<T>::preOrden(NodoAvl<T>* nodo){
    //1. imprimir el valor del nodo
    std::cout << nodo->getDato() << " ";
    //2. llamar a preorden sobre hijo izquierdo
    this->preOrden(nodo->getDescIzq());
    //3. llamar a preorden sobre hijo derecho
    this->preOrden(nodo->getDescDer());
}

//recurrente
template<class T>
void ArbolAvl<T>::inOrden(){
    if (!this->esVacio()){
        this->inOrden(this->raiz);
    }
}

template<class T>
void ArbolAvl<T>::inOrden(NodoAvl<T>* nodo){
    //1. verificar si el nodo es nulo
    if (nodo != NULL){
    //2. llamar a inorden sobre hijo izquierdo
        this->inOrden(nodo->getDescIzq());
    //3. imprimir el valor del nodo
        std::cout << nodo->getDato() << " ";
    //4. llamar a inorden sobre hijo derecho
        this->inOrden(nodo->getDescDer());

    
    }
}


//recurrente
template<class T>
void ArbolAvl<T>::postOrden(){
    if(!this->esVacio()){
        this->postOrden(this->raiz);
    }
}

template<class T>
void ArbolAvl<T>::postOrden(NodoAvl<T>* nodo){
    if (nodo != NULL){
        this->postOrden(nodo->getDescIzq()); //llamada recursiva sobre hijo izquierdo
        this->postOrden(nodo->getDescDer()); //llamada recursiva sobre hijo derecho
        std::cout << nodo->getDato() << " "; //imprimir el valor del nodo
    }
}

//iterativo
template<class T>
void ArbolAvl<T>::nivelOrden(){
    if(!this->esVacio()){
        std::queue<NodoAvl<T>*> cola;
        cola.push(this->raiz);
        NodoAvl<T>* nodo; // Nodod binario que esta en el frente de la cola
        while(!cola.empty()){
            nodo = cola.front(); //obtener el nodo del frente de la cola
            cola = cola.pop();
            std::cout << nodo->getDato() << " ";
            if (nodo->getDescIzq() != NULL){ //si el nodo tiene hijo izquierdo, agregarlo a la cola
                cola.push(nodo->getDescIzq());
            }
            if (nodo->getDescDer() != NULL){ //si el nodo tiene hijo derecho, agregarlo a la cola
                cola.push(nodo->getDescDer());
            }
        }
    }

}

template<class T>
void ArbolAvl<T>::setRaiz(NodoAvl<T>* nodo){
    this->raiz = nodo;
}


template<class T>
bool ArbolAvl<T>::validacionEquilibrio(){
    if (this->esVacio()){
        return true;
    }
    
    this->validacionEquilibrio(this->raiz);

}


template<class T>
bool ArbolAvl<T>::validacionEquilibrio(NodoAvl<T>* nodo){
    if (nodo->esHoja()){
        return true;
    }

    if (altura(nodo) > 1){

    int altura_izq = 0;
    int altura_der = 0;
    int diferencia_altura = 0;

    if (nodo->getDescIzq() != NULL){
        altura_izq = this->altura(nodo->getDescIzq());
    }
    if (nodo->getDescDer() != NULL){
        altura_der = this->altura(nodo->getDescDer());
    }

    diferencia_altura = altura_izq - altura_der;

    if (diferencia_altura >= -2|| diferencia_altura <= 2){
        if(diferencia_altura == 2){
            if (this->altura(nodo->getDescIzq()) == 1){
                this->rotacionDerecha(nodo);
            }
            else{
                this->rotacionIzquierdaDerecha(nodo);
            }
        }
        else if (diferencia_altura == -2){
            if (this->altura(nodo->getDescIzq()) == 1){
                this->rotacionDerechaIzquierda(nodo);
            }
            else{
                this->rotacionIzquierda(nodo);
            }
        }


        if (nodo->getDescIzq() != NULL){
            this->validacionEquilibrio(nodo->getDescIzq());
        }
        if(nodo->getDescDer() != NULL){
            this->validacionEquilibrio(nodo->getDescDer());
        }

        if(diferencia_altura == 1 || diferencia_altura == -1){
            return true;
        }
    }
    else{
        printf("El arbol no esta balanceado, falto una o mas rotaciones\n");
        return false;

    }
}

return true;

}

template<class T>
NodoAvl<T> * ArbolAvl<T>::rotacionIzquierda(NodoAvl<T>* nodo){
    NodoAvl<T>* nodo_padre = nodo->getDescDer(); //nodo padre es el hijo derecho del nodo
    nodo->setDescDer(nodo_padre->getDescIzq()); //el hijo derecho del nodo es el hijo izquierdo del nodo padre
    nodo_padre->setDescIzq(nodo); //el hijo izquierdo del nodo padre es el nodo
    nodo = nodo_padre; //el nodo es el nodo padre
    return nodo;
}

template<class T>
NodoAvl<T> * ArbolAvl<T>::rotacionDerecha(NodoAvl<T>* nodo){
    NodoAvl<T>* nodo_padre = nodo->getDescIzq(); //nodo padre es el hijo izquierdo del nodo
    nodo->setDescIzq(nodo_padre->getDescDer()); //el hijo izquierdo del nodo es el hijo derecho del nodo padre
    nodo_padre->setDescDer(nodo); //el hijo derecho del nodo padre es el nodo
    nodo = nodo_padre; //el nodo es el nodo padre
    return nodo;
}

template<class T>
void ArbolAvl<T>::rotacionIzquierdaDerecha(NodoAvl<T>* nodo){
   NodoAvl<T>* nodo_aux = rotacionIzquierda(nodo->getDescDer()); //nodo auxiliar es la rotacion izquierda del hijo derecho del nodo
    nodo->setDescDer(nodo_aux); //el hijo derecho del nodo es el nodo auxiliar
    rotacionDerecha(nodo); //rotacion derecha del nodo
}

template<class T>
void ArbolAvl<T>::rotacionDerechaIzquierda(NodoAvl<T>* nodo){
    NodoAvl<T>* nodo_aux = rotacionDerecha(nodo->getDescIzq()); //nodo auxiliar es la rotacion derecha del hijo izquierdo del nodo
    nodo->setDescIzq(nodo_aux); //el hijo izquierdo del nodo es el nodo auxiliar    
    rotacionIzquierda(nodo); //rotacion izquierda del nodo
}







