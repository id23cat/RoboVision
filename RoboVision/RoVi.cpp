//#include "opencv/cv.h"
//#include "opencv/highgui.h"
//#include <iostream>
//
////int main(){
////
////    CvCapture *camera=cvCaptureFromFile("http://192.168.1.2:8080/?action=stream");
////    if (camera==NULL)
////        printf("camera is null\n");
////    else
////        printf("camera is not null\n");
////
////    cvNamedWindow("img");
////    while (cvWaitKey(10)!=atoi("q")){
////        double t1=(double)cvGetTickCount();
////        IplImage *img=cvQueryFrame(camera);
////        double t2=(double)cvGetTickCount();
////        printf("time: %gms  fps: %.2g,  %d x %d\n",(t2-t1)/(cvGetTickFrequency()*1000.), 1000./((t2-t1)/(cvGetTickFrequency()*1000.)),
////        		img->height, img->width);
////        cvShowImage("img",img);
////    }
////    cvReleaseCapture(&camera);
////}
//
//
//int main(int argc, char** argv) {
//    cv::VideoCapture vcap(argv[1]);
//    if(!vcap.isOpened()){
//    	 std::cout << "Error opening video stream or file" << std::endl;
//    	 return -1;
//    }
//    cv::Mat image;
//
////    const std::string videoStreamAddress = "http://192.168.1.2:8080/?action=stream";
//    //Yes, this stream does work! Try to paste it into your browser...
//
//    //open the video stream and make sure it's opened
//    if(!vcap.open(videoStreamAddress)) {
//        std::cout << "Error opening video stream or file" << std::endl;
//        return -1;
//    }
//
//    for(;;) {
//        if(!vcap.read(image)) {
//            std::cout << "No frame" << std::endl;
//            cv::waitKey();
//        }
//        cv::imshow("Output Window", image);
//        if(cv::waitKey(1) >= 0) break;
//    }
//}

/*
 * RoVi.cpp
 *
 *  Created on: 25.04.2012
 *      Author: id23cat
 */

//#include <opencv/cv.h>
//#include <opencv/highgui.h>
//
//using namespace cv;
//int main(int argc, char** argv) {
//	Mat image;
//	image = imread(argv[1], 1);
//	if (argc != 2 || !image.data) {
//		printf("No image data \n");
//		return -1;
//	}
//	namedWindow("Display Image", CV_WINDOW_AUTOSIZE);
//	imshow("Display Image", image);
//	waitKey(0);
//	return 0;
//}



//#include <opencv/cv.h>
//#include <opencv/highgui.h>
//
//int main( int argc, char** argv )
//{
//        // задаём высоту и ширину картинки
//        int height = 620;
//        int width = 440;
//        // задаём точку для вывода текста
//        CvPoint pt = cvPoint( height/4, width/2 );
//        // Создаёи 8-битную, 3-канальную картинку
//        IplImage* hw = cvCreateImage(cvSize(height, width), 8, 3);
//        // заливаем картинку чёрным цветом
//        cvSet(hw,cvScalar(0,0,0));
//        // инициализация шрифта
//        CvFont font;
//        cvInitFont( &font, CV_FONT_HERSHEY_COMPLEX,1.0, 1.0, 0, 1, CV_AA);
//        // используя шрифт выводим на картинку текст
//        cvPutText(hw, "OpenCV Step By Step", pt, &font, CV_RGB(150, 0, 150) );
//
//        // создаём окошко
//        cvNamedWindow("Hello World", 0);
//        // показываем картинку в созданном окне
//        cvShowImage("Hello World", hw);
//        // ждём нажатия клавиши
//        cvWaitKey(0);
//
//        // освобождаем ресурсы
//        cvReleaseImage(&hw);
//        cvDestroyWindow("Hello World");
//        return 0;
//}

//#include <opencv/cv.h>
//#include <opencv/highgui.h>
//#include <stdlib.h>
//#include <stdio.h>
#include "RedPoint.h"



//CvCapture* capture;
//int MIN;

int main(int argc, char* argv[])
{
	// имя картинки задаётся первым параметром
//	ImageRed(argc, argv);
	VideoRed(argc, argv);

	return 0;
}
