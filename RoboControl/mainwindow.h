#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/video/tracking.hpp>
#include "networker.h"
#include <opencv/cv.h>

#define MW_FORWARD "q"
#define MW_BACKWARD "w"
#define RT_LEFT "e"
#define RT_RIGHT "r"

//#define FORWARD "MF1M"
//#define BACKWARD "ST1S"
//#define ROTATE_LEFT "RL1R"
//#define ROTATE_RIGHT "RR1R"

namespace Ui {
    class MainWindow;
}

class QImageGrabberMjpeg;
class QKeyEvent;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void showOriginal(QImage * img);

    void on_toolButtonUp_clicked();

    void on_ReconnectBtn_clicked();

    void on_toolButtonLeft_clicked();

    void on_toolButtonDown_clicked();

    void on_toolButtonRight_clicked();

    void on_toolButtonSend_clicked();

    void on_commandLine_returnPressed();

private:
    Ui::MainWindow *ui;
    QImageGrabberMjpeg *grabber;
    cv::Mat gray;
    cv::Mat prevGray;
    cv::Mat image;
    cv::vector<cv::Point2f> points[2];
    bool needToInit;
    bool nightMode;
    bool addRemovePt;
    cv::Size subPixWinSize;
    cv::Size winSize;
    cv::TermCriteria termcrit;
    cv::Point2f pt;

    Networker *robot;
protected:
    void keyPressEvent(QKeyEvent *event);
    void StartGrabber();
//    IplImage* QImage2IplImage(QImage *qimg);
//    QImage* IplImage2QImage(IplImage *iplImg);
};

#endif // MAINWINDOW_H
