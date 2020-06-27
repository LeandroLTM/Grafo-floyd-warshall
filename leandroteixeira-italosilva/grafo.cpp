#include <iostream>
#include "grafo.h"
#include <math.h>
using namespace std;

// Construtor da classe, ele recebe uma matriz de arestas para preenchimento das variáveis.
Grafo::Grafo(float **matriz, int tamanho){
    this->quant_ver = 0;

    // Este for percorre a matriz de arestas que foi passa por parâmetro, para achar a maior
    // aresta, depois atribui o valor dela para a variável quant_ver da classe grafo.
    for(int i=0;i<tamanho;i++){
        if(this->quant_ver < matriz[i][0]){
            this->quant_ver = matriz[i][0];
        }
    }
    // Inicialização do vetor de matrizes peso e pai, baseado no maior vértice do grafo passado.
    this->quant_ver++;
    this->matriz_peso = new float**[quant_ver + 1];
    this->matriz_pai = new int**[quant_ver + 1];

    // Inicialização das matrizes do vetor.
    for(int i=0;i<quant_ver +1;i++){
       this->matriz_peso[i] = new float*[quant_ver];
       this->matriz_pai[i] = new int*[quant_ver];
       for(int j=0;j<quant_ver;j++){
            this->matriz_peso[i][j] = new float[quant_ver];
            this->matriz_pai[i][j] = new int[quant_ver];
       }
    }

    // Atribuindo as matrizes de peso e pai na posição 0, com o valor de INFITO para a de peso
    // e -1 para a de pai.
    for(int i=0;i<this->quant_ver;i++){
        for(int j=0;j<this->quant_ver;j++){
            this->matriz_peso[0][i][j] = INFINITY;
            this->matriz_pai[0][i][j] = -1;
        }
    }

    // Percorrendo a matriz de arestas passada por parâmetro, e preenchendo as matriz de peso e pai
    // com as arestas existentes.
    for(int i=0;i<tamanho;i++){
        if(this->matriz_peso[0][(int)matriz[i][0]][(int)matriz[i][0]] == INFINITY){
            this->matriz_peso[0][(int)matriz[i][0]][(int)matriz[i][0]] = 0;
        }
        this->matriz_peso[0][(int)matriz[i][0]][(int)matriz[i][2]] = matriz [i][1];
        this->matriz_pai[0][(int)matriz[i][0]][(int)matriz[i][2]] = (int)matriz[i][0];
    }

}

// Método da classe grafo que executa as interações do método floyd warshall tentando inserir um
// novo vértice k em todos os caminhos.
void Grafo::floyd_warshall(){
    for(int k=0;k < this->quant_ver;k++){
        for(int i=0;i < this->quant_ver;i++){
            for(int j=0;j < this->quant_ver;j++){
            	// Verificação que compara se o custo inserindo a novo vértice k irá diminuir o custo do caminho.
                if(matriz_peso[k][i][j] > matriz_peso[k][i][k]+matriz_peso[k][k][j]){
                	// Se o custo do novo vértice e menor ele é inserido no caminho.
                    this->matriz_peso[k+1][i][j] = this->matriz_peso[k][i][k]+this->matriz_peso[k][k][j];
                    this->matriz_pai [k+1][i][j] = matriz_pai [k][k][j];
                }else{
                	// Se o custo do novo vértice é maior conserva o caminho já existente.
                    this->matriz_peso[k+1][i][j] = this->matriz_peso[k][i][j];
                    this->matriz_pai [k+1][i][j] = this->matriz_pai[k][i][j];
                }
            }
        }
    }
}

// Método recursiva para imprimir na dela o caminho de um vértice a outro passando os vértice por parâmetro.
void Grafo::caminho(int i,int j){
	// Verificação se o vértice de origem e destino são os mesmos. (condição de parada)
    if(!(i == j)){
    	// Se ainda não chegou na origem chama o método novamente passando o pai do destino atual.
        this->caminho(i,matriz_pai[this->quant_ver][i][j]);
    }
    // Verifica se está na origem para não imprimir o a seta (->).
    if(i == j){
        cout<< j;
    }else{
        cout<< " -> " <<  j;
    }

}

// Método que percorre todos o vértices como origem, e para cada origem percorre todos os vértices de destino,
// chamando o método caminho para imprimir o caminho dos vértices.
void Grafo::mostrar_caminhos(){
    for(int i=0;i<this->quant_ver;i++){
        for(int j=0;j<this->quant_ver;j++){
            if(!(i == j)){
               this->caminho(i,j);
               cout<<" ( "<<this->matriz_peso[this->quant_ver][i][j]<<" ) "<<endl;
            }
        }
    }
}
