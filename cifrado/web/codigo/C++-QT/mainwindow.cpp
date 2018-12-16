#include "ventanaprincipal.h"
#include "ui_mainwindow.h"

#include "cifrado_cesar.hpp"
#include "inversa.hpp"
#include "inversaporgrupos.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_txtDesplazamiento_textChanged(const QString &arg1)
{

}

void MainWindow::on_btnCifrado_clicked()
{
    QString textoPlano=ui->plainTextEdit_4->toPlainText();

    if(!ui->txtDesplazamiento->text().toStdString().empty()){


    }
}
