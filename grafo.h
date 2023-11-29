#ifndef GRAFO_H
#define GRAFO_H

#include <QString>

class Grafo
{
private:
    int** peso;
    int n_vertices;
public:
    Grafo();
    Grafo(const int& n_vertices);
    void inserirAresta(const int& vertice1, const int& vertice2, const int& peso);
    void alterarAresta(const int& vertice1, const int& vertice2, const int& peso);
    void removerAresta(const int& vertice1, const int& vertice2);
    int getNVertices()const;
    int getNOGrafo(const int& i, const int& j)const;
    ~Grafo();
};

#endif // GRAFO_H
