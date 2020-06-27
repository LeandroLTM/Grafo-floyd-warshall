#include <iostream>
#include <fstream>  // Biblioteca de manipulação de arquivo.
#include <math.h>   // Biblioteca matemática.
#include "grafo.h"  // Biblioteca do grafo.
using namespace std;
// main com os parâmetros de compilação.
int main(int argc,char *argv[]){

    ifstream ler;   // Variável para manipulação do arquivo.
    ler.open(argv[1]);  // Abertura do arquivo.
    if(ler.is_open()){  // Verificação se o arquivo foi aberto.

        int tamanho;   // Variável que recebe a quantidade de arestas.
        ler >> tamanho;  // Leitura do primeiro valor do arquivo para variável tamanho.
        // Declaração e inicialização da matriz de arestas.
        float **aresta = new float*[tamanho];
        for(int i=0;i<tamanho;i++){
            aresta[i] = new float[3];
        }
        // Leitura do arquivo e preenchimento da matriz.
        for(int i=0;i<tamanho;i++){
            for(int j=0;j<3;j++){
                ler >> aresta[i][j];
            }
        }

        Grafo *grafo = new Grafo(aresta,tamanho); // Declaração e inicialização do objeto da classe grafo.
        grafo->floyd_warshall();    // Chamando método para cálculo do menor caminho.
        grafo->mostrar_caminhos();  // Chamando método para mostras o caminho.

    }else{
    	// Mensagem de erro para quando o arquivo não foi aberto.
        cout<< "Erro na abertura do arquivo" <<endl;
    }

    return 0;
}
