#ifndef GERENCIADORDEARQUIVOS_H
#define GERENCIADORDEARQUIVOS_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QDebug>

#include "loja.h"
#include "produto.h"


class GerenciadorDeArquivos
{
public:
    GerenciadorDeArquivos();
    static bool salvarLoja(QString &arquivo, Loja &loja);
    static bool carregarLoja(QString &arquivo, Loja &loja);
};

#endif // GERENCIADORDEARQUIVOS_H
