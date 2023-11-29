#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try{
        Arquivo arquivo;
        arquivo.abrir();
        tabela = new Tabela(ui->tableWidget, arquivo.getVetor(), arquivo.getVertices());
        tabela->atualizar();
    }catch(std::bad_alloc& e){
        QMessageBox::critical(this, "Erro", "Erro ao alocar memoria");
    }
    catch(QString& e){
        QMessageBox::critical(this, "Erro", e);
    }
    catch(...){
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_criar_clicked()
{
    if (tabela)
        delete tabela;
    bool ok;
    int n_vertices = ui->lineEdit_vertices->text().toInt(&ok);
    if (ok){
        try{
            tabela = new Tabela(ui->tableWidget, n_vertices);
            tabela->atualizar();
        }
        catch(std::bad_alloc& e){
            QMessageBox::critical(this, "Erro", "Erro ao alocar memoria");
        }
        catch(QString& e){
            QMessageBox::critical(this, "Erro", e);
        }
        catch(...){
            QMessageBox::critical(this, "Erro", "Erro desconhecido");
        }
    }else{
        QMessageBox::critical(this, "Erro", "N° vertices invalido");
    }
}


void MainWindow::on_pushButton_incluir_clicked()
{
    bool ok;
    int vertice1 = ui->lineEdit_vertice1->text().toInt(&ok);
    try{
        if (!ok)
            throw QString("n° vertices invalido");
        int vertice2 = ui->lineEdit_vertice2->text().toInt(&ok);
        if (!ok){
            throw QString("n° vertices invalido");
        }
        int peso = ui->lineEdit_peso->text().toInt(&ok);
        if (ok){
            try{
                if (!tabela){
                    throw QString("tabela nao criada");
                }
                tabela->inserirAresta(vertice1, vertice2, peso);
            }catch(QString& e){
                QMessageBox::critical(this, "Erro", e);
            }
        }else{
            throw QString("n° peso invalido");
        }
    }catch(QString& e){
        QMessageBox::critical(this, "Erro", e);
    }
    catch(...){
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
}


void MainWindow::on_pushButton_alterar_clicked()
{
    bool ok;
    int vertice1 = ui->lineEdit_vertice1->text().toInt(&ok);
    try{
        if (!ok)
            throw QString("n° vertices invalido");
        int vertice2 = ui->lineEdit_vertice2->text().toInt(&ok);
        if (!ok){
            throw QString("n° vertices invalido");
        }
        int peso = ui->lineEdit_peso->text().toInt(&ok);
        if (ok){
            try{
                if (!tabela){
                    throw QString("tabela nao criada");
                }
                tabela->alterarAresta(vertice1, vertice2, peso);
            }catch(QString& e){
                QMessageBox::critical(this, "Erro", e);
            }
        }else{
            throw QString("n° peso invalido");
        }
    }catch(QString& e){
        QMessageBox::critical(this, "Erro", e);
    }
    catch(...){
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
}


void MainWindow::on_pushButton_excluir_clicked()
{
    bool ok;
    int vertice1 = ui->lineEdit_vertice1->text().toInt(&ok);
    try{
        if (!ok){
            throw QString("n° vertices invalido");
        }
        int vertice2 = ui->lineEdit_vertice2->text().toInt(&ok);
        if (!ok){
            throw QString("n° vertices invalido");
        }
        if (ok){
            if (!tabela){
                throw QString("tabela nao criada");
            }
            tabela->removerAresta(vertice1, vertice2);
        }
    }catch(QString& e){
        QMessageBox::critical(this, "Erro", e);
    }
    catch(...){
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
}

