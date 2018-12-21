#include "produto.h"

QString Produto::getItem() const
{
    return item;
}

void Produto::setItem(const QString &value)
{
    item = value.toUpper();
}

float Produto::getQuantidade() const
{
    return quantidade;
}

void Produto::setQuantidade(float value)
{
    quantidade = value;
}

QString Produto::getStatus() const
{
    return quantidade >= QUANTIDADE ? "Alto" : "Baixo";
}

Produto::Produto()
{

}

Produto::Produto(QString n, float m)
{
    item = n;
    quantidade = m;

}
