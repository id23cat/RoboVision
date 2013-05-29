#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qimagegrabbermjpeg.h"

#include <QKeyEvent>

#include <opencv2/imgproc/imgproc.hpp>
#include <ctype.h>

#include <RedPoint.h>
#include <QDebug>

#define MAX_COUNT 200

/*************************************
 Thanks to umanga:
 http://umanga.wordpress.com/2010/04/19/how-to-covert-qt-qimage-into-opencv-iplimage-and-wise-versa/
 ************************************/
IplImage* QImage2IplImage(QImage *qimg)
{

    IplImage *imgHeader = cvCreateImageHeader( cvSize(qimg->width(), qimg->height()), IPL_DEPTH_8U, 4);
    imgHeader->imageData = (char*) qimg->bits();

//    uchar* newdata = (uchar*) malloc(sizeof(uchar) * qimg->byteCount());
//    memcpy(newdata, qimg->bits(), qimg->byteCount());
//    imgHeader->imageData = (char*) newdata;
    //cvClo
    return imgHeader;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    subPixWinSize(10,10),
    winSize(31,31),
    termcrit(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS,20,0.03)
{
    ui->setupUi(this);

    setFocusPolicy(Qt::StrongFocus);

    StartGrabber();

    needToInit = true;

//    robot = new Networker(ui->IPline->text(), ui->Portline->text().toInt());
    robot = new Networker(ui->IPline->text(), ui->Portline->text().toUInt());
}


void MainWindow::StartGrabber()
{
    grabber = new QImageGrabberMjpeg(this);
    QUrl url("http://192.168.1.2:8080/?action=stream");
//    grabber->
    grabber->setUrl(url);
    grabber->startGrabbing();
    connect(grabber, SIGNAL(newImageGrabbed(QImage*)), this, SLOT(showOriginal(QImage*)));
}

void MainWindow::showOriginal(QImage *img)
{
    QImage improc = img->copy();
    qDebug() <<"src img:" << img->bits();
    qDebug() <<"dst img:" << improc.bits();
    ProcessImage(QImage2IplImage(&improc), QImage2IplImage(&improc));

    ui->label->setPixmap( QPixmap::fromImage(*img) );
    ui->label->show();

    ui->labelProccess->setPixmap( QPixmap::fromImage(improc) );
    ui->labelProccess->show();

    update();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete grabber;
}



void MainWindow::on_ReconnectBtn_clicked()
{
    robot->Reconnect(ui->IPline->text(), ui->Portline->text().toInt());
    disconnect(grabber);
    delete grabber;
    StartGrabber();
}

void MainWindow::on_toolButtonUp_clicked()
{
    qDebug() << "UP KEY";
    robot->Write(MW_FORWARD);
}

void MainWindow::on_toolButtonLeft_clicked()
{
    qDebug() << "LEFT KEY";
    robot->Write(RT_LEFT);
}

void MainWindow::on_toolButtonDown_clicked()
{
    qDebug() << "DOWN KEY";
    robot->Write(MW_BACKWARD);
}

void MainWindow::on_toolButtonRight_clicked()
{
    qDebug() << "RIGHT KEY";
    robot->Write(RT_RIGHT);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Up:
        on_toolButtonUp_clicked();
        break;
    case Qt::Key_Down:
        on_toolButtonDown_clicked();
        break;
    case Qt::Key_Left:
        on_toolButtonLeft_clicked();
        break;
    case Qt::Key_Right:
        on_toolButtonRight_clicked();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

void MainWindow::on_toolButtonSend_clicked()
{
    robot->Write( ui->commandLine->displayText() );
    ui->commandLine->clear();
}

void MainWindow::on_commandLine_returnPressed()
{
    robot->Write( ui->commandLine->displayText() );
    ui->commandLine->clear();
}

//IplImage* MainWindow::QImage2IplImage(QImage *qimg)
//{

//    IplImage *imgHeader = cvCreateImageHeader( cvSize(qimg->width(), qimg->height()), IPL_DEPTH_8U, 4);
//    imgHeader->imageData = (char*) qimg->bits();

////    uchar* newdata = (uchar*) malloc(sizeof(uchar) * qimg->byteCount());
////    memcpy(newdata, qimg->bits(), qimg->byteCount());
////    imgHeader->imageData = (char*) newdata;
//    //cvClo
//    return imgHeader;
//}

//QImage*  MainWindow::IplImage2QImage(IplImage *iplImg)
//{
//    int h = iplImg->height;
//    int w = iplImg->width;
//    int channels = iplImg->nChannels;
//    QImage *qimg = new QImage(w, h, QImage::Format_ARGB32);
//    char *data = iplImg->imageData;

//    for (int y = 0; y < h; y++, data += iplImg->widthStep)
//    {
//        for (int x = 0; x < w; x++)
//        {
//            char r, g, b, a = 0;
//            if (channels == 1)
//            {
//                r = data[x * channels];
//                g = data[x * channels];
//                b = data[x * channels];
//            }
//            else if (channels == 3 || channels == 4)
//            {
//                r = data[x * channels + 2];
//                g = data[x * channels + 1];
//                b = data[x * channels];
//            }

//            if (channels == 4)
//            {
//                a = data[x * channels + 3];
//                qimg->setPixel(x, y, qRgba(r, g, b, a));
//            }
//            else
//            {
//                qimg->setPixel(x, y, qRgb(r, g, b));
//            }
//        }
//    }
//    return qimg;

//}




