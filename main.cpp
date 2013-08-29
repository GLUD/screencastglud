#include <QApplication>
#include "recvideo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    recvideo w;
    w.show();
    
    return a.exec();
}
