#include "recvideo.h"
#include "ui_recvideo.h"
#include "string.h"
#include "QMessageBox"
#include "QFileDialog"
#include "QDesktopServices"
#include "QDebug"
#include "QUrl"

recvideo::recvideo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::recvideo)
{

    ui->setupUi(this);
    ui->ancho->setText("1024");
    ui->alto->setText("768");
    ui->framerate->setText("20");
    connect(ui->actionSalir, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(ui->actionGuardar, SIGNAL(triggered()), this, SLOT(on_namevideo_selectionChanged()));
    connect(ui->actionManual,SIGNAL(triggered()), this, SLOT(abrirManual()));
    connect(ui->actionManual_Online,SIGNAL(triggered()), this, SLOT(abrirManualonline()));
    connect(ui->actionAcerca_de,SIGNAL(triggered()), this, SLOT(acercade()));
    connect(ui->actionLicencia, SIGNAL(triggered()), this,SLOT(lic()));
    QString fileName;
    ui->namevideo->setText(fileName);
}


recvideo::~recvideo()
{
    delete ui;
}

void recvideo::on_pushButton_clicked()
{

    QString uno = "ffmpeg -r ";
    QString dos = " -s ";
    QString tres = " -f x11grab -i :0.0 -vcodec msmpeg4v2 -qscale 1 ";
    QString fin = " &";
    QString nombre = ui->namevideo->text();
    QString framerate = ui->framerate->text();
    QString ancho = ui->ancho->text();
    QString alto = ui->alto->text();
    QString equis = "x";
    QString orden = uno+framerate+dos+ancho+equis+alto+tres+nombre+fin;
    std::string str = std::string(orden.toAscii().data());
    const char * comando = str.c_str();
    system(comando);
    QWidget::setWindowState(Qt::WindowMinimized);
}

void recvideo::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Esta saliendo para continuar puse OK");
    msgBox.exec();
    system("pkill -9 ffmpeg");
    close();
}


void recvideo::on_namevideo_selectionChanged()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Seleccione ubicación y nombre Para guardar el vídeo"), ".avi",
        tr("Ví­deo File (*.avi);;All Files (*. *.h)"));
    ui->namevideo->setText(fileName);
}


void recvideo::on_namevideo_returnPressed()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), ".avi",
        tr("Ví­deo File (*.avi);;All Files (*. *.h)"));

    ui->namevideo->setText(fileName);
}

void recvideo::abrirManual(){
    QMessageBox::information(this, "Abriendo Manual","A continuación se abrira el menual de screencastglud");
    QUrl manual("../screencastglud/doc/manual.pdf"); /* filee path not open */
    QDesktopServices::openUrl (manual);
}

void recvideo::abrirManualonline(){
    QMessageBox::information(this, "Abriendo Manual Online","Proximamente el manual on line de screencastglud, Primero visita nuestra pagina del GLUD");
    QUrl manual("http://glud.udistrital.edu.co"); /* filee path not open */
    QDesktopServices::openUrl (manual);
}

void recvideo::acercade(){
    QMessageBox::information(this, "Abriendo Manual","Desarrollado por:\n\n \t Fernando Pineda\n \t GLUD \n\n Grupo GNU/Linux Universidad Distrital");
}

void recvideo::lic(){
    QMessageBox::information(this, "Abriendo Manual","DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE\n \tVersion 2, December 2004\nCopyright (C) 2004 Sam Hocevar <sam@hocevar.net> \nEveryone is permitted to copy and distribute verbatim or modified\ncopies of this license document, and changing it is allowed as long\nas the name is changed.\n \n          DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE \nTERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION \n \n 0. You just DO WHAT THE FUCK YOU WANT TO.");
}
