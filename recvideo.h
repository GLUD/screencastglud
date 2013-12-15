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
    
public slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_namevideo_selectionChanged();

    void on_namevideo_returnPressed();

private:
    Ui::recvideo *ui;
};

#endif // RECVIDEO_H
