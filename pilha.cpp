//Atividade Percursos - Parte 1
// Claudia Fiorentino Andrade - 42005302
// João Victor Ferreira Pimenta - 42005876
// Joyce Cui - 42017157
// Ryan Marco Andrade dos Santos - 42080223

#include <iostream>
#include "pilha.h"

// Construtor da Pilha
Pilha::Pilha(){
  this->topoPilha = -1;
}

// Destrutor da pilha
// N�o faz nada, pois 
// a aloca�o � est�tica e senquencial
Pilha::~Pilha(){};

// Verifica se a pilha
// est� vazia
bool Pilha::isEmpty( ) {
  if (this->topoPilha == -1)
   	return true;
  else
   	return false;
}

// Verifica se a pilha est�
// cheia
bool Pilha::isFull( ){
  if (this->topoPilha == TAM_PILHA-1)
   	return true;
  else
   	return false;
}

// insere um elemento e 
// no topo da pilha
void Pilha::push( Elem e ){
  if (! this->isFull( ))
    this->e[++this->topoPilha] = e;
  else 
    std::cout << "overflow - Estouro de Pilha";
}

// remove um elemento 
// do topo da pilha
Elem Pilha::pop( ){
  if (! this->isEmpty( ))
   return this->e[this->topoPilha--];
  else{
    std::cout << "underflow - Esvaziamento de Pilha";
    return -1;
  }
}

// Retorna o elemento que est�
// no topo da pilha
Elem Pilha::topo( ){
  if ( ! this->isEmpty( ))
   	return this->e[this->topoPilha];
  else{
    std::cout << "underflow - Esvaziamento de Pilha";
    return -1;
  }
}

/// obt�m o total de elementos 
// armazenados na Pilha
int Pilha::size( ){
  return topoPilha+1;
}



