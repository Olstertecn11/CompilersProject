#include "stringAnalyzer.h"
_Nodo* SynAnalyzer::construirArbol(string expresion) {
  stack<_Nodo*> pila;
  _Nodo* nodo;
  for (int i = 0; i < expresion.length(); i++) {
    if (expresion[i] >= '0' && expresion[i] <= '9') {
      nodo = new _Nodo(expresion[i]);
      pila.push(nodo);
    }
    else {
      nodo = new _Nodo(expresion[i]);
      nodo->derecho = pila.top();
      pila.pop();
      nodo->izquierdo = pila.top();
      pila.pop();
      pila.push(nodo);
    }
  }
  nodo = pila.top();
  pila.pop();
  return nodo;
}


string SynAnalyzer::analizarArbol(_Nodo* nodo) {
  if (nodo->valor >= '0' && nodo->valor <= '9') {
    return string(1, nodo->valor);
  }
  string izq = analizarArbol(nodo->izquierdo);
  string der = analizarArbol(nodo->derecho);
  string resultado = izq + der + string(1, nodo->valor);
  return resultado;
}


void SynAnalyzer::imprimirResultados(_Nodo* nodo) {
  if (nodo == NULL) {
    return;
  }

  if (nodo->valor >= '0' && nodo->valor <= '9') {
    string linea = "term.t = ";
    linea += "'";
    linea += nodo->valor;
    linea += "'";
    cadenas.push_back(linea);
  }
  else {
    string linea = "expr.t";
    linea += "' '";
    linea += " = expr.t";
    linea += " ";
    linea += " || ";
    linea += "term.t";
    linea += " ";
    linea += " || '";
    linea += nodo->valor;
    linea += "' || ";
    cadenas.push_back(linea);
  }
  imprimirResultados(nodo->izquierdo);
  imprimirResultados(nodo->derecho);
}

vector<string> SynAnalyzer::getResult(string expr) {
  vector<string> aux;
  _Nodo* raiz = construirArbol(expr);
  string resultado = analizarArbol(raiz);
  imprimirResultados(raiz);
  for (string c : cadenas) {
    if (c.length() > 12) {
      aux.push_back(c);
    }
  }
  aux.push_back("expr.t = term.t");
  for (string c : cadenas) {
    if (c.length() <= 12) {
      aux.push_back(c);
    }
  }
  delete raiz;
  return aux;
}
