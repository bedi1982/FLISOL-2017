#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "database.h"
#include "qsqlquery.h"
#include "qsqlerror.h"
#include "QTime"
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Database db;

    if(db.Connect()){
        QMessageBox::information(this, tr("Success!"), "Conectado!");
    }else{
        QMessageBox::information(this, tr("Success!"), "Shuif - database Down!");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonBox_accepted()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Clientes(nome, endereco, phone, sexo, cidade) "
                                "values(:nome, :endereco, :phone, :sexo, :cidade)");
    query.bindValue(":nome", ui->line_Name->text());
    query.bindValue(":endereco", ui->line_Address->text());
    query.bindValue(":phone", ui->line_Phone->text());
    query.bindValue(":sexo", ui->line_Name->text());
    query.bindValue(":cidade", ui->line_City->text());

    if(query.exec()){
        QMessageBox::information(this, tr("Success!"), ui->line_Name->text() + "Adicionado ao banco!");
        qDebug() << query.lastError();
    }else{
        QMessageBox::information(this, tr("Chuif!!"), "See debug!");
        qDebug() << query.lastError();
    }

    clear_form();
    ui->line_Name->setFocus();
}

void MainWindow::clear_form()
{
    ui->line_Address->setText("lalalalalala");
    ui->line_City->setText("");
    ui->line_Gender->setText("");
    ui->line_Name->setText("");
    ui->line_Phone->setText("");
}

void MainWindow::on_buttonBox_rejected()
{
    close();
}

void MainWindow::on_pushButton_clicked()
{
    int min = ui->spin_min->value();
    int max = ui->spin_max->value();

    // Create seed for the random
    // That is needed only once on application startup
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    // Get random value between 0-100
    //int randomValue = randInt(0,100);

    qDebug() << qrand() % ((max + 1) - min) + min;

}
