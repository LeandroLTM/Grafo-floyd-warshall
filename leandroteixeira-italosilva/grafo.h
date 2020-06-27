#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

// Classe que representa um grafo.
class Grafo{
// Métodos públicos da classe.
public:
    Grafo(float **matriz,int tamanho); // Construtor da classe.
    void floyd_warshall();      // Método sem retorno para execução do floyd_warshall, visto em aula.
    void mostrar_caminhos();     // Método sem retorno para selecionar os caminhos.
    void caminho(int i,int j);  // Método para a impressão do caminho entre dois vértices.
// Atributos privados.
private:
    float ***matriz_peso;   // Matriz cúbica dos pesos das arestas.
    int ***matriz_pai;     // Matriz cúbica dos pais de cada vértice.
    int quant_ver;     // Variável com a quantidades de vértices do grafo.
};

#endif // GRAFO_H_INCLUDED
