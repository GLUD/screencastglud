#include "recvideo.h"
#include "ui_recvideo.h"
#include "string.h"
#include "QMessageBox"
#include "QFileDialog"

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
    QString fileName = QFileDialog::getSaveFileName(this, tr("Asigne ubicación y nombre Para guardar el vídeo"), ".avi",
        tr("Ví­deo File (*.avi);;All Files (*. *.h)"));

    ui->namevideo->setText(fileName);
}


void recvideo::on_namevideo_returnPressed()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), ".avi",
        tr("Ví­deo File (*.avi);;All Files (*. *.h)"));

    ui->namevideo->setText(fileName);
}
