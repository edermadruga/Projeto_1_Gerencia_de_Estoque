#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>

#include "gerenciadordearquivos.h"
#include "produto.h"
#include "loja.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Loja eletronica;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void atualizarEstatisticas();

private slots:
    void on_btn_insert_clicked();

    void on_btn_NameSort_clicked();

    void on_btn_GradeSort_clicked();

    void salvar();
    void carregar();

    void on_btn_excluir_clicked();

    void on_btn_editar_clicked();

private:
    Ui::MainWindow *ui;
    void inserirItemNaTabela(Produto produto, int row);


};

#endif // MAINWINDOW_H
