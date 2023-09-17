#include "ArbolAvl.h"
#include "muestra.h"
#include <iostream>
#include <fstream>
#include "avlMediana.h"
#include <string>

int main() {
    AvlMediana<int> avl = AvlMediana<int>();
    ArbolAvl<int> arbol = ArbolAvl<int>();
    avl.setArbol(arbol);
    avl.leerArchivo("datos.txt");
    avl.revisarAccion(avl.getDatos());
    avl.calcularMediana();
    std::cout << "Mediana: " << avl.getMediana() << std::endl;
    std::cout << "Nivel: " << avl.getNivelMediana() << std::endl;
    return 0;

}