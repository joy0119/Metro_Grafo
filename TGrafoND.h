// Claudia Fiorentino Andrade - 42005302
// João Victor Ferreira Pimenta - 42005876
// Joyce Cui - 42017157
// Ryan Marco Andrade dos Santos - 42080223
/*
Implementa�o de uma Classe para grafos denominada TGrafoND,
usando Matriz de Adjac�ncia
e m�todos para utiliza�o de um grafo dirigido.
*/
#ifndef ___GRAFOND_MATRIZ_ADJACENCIA___
#include "Vertice.h"
#define ___GRAFOND_MATRIZ_ADJACENCIA___

// defini�o de uma estrutura para armezanar um grafo
// Tamb�m seria poss�vel criar um arquivo grafo.h
// e fazer a inclus�o "#include <grafo.h>"
class TGrafoND {
private:
  int n; // quantidade de v�rtices
  int m; // quantidade de arestas
  int tipoGrafo;
  float **adj;   // matriz de adjac�ncia
  Vertice *vetr; // conjunto de vértices

  // ---- Getters -------------------------
  int degree(int v);

  // ---- Auxiliares para Percursos -------
  void visitarNo(int *qntd_visitas); // Dá uma bizoiada num vértice
  int *marcarNo(int nosMarcados[],
                int nroNosMarcados,  // Marca um nó que ja foi visitado num algoritmo de percurso
                int no);
  int noAdjacente(int no, // Busca um próximo nó adjacente ao atual
                  int nosMarcados[]);

  // ---- Auxiliares para Bellman-Ford ----
  Vertice find_V(string nome); // Retorna a instância do vértice de acordo com o
                               // nome informado
  int find_index_V(string nome); /* Retorna o índice de determinado vértice,
                                  na matriz de adj e no vetor de vértices*/
  void printCaminho(int *distancia,
                    int *predecessor, // Imprime o caminho encontrado pelo
                    int destino);      // algoritmo de Bellman
  void relaxa(int *d, int *pi, int v,
              int u); // Faz a troca de melhor caminho no algoritmo de Bellman

public:
  // Construtores
  TGrafoND(int n, Vertice v[]);
  ~TGrafoND();

  // ---- Getters ---------------------------
  int getV();
  int getA();
  bool is_adj(int i, int j);

  // ---- Operações Básicas  ----------------
  Vertice getVert(int i);
  void insereA(string a,
               string b); // Insere uma aresta de acordo com os nomes passados
  void insereV(string a,
               int b);    // Insere um vértice à matriz de adjacência e a o grafo
  void removeA(string a,
               string b); // Remove uma aresta, da mesma forma que é adicionado
  void removeV(string a); // Remove um vértice da matriz de adjacência e
                          // portanto do grafo

  // ---- Análise do grafo ------------------
  void show();                           // Apresentação visual do grafo
  int grauV(int g[]);                    // Retorna o grau de um vértice
  int percursoProfundidade(int vInicio); // Percurso em profundidade do grafo
  int conexidade();                      // Verifica se o grafo é conexo - 1, ou desconexo - 0;
  
  // ---- Solução para o Projeto ------------
  void caminhoMinimo(string origem, string destino);  // Algoritmo de Bellman-Ford
};

#endif
