#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

qreal cant_canios,pulv,cant_picos;

int largo,ancho_2,diametro;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int ancho,alto,ranura;





    ancho=ui->tab->width();
    alto=ui->tab->height();

    ranura=alto/10;

    escena->setSceneRect(0,0,ancho,alto);
    ui->graphicsView->setScene(escena);
    //ui->graphicsView->setDragMode(1);

    ui->tabWidget->setTabText(0,"Ingreso de datos");
    ui->tabWidget->setTabText(1,"Grafico");
    ui->tabWidget->setTabEnabled(0,true);
    ui->tabWidget->setTabEnabled(1,false);

    ui->radioCircular->setText("Circular");
    ui->radioCircular->setGeometry(0,ranura,ancho/2,ranura);
    ui->radioCircular->setChecked(false);

    ui->radioRectangular->setText("Rectangular");
    ui->radioRectangular->setGeometry(0,2*ranura,ancho/2,ranura);
    ui->radioRectangular->setChecked(true);

    ui->labelPulv->setText("Diametro de cada Pulverizador");
    ui->labelPulv->setGeometry(0,3*ranura,ancho/2,ranura);
    ui->labelPulv->setVisible(false);

    ui->textEditPulv->setText("Diametro de cada Pulverizador");
    ui->textEditPulv->setGeometry(0,4*ranura,ancho/2,2*ranura);
    ui->textEditPulv->setReadOnly(true);

    ui->lineEditPulv->setGeometry(ancho/2,4*ranura,ancho/2,2*ranura);

    ui->labelDiam->setText("Diametro del recinto");
    ui->labelDiam->setGeometry(0,8*ranura,ancho/2,2*ranura);
    //ui->labelDiam->setVisible(false);

    ui->lineEditDiam->setGeometry(ancho/2,8*ranura,ancho/2,2*ranura);
    //ui->lineEditDiam->setVisible(false);

    ui->labelAncho->setText("Ancho del recinto");
    ui->labelAncho->setGeometry(0,8*ranura,ancho/2,2*ranura);
    //ui->labelAncho->setVisible(false);

    ui->lineEditAncho->setGeometry(ancho/2,8*ranura,ancho/2,2*ranura);
    //ui->lineEditAncho->setVisible(false);

    ui->labelLargo->setText("Largo del Recinto");
    ui->labelLargo->setGeometry(0,10*ranura,ancho/2,2*ranura);
    //ui->labelLargo->setVisible(false);

    ui->lineEditLargo->setGeometry(ancho/2,10*ranura,ancho/2,2*ranura);
    //ui->lineEditLargo->setVisible(false);

    ui->pushButtonCalc->setText("Calcular");
    ui->pushButtonCalc->setGeometry(ancho/4,12*ranura,ancho/2,2*ranura);
    //ui->pushButtonCalc->setVisible(false);

    if(ui->radioCircular->isChecked()){
        ui->labelAncho->setVisible(false);
        ui->lineEditAncho->setVisible(false);
        ui->labelLargo->setVisible(false);
        ui->lineEditLargo->setVisible(false);
        ui->labelDiam->setVisible(true);
        ui->lineEditDiam->setVisible(true);
    }else{
        ui->labelDiam->setVisible(false);
        ui->lineEditDiam->setVisible(false);
        ui->labelAncho->setVisible(true);
        ui->lineEditAncho->setVisible(true);
        ui->labelLargo->setVisible(true);
        ui->lineEditLargo->setVisible(true);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioCircular_clicked()
{
    if(ui->radioCircular->isChecked()){
        ui->labelAncho->setVisible(false);
        ui->lineEditAncho->setVisible(false);
        ui->labelLargo->setVisible(false);
        ui->lineEditLargo->setVisible(false);
        ui->labelDiam->setVisible(true);
        ui->lineEditDiam->setVisible(true);
    }else{
        ui->labelDiam->setVisible(false);
        ui->lineEditDiam->setVisible(false);
        ui->labelAncho->setVisible(true);
        ui->lineEditAncho->setVisible(true);
        ui->labelLargo->setVisible(true);
        ui->lineEditLargo->setVisible(true);
    }
}

void MainWindow::on_radioRectangular_clicked()
{
    if(ui->radioCircular->isChecked()){
        ui->labelAncho->setVisible(false);
        ui->lineEditAncho->setVisible(false);
        ui->labelLargo->setVisible(false);
        ui->lineEditLargo->setVisible(false);
        ui->labelDiam->setVisible(true);
        ui->lineEditDiam->setVisible(true);
    }else{
        ui->labelDiam->setVisible(false);
        ui->lineEditDiam->setVisible(false);
        ui->labelAncho->setVisible(true);
        ui->lineEditAncho->setVisible(true);
        ui->labelLargo->setVisible(true);
        ui->lineEditLargo->setVisible(true);
    }
}

void MainWindow::on_pushButtonCalc_clicked()
{
    ui->tabWidget->setTabEnabled(1,true);
    ui->tabWidget->setCurrentIndex(1);
    pulv=ui->lineEditPulv->text().toDouble();

    if(ui->radioCircular->isChecked()){
        diametro=ui->lineEditDiam->text().toInt();

    }else{
        ancho_2=ui->lineEditAncho->text().toInt();
        largo=ui->lineEditLargo->text().toInt();
        cant_canios=(qreal)ancho_2/pulv;
        qDebug()<< qRound(cant_canios);

        cant_picos=(int)cant_canios*(largo/pulv);
        qDebug()<<cant_picos;
        int x0,y0,xf,yf;
        x0=escena->height()/10;
        xf=escena->height()-x0;
        y0=escena->width()/10;
        yf=escena->width()-y0;
        //escena->addLine(0,0,5,10);
       /* qDebug()<<x0;
        qDebug()<<y0;
        qDebug()<<xf;
        qDebug()<<yf;
        */
        qDebug()<<escena->height();
        qDebug()<<escena->width();

        escena->addLine(100,100,ancho_2,100);
        escena->addLine(100+ancho_2,100,100+ancho_2,largo);

        qDebug()<<ui->graphicsView->height();
        qDebug()<<ui->graphicsView->width();

    }






}
