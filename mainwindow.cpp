#include <QtGui>

#include "renderarea.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox> // inputing
#include <QString> // toFloat

const int IdRole = Qt::UserRole;

/*fine 2*/
void MainWindow::shapeChanged()
 {
     RenderArea::Shape shape = RenderArea::Shape(ui->comboBox->itemData(
     ui->comboBox->currentIndex(), IdRole).toInt());
     ui->renderArea->setShape(shape);
 }
/*end fine 2*/

/*spin box*/
//void MainWindow::
/*end spin*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //I need to edit this mmmm later just make sure it works first
    ui->comboBox->addItem(tr("Choisir une figure"), RenderArea::foo);
    ui->comboBox->addItem(tr("Triangle de Sierpinski"), RenderArea::Sierpinski);
    ui->comboBox->addItem(tr("Von Koch"), RenderArea::Koch);
    ui->comboBox->addItem(tr("Tree"), RenderArea::Tree);
    ui->comboBox->addItem(tr("basic Chaos"), RenderArea::Chaos1);
    ui->comboBox->addItem(tr("Chaos 1"), RenderArea::Chaos2);
    ui->comboBox->addItem(tr("Chaos 2"), RenderArea::Chaos3);
    ui->comboBox->addItem(tr("Barnsley Fern"), RenderArea::Barnsley);
    ui->comboBox->addItem(tr("Julia Set"), RenderArea::Julia);
    ui->comboBox->addItem(tr("Mandelbrot Set"), RenderArea::Mandelbrot);
    ui->comboBox->addItem(tr("Text"), RenderArea::Text);
    /*fine 2*/
    connect(ui->comboBox, SIGNAL(activated(int)),
                 this, SLOT(shapeChanged()));
    shapeChanged();
    /*end fine 2*/



}

MainWindow::~MainWindow()
{
    delete ui;
}

/*inputting*/
/*void MainWindow::on_pushButton_clicked()
{
    //ui->lineEdit->setText("Hello khawla");
    QString input = ui->lineEdit->text();
    int num = input.toFloat();
    if(num==0)
        QMessageBox::information(this,"Attention","Vous devez entrer un nombre > 0");
    else
        ui->renderArea->setNum(num);


}*/

void MainWindow::on_lineEdit_returnPressed()
{
    //ui->lineEdit->setText("Hello khawla");
    QString input = ui->lineEdit->text();
    int num = input.toFloat();
    if(num==0)
        QMessageBox::information(this,"Attention","Vous devez entrer un nombre > 0");
    else
        ui->renderArea->setNum(num);
}
/*end inpt*/
