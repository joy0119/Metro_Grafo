//Atividade Percursos - Parte 1
// Claudia Fiorentino Andrade - 42005302
// João Victor Ferreira Pimenta - 42005876
// Joyce Cui - 42017157
// Ryan Marco Andrade dos Santos - 42080223

#ifndef ___PILHA_H___
#define ___PILHA_H___

// defini�o de um novo tipo de dado
typedef int Elem; 

// constante que indica o 
// Tamanho alocado para a pilha
const int TAM_PILHA = 10;

// Classe pilha est�tica e sequencial
class Pilha {
	private:
   		int topoPilha;
   		Elem e[TAM_PILHA];
   	public:
   		Pilha();
   		~Pilha();
   		bool isEmpty();
   		bool isFull();
   		void push(Elem e);
   		Elem pop();
   		Elem topo(); 
		int size();		
};

#endif
