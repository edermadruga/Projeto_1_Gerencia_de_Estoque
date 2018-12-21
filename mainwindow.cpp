#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionSalvar,SIGNAL(triggered()), this, SLOT(salvar()));
    connect(ui->actionCarregar,SIGNAL(triggered()), this, SLOT(carregar()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::atualizarEstatisticas()
{
    ui->lbl_avg->setText(QString::number(eletronica.quantidadeTotaldaLoja(),'f',2));
    ui->lbl_highest->setText(QString::number(eletronica.maiorQuantidade(),'f',2));
    ui->lbl_lowest->setText(QString::number(eletronica.menorQuantidade(),'f',2));

    QString color = eletronica.quantidadeTotaldaLoja() < 50 ? "red" : "black";
    ui->lbl_avg->setStyleSheet("color: "+color);

}

void MainWindow::inserirItemNaTabela(Produto produto, int row)
{
    ui->tbl_data->setItem(row,0,new QTableWidgetItem(produto.getItem()));
    ui->tbl_data->setItem(row,1,new QTableWidgetItem(QString::number(produto.getQuantidade())));
    ui->tbl_data->setItem(row,2,new QTableWidgetItem(produto.getStatus()));
    ui->tbl_data->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tbl_data->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tbl_data->setStyleSheet("QTableView {selection-background-color:blue}");
}

void MainWindow::salvar()
{

    QString nomeArquivo = QFileDialog::getSaveFileName(this,"Lista de Itens","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
    if( GerenciadorDeArquivos::salvarLoja(nomeArquivo,eletronica) ){
        QMessageBox::information(this, "Salvar loja","Dados Salvos com Sucesso");
    }else{
        QMessageBox::information(this, "Salvar loja","Não foi possível salvar os dados");
    }

}

void MainWindow::carregar()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Lista de Itens","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
    eletronica.clear();

    if(GerenciadorDeArquivos::carregarLoja(nomeArquivo,eletronica)){

        ui->tbl_data->clearContents();
        for(int i=0;i<eletronica.size();i++){

            if(i >= ui->tbl_data->rowCount())
                ui->tbl_data->insertRow(i);

            inserirItemNaTabela(eletronica[i],i);
        }
        atualizarEstatisticas();

    }else{
        QMessageBox::information(this, "Carregar loja","Não foi possível carregar os dados");
    }

}

void MainWindow::on_btn_insert_clicked()
{

    if(ui->le_nameInput->text().size() != 0 && ui->le_avgInput->text().size() != 0){
        Produto produto;

        if(eletronica.encontarItem(ui->le_nameInput->text().toUpper())==true){
            QMessageBox::information(this,"Duplicidade","Item Duplicado");
        }else{

        produto.setItem(ui->le_nameInput->text());
        produto.setQuantidade(ui->le_avgInput->text().toFloat());

        int qnt_row = ui->tbl_data->rowCount();

        ui->tbl_data->insertRow(qnt_row);
        inserirItemNaTabela(produto, qnt_row);


        ui->le_nameInput->clear();
        ui->le_avgInput->clear();

        eletronica.inserirProduto(produto);
        atualizarEstatisticas();
        }
    }
}

void MainWindow::on_btn_NameSort_clicked()
{
    ui->tbl_data->clearContents();

    eletronica.ordenarPorProduto();
    for(int i = 0; i<eletronica.size(); i++){
        inserirItemNaTabela(eletronica[i], i);
    }
}

void MainWindow::on_btn_GradeSort_clicked()
{
    ui->tbl_data->clearContents();
    eletronica.ordenarPorQuantidade();
    for(int i = 0; i<eletronica.size();i++){
        inserirItemNaTabela(eletronica[i],i);
    }
}

void MainWindow::on_btn_excluir_clicked()
{
    int linha=ui->tbl_data->currentRow();
    int id=ui->tbl_data->item(linha,0)->text().toInt();
    ui->tbl_data->removeRow(linha);
    QMessageBox::information(this,"Mensagem de Exclusão","Registro Excluido");
    eletronica.remove(linha);

}

void MainWindow::on_btn_editar_clicked()
{
    int linha=ui->tbl_data->currentRow();
    ui->le_nameInput->setText(ui->tbl_data->item(linha,0)->text());
    ui->le_avgInput->setText(ui->tbl_data->item(linha,1)->text());
    ui->tbl_data->removeRow(linha);
    eletronica.remove(linha);
}
