#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qimagegrabbermjpeg.h"

#include <QKeyEvent>


#include <opencv2/imgproc/imgproc.hpp>
#include <ctype.h>

#define MAX_COUNT 200

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    subPixWinSize(10,10),
    winSize(31,31),
    termcrit(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS,20,0.03)
{
    ui->setupUi(this);

    setFocusPolicy(Qt::StrongFocus);

    grabber = new QImageGrabberMjpeg(this);
    QUrl url("http://192.168.1.2:8080/?action=stream");
    grabber->setUrl(url);
    grabber->startGrabbing();
    connect(grabber, SIGNAL(newImageGrabbed(QImage*)), this, SLOT(showOriginal(QImage*)));

    needToInit = true;

//    robot = new Networker(ui->IPline->text(), ui->Portline->text().toInt());
    robot = new Networker();
}

void MainWindow::showOriginal(QImage *img)
{
    ui->label->setPixmap( QPixmap::fromImage(*img) );
    ui->label->show();

    ui->labelProccess->setPixmap( QPixmap::fromImage(*img) );
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
}

void MainWindow::on_toolButtonUp_clicked()
{
    robot->Write("MF1M");
}

void MainWindow::on_toolButtonLeft_clicked()
{
    robot->Write("RL1R");
}

void MainWindow::on_toolButtonDown_clicked()
{
    robot->Write("ST1S");
}

void MainWindow::on_toolButtonRight_clicked()
{
    robot->Write("RR1R");
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Up:
        robot->Write("MF1M");
        break;
    case Qt::Key_Down:
        robot->Write("ST1S");
        break;
    case Qt::Key_Left:
        robot->Write("RL1R");
        break;
    case Qt::Key_Right:
        robot->Write("RR1R");
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}
