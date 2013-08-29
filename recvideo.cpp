#include "recvideo.h"
#include "ui_recvideo.h"
#include "string.h"
#include "QMessageBox"

recvideo::recvideo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::recvideo)
{
    ui->setupUi(this);
    ui->ancho->setText("1024");
    ui->alto->setText("768");
    ui->framerate->setText("20");
    ui->namevideo->setText("video.avi");
}

recvideo::~recvideo()
{
    delete ui;
}

void recvideo::on_pushButton_clicked()
{
    QString uno = "ffmpeg -r ";
    QString dos = " -s ";
    QString tres = " -f x11grab -i :0.0 -vcodec msmpeg4v2 -qscale 1 /home/$USER/Vídeos/";
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
    close();
}
