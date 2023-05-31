/* PROJETO TEORIA DOS GRAFOS - METRO */
// Claudia Fiorentino Andrade - 42005302
// João Victor Ferreira Pimenta - 42005876
// Joyce Cui - 42017157
// Ryan Marco Andrade dos Santos - 42080223

/* BIBLIOTECAS E CLASSES ================================================ */
#include "TGrafoND.h"
#include <iostream>
#include <string>
#include "algorithm"
#include <fstream>
#include <sstream>
using namespace std;

/* PROTÓTIPOS =========================================================== */
void show_menu();
void le_cria_g(string n_arq, TGrafoND *Grafo);
void mostrar_conteudo_arq(string n_arq);
void salva_grafo(TGrafoND *grafo);

/* MAIN ================================================================= */
int main() {
  // Vertice v[6];
  // v[0].setNome("A");
  // v[0].setPeso(1);
  // v[1].setNome("D");
  // v[1].setPeso(2);
  // v[2].setNome("C");
  // v[2].setPeso(10);
  // v[3].setNome("F");
  // v[3].setPeso(3);
  // v[4].setNome("E");
  // v[4].setPeso(1);
  // v[5].setNome("B");
  // v[5].setPeso(4);
  
  // TGrafoND g(6, v);
  // g.insereA("A","D");
  // g.insereA("A","C");
  // g.insereA("C","E");
  // g.insereA("C","F");
  // g.insereA("F","B");
  // g.insereA("C","B");
  // g.show();

  
  // g.show();
  // std::cout << "________________________________\n" << std::endl;
  //   std::cout << "EXEMPLO DE INSERCAO DE VERTICE\n" << std::endl;

  // g.insereV("bresser mooca", 29);
  // g.show();
  // std::cout << "________________________________\n" << std::endl;
  //   std::cout << "EXEMPLO DE REMOCAO DE ARESTA\n" << std::endl;
  // g.removeA("carrao","tatuape");
  // g.show();
  // std::cout << "________________________________\n" << std::endl;
  // std::cout << "EXEMPLO DE REMOCAO DE VERTICE\n" << std::endl;
  // g.removeV("tatuape");
  // g.show();

  int option, p;
  string v1, v2;
  Vertice* v;
  TGrafoND g(0, v);
  bool menu = true;
  while (menu != false) {
    show_menu();
    cin >> option;
    cout << '\n';
    switch (option) {
    case 1:
      le_cria_g("Projeto.txt", &g);
      break;
    case 2:
      salva_grafo(&g);
      break;
    case 3:
      cout << "Insira o nome do vertice: ";
      getline(cin >> ws, v1);
      cout << '\n';
      cout << "Insira o peso do vertice: ";
      cin >> p;
      cout << '\n';
      g.insereV(v1, p);
      g.show();
      break;
    case 4:
      cout << "Insira o nome do vertice 1: ";
     getline(cin >> ws, v1);
      cout << '\n';
      cout << "Insira o nome do vertice 2: ";
      getline(cin >> ws, v2);
      cout << '\n';
      g.insereA(v1,v2);
      g.show();
      break;
    case 5:
      cout << "Insira o nome do vertice: ";
      getline(cin >> ws, v1);
      std::cout << '\n';
      g.removeV(v1);
      g.show();
      break;
    case 6:
      cout << "Insira o nome do vertice 1: ";
      getline(cin >> ws, v1);
      cout << "Insira o nome do vertice 2: ";
      getline(cin >> ws, v2);
      g.removeA(v1, v2);
      g.show();
      break;
    case 7:
      mostrar_conteudo_arq("Projeto.txt");
      break;
    case 8:
      g.show();
      break;
    case 9:
      cout << "Conexidade: " << g.conexidade() << endl;
      break;
    case 10:
      cout << "CAMINHO MÍNIMO \n";
      cout << "Insira o nome da estação atual: \n";
      getline(cin >> ws, v1);
      cout << "Insira o nome da estação destino: \n";
      getline(cin >> ws, v2);
      g.caminhoMinimo(v1, v2);
      cout << endl;
      break;
    case 11:
      cout << "OBJETIVOS ODS \n";
      cout << "Nosso projeto está associado a dois objetivos da ODS, sendo "
              "estes: \n"
           << " * Objetivo 8 - Emprego Decente e Crescimento Econômico\n"
           << " * Objetivo 11 - Cidades e Comunidades Sustentáveis\n"
           << "O objetivo 8 almeja “Promover o crescimento econômico "
              "sustentado, inclusivo e sustentável, emprego pleno e produtivo, "
              "e trabalho decente para todos”. A subseção 8.2 aborda como meta "
              " “Atingir níveis mais elevados de produtividade das economias "
              "por meio da diversificação, modernização tecnológica e "
              "inovação, inclusive por meio de um foco em setores de alto "
              "valor agregado e dos setores intensivos em mão de obra”, "
              "associando-se ao nosso projeto a medida que, com a obtenção de "
              "uma rota de menor circulação. propicia-se um ambiente de maior "
              "acomodação. Isso favorece a redução de estresse da rotina dos "
              "indivíduos e, por consequência, a elevação da produtividade em "
              "sua rotina, gerando qualidade de vida. \n"
           << "O objetivo 11 pretende “Tornar as cidades e os assentamentos "
              "humanos inclusivos, seguros, resilientes e sustentáveis”. A "
              "subseção 11.6 aponta como meta “Até 2030, reduzir o impacto "
              "ambiental negativo per capita das cidades, inclusive prestando "
              "especial atenção à qualidade do ar, gestão de resíduos "
              "municipais e outros”, sendo assim conectado ao nosso projeto "
              "conforme o incentivo de utilização do metrô contribui para a "
              "redução do uso de carros, principais responsáveis pelo impacto "
              "ambiental negativo nas cidades, pois afetam diretamente na "
              "qualidade do ar.\n";
      break;
    case 12:
      cout << "Fim do Programa!\n";
      menu = false;
      break;
    default:
      cout << "Entrada inválida! Insira outro valor: ";
      cin >> option;
      break;
    }

    std::cout << '\n';
  }
  return 0;
}

/* FUNÇÕES  ============================================================= */
void show_menu() {
  std::cout << "Bem vindo ao nosso projeto de grafos, escolha uma opcao: \n"
            << "[1]  Ler dados do arquivo Projeto.txt;\n"
            << "[2]  Gravar dados no arquivo grafo.txt;\n"
            << "[3]  Inserir vértice;\n"
            << "[4]  Inserir aresta;\n"
            << "[5]  Remove vértice;\n"
            << "[6]  Remove aresta;\n"
            << "[7]  Mostrar conteúdo do arquivo;\n"
            << "[8]  Mostrar grafo;\n"
            << "[9] Confira a conexidade;\n"
            << "[10] Encontrar a melhor rota (Caminho mínimo);\n"
            << "[11] Objetivos ODS relacionados com o projeto;\n"
            << "[12] Encerrar a aplicação.\n"
            << "Option: ";
}

void le_cria_g(string n_arq, TGrafoND* Grafo)
{
  string linha, nome_a, nome_b, peso_s;
  ifstream arq(n_arq);
  int n, m, peso;

  /* Verifica se o arquivo foi aberto */
  if (arq.is_open())
  {
    /* Lê a primeira e segunda linha e as interpreta */
    getline(arq, linha); cout << "O tipo de grafo é NÃO DIRECIONADO - TIPO 1\n"; 
    getline(arq, linha); n = stoi(linha);

    /* Insere os vértices até chegar ao fim do arquivo */
    /* ou alcançar a quantidade descrita              */
    cout << "----------------VERTICES----------------" << endl;
    while(n > 0 && getline(arq, linha))
    {
      stringstream ss(linha);
      getline(ss, nome_a, ','); getline(ss, peso_s);
      peso = stoi(peso_s);
      cout << nome_a << "   " << peso_s << endl;
      Grafo->insereV(nome_a, peso); n--;
    }
    /* Adquire a quantidade de arestas */
    getline(arq, linha); m = stoi(linha);
    cout << "----------------ARESTAS----------------" << endl;
    /* Insere as arestas até chegar ao fim do arquivo */
    /* ou alcançar a quantidade descrita              */
    while(m >= 0 && getline(arq, linha))
    {
      stringstream ss(linha);
      getline(ss, nome_a, ','); getline(ss, nome_b);
      cout << nome_a << "   " << nome_b << endl;
      Grafo->insereA(nome_a, nome_b); m--;
    }
  }
  else cout << "Não foi possível abrir o arquivo !!\n";
}

void mostrar_conteudo_arq(string n_arq) 
{
  string linha;
  ifstream arq(n_arq);

  while (arq.is_open() && getline(arq, linha))
    cout << linha << endl;

  arq.close();
}

void salva_grafo(TGrafoND* grafo) 
{
  ofstream saida("grafo.txt");
  int n = grafo->getV();

  // Coloca as duas primeiras linhas 
  saida << 1 << endl;
  saida << n << endl;
  // Roda cada vértice e adquire o nome dele
  for (int i = 0; i < n; i++)
    saida << grafo->getVert(i).getNome() << "," << grafo->getVert(i).getPeso() << endl;
  saida << grafo->getA() << endl;
  // Roda cada vértice e verifica quais são os adjacentes a ele
  for (int i = 0; i < n; i++)
    for (int j = i; j < n - 1; j++)
      if (grafo->is_adj(i, j)) saida << grafo->getVert(i).getNome() << "," << grafo->getVert(j).getNome() << endl;
  saida.close(); return;
}
