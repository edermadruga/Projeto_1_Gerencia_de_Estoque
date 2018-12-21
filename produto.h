#ifndef PRODUTO_H
#define PRODUTO_H

#include <QObject>

#define QUANTIDADE 10

class Produto
{

private:
    QString item;
    float quantidade;
    bool status;

public:
    explicit Produto();
    Produto(QString n, float m);

    QString getItem() const;
    void setItem(const QString &value);

    float getQuantidade() const;
    void setQuantidade(float value);

    QString getStatus() const;


signals:

public slots:
};

#endif // PRODUTO_H
