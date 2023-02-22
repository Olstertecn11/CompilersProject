#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class _Nodo {
public:
	char valor;
	_Nodo* izquierdo;
	_Nodo* derecho;
	_Nodo(char v) {
		valor = v;
		izquierdo = derecho = NULL;
	}
};

class SynAnalyzer {
public:
	vector<string> cadenas;
	_Nodo* construirArbol(string) ;
	string analizarArbol(_Nodo*) ;
	void imprimirResultados(_Nodo* ) ;
	vector<string> getResult(string ) ;
};
