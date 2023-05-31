// Claudia Fiorentino Andrade - 42005302
// João Victor Ferreira Pimenta - 42005876
// Joyce Cui - 42017157
// Ryan Marco Andrade dos Santos - 42080223
#include <iostream>
#include <locale.h>
#include "Vertice.h"

Vertice::Vertice(string nome, float peso) {
  this->nome = nome;
  this->peso = peso;
}

Vertice::~Vertice() {
  nome = " ";
  peso = 0;
  // std::cout << "espaco do vertice liberado";
}	

Vertice::Vertice(){
  this->nome = " ";
  this->peso = 0;
}
    
string Vertice::getNome() {
  return nome;
}

void Vertice::setNome(string a) {
  nome = a;
}

int Vertice::getPeso() {
  return peso;
}

void Vertice::setPeso(float a) {
  peso = a;
}