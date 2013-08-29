#ifndef RECVIDEO_H
#define RECVIDEO_H

#include <QMainWindow>

namespace Ui {
class recvideo;
}

class recvideo : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit recvideo(QWidget *parent = 0);
    ~recvideo();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::recvideo *ui;
};

#endif // RECVIDEO_H
