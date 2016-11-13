#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <math.h>

qreal cant_canios,pulv,cant_picos;

qreal largo,ancho_2,diametro;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int ancho,alto,ranura;







    //escena->setSceneRect(0,0,ancho,alto);
    ui->graphicsView->setScene(escena);
    //ui->graphicsView->setSceneRect(0,0,480,640);
    //ui->graphicsView->setDragMode(1);

    alto=ui->graphicsView->height();
    ancho=ui->graphicsView->width();

    /*ancho=ui->tab->width();
    alto=ui->tab->height();

    ancho=ui->tabWidget->width();
    alto=ui->tabWidget->height(); */

    ranura=alto/10;

    ui->tabWidget->setTabText(0,"Ingreso de datos");
    ui->tabWidget->setTabText(1,"Grafico");
    ui->tabWidget->setTabEnabled(0,true);
    ui->tabWidget->setTabEnabled(1,false);

    ui->radioCircular->setText("Circular");
    ui->radioCircular->setGeometry(0,ranura,ancho/2,ranura);
    ui->radioCircular->setChecked(true);

    ui->radioRectangular->setText("Rectangular");
    ui->radioRectangular->setGeometry(0,2*ranura,ancho/2,ranura);
    ui->radioRectangular->setChecked(false);

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

    QPen bordes,canios,pulve;

    bordes.setWidth(4);
    bordes.setColor(QColor(0,0,0));

    canios.setWidth(3);
    canios.setColor(QColor(0,0,255));

    pulve.setWidth(3);
    pulve.setColor(QColor(0,255,0));

    escena->clear();

    int alt,anc;
    alt=ui->graphicsView->height();
    anc=ui->graphicsView->width();

    qreal escala,esc_x,esc_y,escala_2;

    if(ui->radioCircular->isChecked()){
        diametro=ui->lineEditDiam->text().toDouble();
        cant_canios=(qreal)diametro/pulv/2;
        qDebug()<< cant_canios;
        cant_canios=qRound(cant_canios);

        esc_x=0.9*anc/(qreal)diametro;
        esc_y=0.9*alt/(qreal)diametro;
        if(esc_x>=esc_y){
            escala=esc_y;
        }else{
            escala=esc_x;
        }
        escala_2=0.9*escala;

        cant_picos=0;

        escena->addLine(0,-alt/2,0,alt/2);
        escena->addLine(-anc/2,0,anc/2,0);
        escena->addEllipse(-escala_2*diametro/2,-escala_2*diametro/2,escala_2*diametro,escala_2*diametro,bordes);

        int i,j;
        qreal d_tmp;
        for(i=0;i<cant_canios;i++){
            escena->addEllipse(-escala_2*(diametro-pulv*(2*i+1))/2,-escala_2*(diametro-pulv*(2*i+1))/2,escala_2*(diametro-pulv*(2*i+1)),escala_2*(diametro-pulv*(2*i+1)),canios);
            //qDebug()<<(diametro-pulv*(2*i+1));
            //for(j=0)
            cant_picos=3.1416*(diametro-pulv*(2*i+1))/pulv;
            cant_picos=qRound(cant_picos);
            //qDebug()<<cant_picos;
            d_tmp=(diametro-pulv*(2*i+1));
            qDebug()<<d_tmp;

            for(j=0;j<cant_picos;j++){
                if(d_tmp<pulv/2){
                    escena->addEllipse(-escala_2*pulv/2,-escala_2*pulv/2,escala_2*pulv,escala_2*pulv,pulve);
                }else{
                    escena->addEllipse(escala_2*(d_tmp/2*cos(j*2*3.1416/cant_picos)-pulv/2),escala_2*(d_tmp/2*sin(j*2*3.1416/cant_picos)-pulv/2),escala_2*pulv,escala_2*pulv,pulve);
                }
              /*  qDebug()<<d_tmp/2*cos(j*2*3.1416/cant_picos);
                qDebug()<<d_tmp/2*sin(j*2*3.1416/cant_picos); */
            }
        }




    }else{
        ancho_2=ui->lineEditAncho->text().toDouble();
        largo=ui->lineEditLargo->text().toDouble();
        cant_canios=(qreal)ancho_2/pulv;
        //qDebug()<< qRound(cant_canios);


        cant_picos=(int)cant_canios*(largo/pulv);
        qDebug()<<cant_picos;




        esc_x=0.9*anc/(qreal)ancho_2;
        esc_y=0.9*alt/(qreal)largo;
        if(esc_x>=esc_y){
            escala=esc_y;
        }else{
            escala=esc_x;
        }
        escala_2=0.9*escala/2;



        escena->addLine(-escala_2*(qreal)ancho_2,-escala_2*(qreal)largo,escala_2*(qreal)ancho_2,-escala_2*(qreal)largo,bordes);
        escena->addLine(escala_2*(qreal)ancho_2,-escala_2*(qreal)largo,escala_2*(qreal)ancho_2,escala_2*(qreal)largo,bordes);
        escena->addLine(escala_2*(qreal)ancho_2,escala_2*(qreal)largo,-escala_2*(qreal)ancho_2,escala_2*(qreal)largo,bordes);
        escena->addLine(-escala_2*(qreal)ancho_2,escala_2*(qreal)largo,-escala_2*(qreal)ancho_2,-escala_2*(qreal)largo,bordes);

        int i,j;
        for(i=0;i<(int)cant_canios;i++){
            escena->addLine(-escala_2*(qreal)ancho_2+escala_2*(qreal)ancho_2/(int)cant_canios*(2.0*i+1.0),-0.95*escala*(qreal)largo/2,-escala_2*(qreal)ancho_2+escala_2*(qreal)ancho_2/(int)cant_canios*(2.0*i+1.0),escala_2*(qreal)largo,canios);
            for(j=0;j<largo/pulv;j++){
                if(i%2==0){
                   escena->addEllipse(-escala_2*(qreal)ancho_2+escala_2*(qreal)ancho_2/(int)cant_canios*(2.0*i+1.0)-2*escala_2*pulv/2,-escala_2*(qreal)largo+escala_2*pulv*(2.0*j+1.0)-2*escala_2*pulv/2,2*escala_2*pulv,2*escala_2*pulv,pulve);
                }else{
                    escena->addEllipse(-escala_2*(qreal)ancho_2+escala_2*(qreal)ancho_2/(int)cant_canios*(2.0*i+1.0)-2*escala_2*pulv/2,-escala_2*(qreal)largo+escala_2*pulv*(2.0*j+1.0)-4*escala_2*pulv/2,2*escala_2*pulv,2*escala_2*pulv,pulve);
                }
            }
        }
    }






}
