#include <iostream>

using namespace std; 

struct pila{
     int  * datos = new int[10];
     int capacidad = 10;
     int tam = 0;
};

void dobla_cap(pila & p);
void liberar(pila & p);

int main(){
     pila p;
     liberar(p);
     return 0;
}

void dobla_cap(pila & p){
     int * new_datos = new int[2*p.capacidad];
     for(int i=0;i<p.tam;i++){
         new_datos[i] = p.datos[i];
     }
     p.capacidad = 2*p.capacidad;
     delete[] p.datos;
     p.datos = new_datos;  
};

void liberar(pila & p){
     delete[] p.datos;
     p.capacidad = 0;
     p.tam = 0;
};

