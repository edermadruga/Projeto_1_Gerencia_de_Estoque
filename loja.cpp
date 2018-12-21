#include "loja.h"

Loja::Loja(QObject *parent) : QObject(parent)
{

}

void Loja::inserirProduto(const Produto a)
{
    loja.push_back(a);
}

float Loja::quantidadeTotaldaLoja()
{
    return std::accumulate(loja.begin(),loja.end(),0.0, [](float acc, Produto a){return acc+=a.getQuantidade();});
}

float Loja::maiorQuantidade()
{
    Produto *maior = std::max_element(loja.begin(),loja.end(),[](Produto a, Produto b){ return a.getQuantidade() < b.getQuantidade();});
    return maior->getQuantidade();
}

float Loja::menorQuantidade()
{
    Produto *menor = std::min_element(loja.begin(),loja.end(),[](Produto a, Produto b){return a.getQuantidade() < b.getQuantidade();});
    return menor->getQuantidade();
}

void Loja::ordenarPorProduto()
{
    std::sort(loja.begin(), loja.end(), [](Produto a, Produto b){return a.getItem()<b.getItem();});
}

void Loja::ordenarPorQuantidade()
{
    ordenarPorProduto();
    std::stable_sort(loja.begin(),loja.end(),[](Produto a, Produto b){return a.getQuantidade()<b.getQuantidade();});

}

int Loja::size()
{
    return loja.size();
}

void Loja::clear()
{
    loja.clear();
}

void Loja::remove(int i)
{
    loja.remove(i);
}

Produto Loja::operator[](int i)
{
    return loja[i];
}

bool Loja::encontarItem(QString item)
{

QString nome = item;
auto e = std::find_if(loja.begin(),loja.end(), [&](Produto a){return a.getItem()==nome;} );

if(e != loja.end()){
    return true;

}else{
    return false;
}

}
