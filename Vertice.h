// Claudia Fiorentino Andrade - 42005302
// João Victor Ferreira Pimenta - 42005876
// Joyce Cui - 42017157
// Ryan Marco Andrade dos Santos - 42080223
#include <string>
using namespace std;
#ifndef ___VERTICE_MATRIZ_ADJACENCIA___

#define ___VERTICE_MATRIZ_ADJACENCIA___


class Vertice{
	private:
		string nome;
		int peso;
  public:
    Vertice();
    Vertice(string nome, float peso);
		~Vertice();	
    string getNome();
    void setNome(string a);
    int getPeso();
    void setPeso(float a);
};

#endif




