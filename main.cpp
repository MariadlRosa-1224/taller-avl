#include "ArbolAvl.h"
#include "muestra.h"
#include <iostream>
#include <fstream>
#include "avlMediana.h"
#include <string>

int main() {
    //probando arbol avl. esto se elimina luego

    ArbolAvl<int> *arbol = new ArbolAvl<int>();
    arbol->insertar(5);
    arbol->insertar(3);
    arbol->insertar(7);
    arbol->insertar(2);
    arbol->insertar(4);

    arbol->preOrden();
    arbol->inOrden();
    arbol->postOrden();

    // ahora si la mediana del arbol

    /* string nombreArchivo = "datos-test1.txt";

    AvlMediana<int> *arbolMediana = new AvlMediana<int>();
    arbolMediana->leerArchivo(nombreArchivo);
    arbolMediana->calcularMediana();
    cout << "La mediana es: " << arbolMediana->getMediana() << endl;
    cout << "El nivel de la mediana es: " << arbolMediana->getNivelMediana() << endl; */

}