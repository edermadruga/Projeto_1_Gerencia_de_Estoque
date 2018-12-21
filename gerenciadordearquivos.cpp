#include "gerenciadordearquivos.h"


GerenciadorDeArquivos::GerenciadorDeArquivos()
{

}

bool GerenciadorDeArquivos::salvarLoja(QString &arquivo, Loja &loja)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }

    QTextStream out(&file);

    for(int i=0;i<loja.size();i++){
        out << loja[i].getItem()<<","<<loja[i].getQuantidade()<<"\n";
    }

    file.close();
    return true;
}

bool GerenciadorDeArquivos::carregarLoja(QString &arquivo, Loja &loja)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QTextStream in(&file);

    QString linha;

    while(!in.atEnd()){
        linha = in.readLine();

        QStringList dados = linha.split(",");

        Produto a(dados[0],dados[1].toFloat());
        loja.inserirProduto(a);

    }

    return true;
}
