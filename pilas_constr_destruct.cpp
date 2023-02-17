#include<iostream>

using namespace std;

//typedef int elemento;

template <typename elemento>
struct nodo_pila {
       elemento dato;
       nodo_pila<elemento> * sig;
};

template <typename elemento>
nodo_pila<elemento> * nuevo_nodo(elemento e,nodo_pila<elemento>* s){
       nodo_pila<elemento>* result = new nodo_pila<elemento>;
       result->dato = e;
       result->sig = s;
       return result;
};

template <typename elemento>
struct pila{
	  nodo_pila<elemento> * ultimo = NULL;
	  int profundidad = 0;
	  pila(){
	  }
	  
	  pila(const pila<elemento>& p){
	       //Descomentar para depurar
	       //cout << "Llamada al constructor de copia"<<endl;
	       ultimo = NULL;
	       profundidad = 0;
	       nodo_pila<elemento> * aux = p.ultimo;
	       nodo_pila<elemento> * primero = NULL;
	       while(aux!=NULL){
		    nodo_pila<elemento>* aux1 = nuevo_nodo<elemento>(aux->dato,NULL);
		    if(primero!=NULL){
		       primero->sig = aux1;
		    }
		    else{
		       ultimo = aux1;
		    }
		    primero = aux1;
		    profundidad++;
		    aux = aux->sig;
	       }
	  }
	  
	  
	  pila(pila<elemento>&& p){
	       //Descomentar para depurar
	       //cout<<"Llamada al construtor de traslado"<<endl; 
	       ultimo = p.ultimo;
	       profundidad = p.profundidad;
	       p.ultimo=NULL;
	       p.profundidad = 0;
	  }
	  
	  
	  pila & operator =(const pila & p){
		//Descomentar para depurar
		//cout<< "Llamada al operador de asignación" <<endl;
		liberar(*this);
		nodo_pila<elemento> * aux = p.ultimo;
		nodo_pila<elemento> * primero = NULL;
		while(aux!=NULL){
		    nodo_pila<elemento>* aux1 = nuevo_nodo<elemento>(aux->dato,NULL);
		    if(primero!=NULL){
		       primero->sig = aux1;
		    }
		    else{
		       ultimo = aux1;
		    }
		    primero = aux1;
		    profundidad++;
		    aux = aux->sig;
	       }
	       return (*this);
	  }
	  
	  pila & operator =(pila<elemento>&& p){
	       //Descomentar para depurar
	       //cout<<"Llamada al asignador de traslado"<<endl;
	       liberar(*this); 
	       ultimo = p.ultimo;
	       profundidad = p.profundidad;
	       p.ultimo=NULL;
	       p.profundidad = 0;
	       return (*this);
	  }
	  
	  ~pila(){
	      while(ultimo!=NULL){
		  des_apilar(*this);
	     }
	   }
};


template <typename elemento>
pila<elemento> pila_vacia(){
     pila<elemento> result;
     return result;
}



template <typename elemento>
void apilar(elemento e, pila<elemento> & p){
     nodo_pila<elemento>* aux = nuevo_nodo(e,p.ultimo);
     p.ultimo = aux;
     p.profundidad++;
}


template <typename elemento>
void des_apilar(pila<elemento> & p){
     nodo_pila<elemento>* aux = p.ultimo->sig;
     delete p.ultimo;
     p.ultimo = aux;
     p.profundidad--;
}

template <typename elemento>
elemento cima(pila<elemento> p){
       return p.ultimo->dato;
}

template <typename elemento>
elemento pop(pila<elemento> & p){
     elemento result = cima(p);
     des_apilar(p);
     return result;
}

template <typename elemento>
bool es_vacia(pila<elemento> p){
     return p.profundidad == 0;
}

template <typename elemento>
void liberar(pila<elemento> & p){
     while(p.ultimo!=NULL){
          des_apilar(p);
     }
}

template <typename elemento>
void mostrar(pila<elemento>  p){
     nodo_pila<elemento> * act= p.ultimo;
     while(act != NULL){
            cout << act->dato << endl;
            act = act->sig;
     }
}

template <typename elemento>
int profundidad(pila<elemento> p){
   return p.profundidad;
}

template <typename elemento>
pila<elemento> un_ejemplo(int n){
   pila<elemento> result;
   for(int i = 0; i<n;i++){
         //cout << i << endl;
         apilar(i,result);
    }
    return result;
}

int main(){
    cout << "pila<int> p;" << endl;
    pila<int> p;
    for(int i = 0; i<10;i++){
         //cout << i << endl;
         apilar(i,p);
    }
    cout << "pila<int>p1=un_ejemplo<int>(15);"<< endl;
    pila<int>p1=un_ejemplo<int>(15);
    cout << "pila<int>p2=p;" <<endl;
    pila<int>p2=p;
    cout << "pila<int>p3;" <<endl;
    pila<int>p3;
    cout << "p3 = un_ejemplo<int>(6);" <<endl;
    p3 = un_ejemplo<int>(6);
    cout << "p2 = p3" <<endl;
    p2 = p3;
    //p1=un_ejemplo<int>(15);
    //p2=un_ejemplo<int>(15);
    cout << "mostrar(p);" <<endl;
    mostrar(p);
    cout << "des_apilar(p);" <<endl;
    des_apilar(p);
    cout << "mostrar(p1);" <<endl;
    mostrar(p1);
    //cout << "PAsa" <<endl;
    //cout << cima(p)<< endl;
    //cout << "PAsa" <<endl;
    //des_apilar(p);
    //apilar(100,p);
    //mostrar(p);
    //liberar(p);
    return 0;
}

