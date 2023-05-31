// Claudia Fiorentino Andrade - 42005302
// João Victor Ferreira Pimenta - 42005876
// Joyce Cui - 42017157
// Ryan Marco Andrade dos Santos - 42080223
#include "TGrafoND.h"
#include "pilha.h"
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale.h>

// Construtor do TGrafoND, respons�vel por
// Criar a matriz de adjac�ncia v x v do Grafo
TGrafoND::TGrafoND(int n, Vertice v[]) {
  this->n = n;
  // No in�cio dos tempos n�o h� arestas
  this->m = 0;
  this->tipoGrafo = 0;

  float **adjac = (float **)malloc(n * sizeof(float *));
  for (int i = 0; i < n; i++) {
    adjac[i] = (float *)malloc(n * sizeof(float));
  }
  adj = adjac;
  vetr = (Vertice *)malloc(sizeof(Vertice) * n);

  for (int i = 0; i < n; i++) {
    vetr[i].setNome(v[i].getNome());
    vetr[i].setPeso(v[i].getPeso());
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      adj[i][j] = 0;
}

TGrafoND::~TGrafoND() {
  for (int i = 0; i < n; i++)
    delete[] adj[i];
  delete[] adj;
  delete[] vetr;
}

// MÉTODOS PRIVADOS =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void TGrafoND::visitarNo(int *qntd_visitas) { (*qntd_visitas)++; }

int *TGrafoND::marcarNo(int nosMarcados[], int nroNosMarcados, int no) {
  // verifica se vÃ©rtice ainda nÃ£o foi marcado, se nÃ£o, marca
  if (nosMarcados[no] == 0) {
    // std::cout << "marcando no: " << no << "\n";
    nosMarcados[no] = 1;
  }
  nroNosMarcados++;
  return nosMarcados;
}

int TGrafoND::noAdjacente(int no, int nosMarcados[]) {
  // verifica se há relacao de nos adjacentes e se o no jÃ¡ for marcado
  for (int i = 0; i < n; i++)
    if (adj[no][i] != 0 && nosMarcados[i] != 1) {
      return i;
    }
  return -1;
}

Vertice TGrafoND::find_V(string nome) { return vetr[find_index_V(nome)]; }

int TGrafoND::find_index_V(string nome) {
  for (int i = 0; i < n; i++)
    if (vetr[i].getNome() == nome)
      return i;
  return (-1);
}

void TGrafoND::printCaminho(int *distancia, int *predecessor, int destino) {
  if (distancia[destino] == 0) {
    cout << "\n+- - - - - - -! CAMINHO RECOMENDADO !- - - - - - -+" << endl;
    // linha 1
    cout << "|";
    cout << setw(24) << left << "Estações";
    cout << "  |";
    cout << setw(24) << left << "Nº de Pessoas (milhares)|" << endl;
    cout << "+- - - - - - - - - - - - - - - - - - - - - - - - -+" << endl;
    // linha 2
    cout << "|";
    cout << setfill('.') << setw(24) << left << vetr[destino].getNome();
    cout << "|";
    cout << setw(24) << left << vetr[destino].getPeso();
    cout << "|" << endl;
    return;
  }
  printCaminho(distancia, predecessor, predecessor[destino]);
  cout << "|";
  cout << setfill('.') << setw(24) << left << vetr[destino].getNome();
  cout << "|";
  cout << setw(24) << left << vetr[destino].getPeso();
  cout << "|" << endl;
}

void TGrafoND::relaxa(int *d, int *pi, int v, int u) {
  if (d[v] > d[u] + (vetr[u].getPeso() + vetr[v].getPeso())) {
    d[v] = d[u] + (vetr[u].getPeso() + vetr[v].getPeso());
    if (pi[v] == -2 || pi[v] != u)
      pi[v] = u;
  }
}

// MÉTODOS PÚBLICOS =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
void TGrafoND::insereA(string a, string b) {
  // verifica se os nomes estao no vetor
  // int rel = 0;
  int iA;
  int iB;
  for (int i = 0; i < n; i++) {
    if (a == vetr[i].getNome()) {
      iA = i;
    }
  }
  for (int j = 0; j < n; j++) {
    if (b == vetr[j].getNome()) {
      iB = j;
    }
  }
  // testa se nao temos a aresta
  if (adj[iA][iB] == 0 && adj[iB][iA] == 0) {
    adj[iA][iB] = 1;
    adj[iB][iA] = 1;
    m++; // atualiza qtd arestas
  }
}

void TGrafoND::insereV(string a, int b) {
  n++;
  vetr = (Vertice *)realloc(vetr, sizeof(Vertice) * n);

  float **newAdj = (float **)malloc(n * sizeof(float *));
  for (int i = 0; i < n; i++) {
    newAdj[i] = (float *)calloc(n, sizeof(float));
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      newAdj[i][j] = adj[i][j];
    }
    newAdj[i][n - 1] = 0;
  }

  for (int i = 0; i < n; i++) {
    newAdj[n - 1][i] = 0;
  }

  delete[] adj;
  adj = newAdj;

  vetr[n - 1].setNome(a);
  vetr[n - 1].setPeso(b);
}

// remove uma aresta v->w do Grafo
void TGrafoND::removeA(string a, string b) {
  // verifica se os nomes estao no vetor
  // int rel = 0;
  int iA, iB;
  for (int i = 0; i < n; i++) {
    if (a == vetr[i].getNome()) {
      // rel++;
      iA = i;
    }
  }
  for (int j = 0; j < n; j++) {
    if (b == vetr[j].getNome()) {
      // rel++;
      iB = j;
    }
  }

  if (adj[iA][iB] != 0 && adj[iB][iA] != 0) {
    adj[iA][iB] = 0;
    adj[iB][iA] = 0;
    m--; // atualiza qtd arestas
    std::cout << "\n aresta removida \n";
  } else {
    cout << "\nDesculpe! Não encontramos uma ligação entre as estações "
            "informadas!\n";
  }
}

void TGrafoND::removeV(string a) {
  int temp;
  Vertice tempV;
  int iA = -1;
  for (int i = 0; i < n; i++) {
    if (a == vetr[i].getNome()) {
      iA = i;
    }
  }
  if (iA == -1) {
    std::cout << "\nDesculpe! Não encontramos esta estação no sistema!\n";
    return;
  }
  for (int w = 0; w < n; w++) {
    if (adj[iA][w] != 0) {
      adj[iA][w] = 0;
      m--;
    } else if (adj[w][iA] != 0) {
      adj[w][iA] = 0;
      m--;
    }
  }
  if (iA != n - 1) {
    // deslocamento da matriz
    for (int w = 0; w < n; w++) {
      //(n-1)-iA -> deslocamento de elementos apos o indice solicitado
      for (int i = 0; i < (n - 1) - iA; i++) {
        temp = adj[w][iA + i];               // temp <- [0][1]
        adj[w][iA + i] = adj[w][iA + i + 1]; //[0][1] <- [0][2]
        adj[w][iA + i + 1] = temp;           //[0][2] <- temp([0][1])
      }
    }
    for (int w = 0; w < n; w++) {
      for (int i = 0; i < (n - 1) - iA; i++) {
        temp = adj[iA + i][w];
        adj[iA + i][w] = adj[iA + i + 1][w];
        adj[iA + i + 1][w] = temp;
      }
    }
    // deslocamento do vetor(vértice)
    for (int i = 0; i < (n - 1) - iA; i++) {
      tempV = vetr[iA + i];
      vetr[iA + i] = vetr[iA + i + 1];
      vetr[iA + i + 1] = tempV;
    }
  }
  n--;
  vetr = (Vertice *)realloc(vetr, sizeof(Vertice) * n);
  float **newAdj = (float **)malloc(n * sizeof(float *));
  for (int i = 0; i < n; i++) {
    newAdj[i] = (float *)malloc(n * sizeof(float));
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      newAdj[i][j] = adj[i][j];
    }
    newAdj[i][n - 1] = 0;
  }

  for (int i = 0; i < n; i++) {
    newAdj[n - 1][i] = 0;
  }
  delete[] adj;
  adj = newAdj;
}

int TGrafoND::getV() { return n; }

int TGrafoND::getA() { return m; }

bool TGrafoND::is_adj(int i, int j) { return adj[i][j] == 1; }

Vertice TGrafoND::getVert(int i) { return vetr[i]; }

// Apresenta o Grafo contendo
// n�mero de v�rtices, arestas
// e a matriz de adjac�ncia obtida
void TGrafoND::show() {
  std::cout << "vertices: " << n << std::endl;
  std::cout << "arestas: " << m << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << "\n";
    for (int w = 0; w < n; w++)
      if (adj[i][w] == 1 && adj[w][i] == 1)
        std::cout << "Adj[" << vetr[i].getNome() << "(" << vetr[i].getPeso()
                  << ")"
                  << "," << vetr[w].getNome() << "(" << vetr[w].getPeso() << ")"
                  << "]= 1"
                  << " \n";
  }
  std::cout << "\nfim da impressao do grafo." << std::endl;
}

int TGrafoND::degree(int v) {
  int grau = 0;
  for (int w = 0; w < n; w++)
    if (adj[w][v] != 0 && adj[v][w] != 0)
      grau++;

  return grau;
}

int TGrafoND::grauV(int g[]) {
  for (int i = 0; i < n; i++) {
    g[i] = degree(i);
  }
  return *g;
}

int TGrafoND::percursoProfundidade(int vInicio) {
  int nroNosMarcados = 0, no, nroNosVisitados = 0;
  int *nosMarcados = new int[n];
  Pilha *p = new Pilha();
  nosMarcados = marcarNo(nosMarcados, nroNosMarcados, vInicio);
  p->push(vInicio);
  while (!p->isEmpty()) {
    no = p->pop();
    // Existe nó adjacente a n ainda nÃ£o marcado
    m = noAdjacente(no, nosMarcados);
    while (m != -1) {
      visitarNo(&nroNosVisitados);
      p->push(no);
      marcarNo(nosMarcados, nroNosMarcados, m);
      no = m;
      m = noAdjacente(m, nosMarcados);
    }
  }
  return nroNosVisitados;
}

int TGrafoND::conexidade() {
  int* graus = new int[n];
  grauV(graus);
  for (int i = 0; i < n; i++) {
    if (graus[i] == 0) {
      return 0;
    }
  }
  return 1;
}

void mostraVetor(int *v, int tam) {
  for (int i = 0; i < tam; i++)
    cout << v[i] << " | ";
}

void TGrafoND::caminhoMinimo(string origem, string destino) {
  // INICIALIZAÇÃO DAS VARIÁVEIS
  int *d = new int[n];  // menor distancia da origem até um vértice v
  int *pi = new int[n]; // indica vértice predecessor de v no menor caminho
                        // encontrado - só vai ter indices dentro

  int origem_index = find_index_V(origem),
      destino_index = find_index_V(destino);
  if (origem_index == -1 || destino_index == -1) {
    cout << "Uma das estações não foi encontrada !!" << endl;
    return;
  }

  for (int v = 0; v < n; v++) {
    pi[v] = -2;
    d[v] = 99999;
  }
  d[origem_index] = 0;

  for (int count = 1; count < n - 1; count++) // Para cada Vértice em G
    /* Para cada aresta em G */
    for (int u = 0; u < n; u++)
      for (int v = 0; v < n; v++)
        if (adj[u][v] == 1)
          relaxa(d, pi, v, u);
  /* Para cada aresta em G */
  for (int u = 0; u < n; u++)
    for (int v = 0; v < n; v++) {
      if (adj[u][v] != 1)
        continue;
      if (d[v] > d[u] + (vetr[u].getPeso() + vetr[v].getPeso())) {
        cout << "Não há caminho minimo para estes vértices !! \n";
        return;
      }
    }
  printCaminho(d, pi, destino_index);
  cout << "+- - - - - - - = = = = =(*)= = = = = - - - - - - -+" << endl;
}
