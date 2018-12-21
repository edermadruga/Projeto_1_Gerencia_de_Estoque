#ifndef LOJA_H
#define LOJA_H

#include <QObject>
#include <QVector>
#include <numeric>
#include <algorithm>

#include "produto.h"

class Loja : public QObject
{
    Q_OBJECT
private:
    QVector<Produto> loja;

public:
    explicit Loja(QObject *parent = nullptr);
    void inserirProduto(const Produto a);
    float quantidadeTotaldaLoja();
    float maiorQuantidade();
    float menorQuantidade();
    void ordenarPorProduto();
    void ordenarPorQuantidade();

    int size();
    void clear();
    void remove(int i);
    bool encontarItem(QString item);

    Produto operator[](int i);


signals:

public slots:
};

#endif // LOJA_H
