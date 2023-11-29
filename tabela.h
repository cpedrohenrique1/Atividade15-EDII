#ifndef TABELA_H
#define TABELA_H

#include "QTableWidget"
#include "QHeaderView"
#include "grafo.h"

class Tabela
{
private:
    QTableWidget *tabela;
    Grafo *grafo;
    int tamanho_tabela;

public:
    Tabela();
    Tabela(QTableWidget *parent, const int &tamanho);
    Tabela(QTableWidget *parent, Grafo* grafo, const int& tamanho);
    ~Tabela();
    void start();
    void limpar();
    void atualizar();
    void inserirAresta(const int &vertice1, const int& vertice2, const int &peso);
    void alterarAresta(const int &vertice1, const int& vertice2, const int &peso);
    void removerAresta(const int &vertice1, const int& vertice2);
    Grafo *getVetor() const;
};

#endif // TABELA_H