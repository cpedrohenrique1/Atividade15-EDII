#include "grafo.h"

Grafo::Grafo() : peso(0),
                 n_vertices(0)
{
}

Grafo::Grafo(const int &n_vertices) : peso(0),
                                      n_vertices(0)
{
    if (n_vertices < 0){
        throw QString("vertice invalido");
    }
    this->n_vertices = n_vertices;
    try{
        peso = new int*[n_vertices];
        for (int i = 0; i < n_vertices; ++i){
            peso[i] = new int[n_vertices];
            for (int j = 0; j < n_vertices; ++j){
                peso[i][j] = -1;
            }
        }
    }catch(std::bad_alloc& e){
        throw QString("Erro ao alocar memoria");
    }
}
void Grafo::inserirAresta(const int &vertice1, const int &vertice2, const int &peso){
    if (!(this->peso)){
        throw QString("Peso nao criado");
    }
    if ((vertice1 <= 0 || vertice2 <= 0) || (vertice1 > n_vertices || vertice2 > n_vertices)){
        throw QString("Vertice invalida");
    }
    if (peso < 0){
        throw QString("Peso invalido");
    }
    if (this->peso[vertice1 - 1][vertice2 - 1] != -1){
        throw QString("Elemento ja existe");
    }
    this->peso[vertice1 - 1][vertice2 - 1] = peso;
    this->peso[vertice2 - 1][vertice1 - 1] = peso;
}

void Grafo::alterarAresta(const int &vertice1, const int &vertice2, const int &peso){
    if (!(this->peso)){
        throw QString("Peso nao criado");
    }
    if ((vertice1 <= 0 || vertice2 <= 0) || (vertice1 > n_vertices || vertice2 > n_vertices)){
        throw QString("Vertice invalida");
    }
    if (peso < 0){
        throw QString("Peso invalido");
    }
    if ((this->peso[vertice1 - 1][vertice2 - 1] == -1)){
        throw QString("Elemento nao existe");
    }
    this->peso[vertice1 - 1][vertice2 - 1] = peso;
    this->peso[vertice2 - 1][vertice1 - 1] = peso;
}
void Grafo::removerAresta(const int &vertice1, const int &vertice2){
    if (!(this->peso)){
        throw QString("Peso nao criado");
    }
    if ((vertice1 <= 0 || vertice2 <= 0) || (vertice1 > n_vertices || vertice2 > n_vertices)){
        throw QString("Vertice invalida");
    }
    if (this->peso[vertice1 - 1][vertice2 - 1] == -1){
        throw QString("Elemento nao existe");
    }
    this->peso[vertice1 - 1][vertice2 - 1] = -1;
    this->peso[vertice2 - 1][vertice1 - 1] = -1;
}
int Grafo::getNVertices() const{
    return n_vertices;
}

int Grafo::getNOGrafo(const int& i, const int& j)const{
    if ((i < 0 || i > n_vertices) || (j < 0 || j > n_vertices)){
        throw QString("indice invalido");
    }
    return peso[i][j];
}

Grafo::~Grafo(){
    if (peso){
        for (int i = 0; i < n_vertices; ++i){
            if (peso[i]){
                delete peso[i];
            }
        }
        delete[] peso;
    }
}
