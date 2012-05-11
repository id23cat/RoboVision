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

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdlib.h>
#include <stdio.h>

void FindRedPoint(IplImage *img, int *Max, CvPoint *maxPoint);
void VideoRed(int argc, char* argv[]);
void ImageRed(int argc, char* argv[]);
void drawTarget(IplImage* img, CvPoint pt, int radius);
void BRIGHTNESSCallback(int pos);
void CONTRASTCallback(int pos);
void SATURATIONCallback(int pos);
void MINTthresholdCallback(int pos);

CvCapture* capture;
int MIN;

int main(int argc, char* argv[])
{
	// имя картинки задаётся первым параметром
//	ImageRed(argc, argv);
	VideoRed(argc, argv);

	return 0;
}

void VideoRed(int argc, char* argv[]){
    // получаем любую подключённую камеру
	if(argc>1)
		capture = cvCreateCameraCapture(atoi(argv[1])); //cvCaptureFromCAM( 0 );
	else
		capture = cvCreateCameraCapture(CV_CAP_ANY); //cvCaptureFromCAM( 0 );
    assert( capture );

    //cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 640);//1280);
    //cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 480);//960);

    // узнаем ширину и высоту кадра
    double width = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
    double height = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
    printf("[i] %.0f x %.0f\n", width, height );

    IplImage* frame=0;
    IplImage* modified=0;

    cvNamedWindow("capture", CV_WINDOW_AUTOSIZE);
//        cvNamedWindow("GAUSSIAN", CV_WINDOW_AUTOSIZE);
//        cvNamedWindow("BILATERAL", CV_WINDOW_AUTOSIZE);

    // показываем ползунок
    int BRposition = 0;
    int CTposition = 0;
    int SNposition = 100;
    int MINt = 90;
    MIN = MINt;
    cvCreateTrackbar("BRIGHTNESS", "capture", &BRposition, 100, BRIGHTNESSCallback);
    cvCreateTrackbar("CONTRAST", "capture", &CTposition, 100, CONTRASTCallback);
    cvCreateTrackbar("SATURATION", "capture", &SNposition, 100, SATURATIONCallback);
    cvCreateTrackbar("Thrashold", "capture", &MINt, 200, MINTthresholdCallback);

    // устанавливаем настройки видео по-умолчанию
	cvSetCaptureProperty(capture, CV_CAP_PROP_BRIGHTNESS, BRposition/100);
	cvSetCaptureProperty(capture, CV_CAP_PROP_CONTRAST, CTposition/100);
	cvSetCaptureProperty(capture, CV_CAP_PROP_SATURATION, SNposition/100);

    printf("[i] press Enter for capture image and Esc for quit!\n\n");

    int counter=0;
    char filename[512];
    int max;
    CvPoint maxP;

    while (true) {
		// получаем кадр
		frame = cvQueryFrame(capture);
		counter++;
		if (counter == 1) {
			//		modified = cvCloneImage(frame);

			//                cvSmooth(frame, modified, CV_GAUSSIAN, 3,3,15,15);
			//                cvShowImage("GAUSSIAN", modified);
			//                cvSmooth(frame, modified, CV_BILATERAL, 3,3,30,30);
			//                cvShowImage("BILATERAL", modified);

			FindRedPoint(frame, &max, &maxP);
			printf("MaxV = %d\n", max);
			counter=0;
		}

		if(max > MIN)
			drawTarget(frame, maxP, 8);
		cvShowImage("capture", frame);

		// показываем


		char c = cvWaitKey(33);
		if (c == 27) { // нажата ESC
			break;
		} else if (c == 13) { // Enter
			// сохраняем кадр в файл
			sprintf(filename, "Image%d.jpg", counter);
			printf("[i] capture... %s\n", filename);
			cvSaveImage(filename, frame);
			counter++;
		}
		cvReleaseImage(&modified);
	}
	// освобождаем ресурсы
	cvReleaseCapture(&capture);
	cvDestroyWindow("capture");
	//        cvDestroyWindow("GAUSSIAN");
	//        cvDestroyWindow("BILATERAL");
}

void ImageRed(int argc, char* argv[]){
	// имя картинки задаётся первым параметром
	const char* filename = argc == 2 ? argv[1] : "RedPoint1.jpg";
	// получаем картинку
	IplImage *image = cvLoadImage(filename, 1);
	// клонируем картинку
//	IplImage *src = cvCloneImage(image);

	printf("[i] image: %s\n", filename);
//	assert( src != 0 );

	// окно для отображения картинки
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);


	int max;
	CvPoint maxP;
	FindRedPoint(image, &max, &maxP);
	drawTarget(image, maxP, 8);

	cvShowImage( "original", image );

	// ждём нажатия клавиши
	cvWaitKey(0);


	cvReleaseImage(&image);
//	cvReleaseImage(&src);
	cvDestroyWindow("original");
}

// рисуем целеуказатель
void drawTarget(IplImage* img, CvPoint pt, int radius)
{
        cvCircle(img,cvPoint(pt.x, pt.y),radius,CV_RGB(250,0,0),1,8);
        cvLine(img, cvPoint(pt.x-radius/2, pt.y-radius/2), cvPoint(pt.x+radius/2, pt.y+radius/2),CV_RGB(250,0,0),1,8);
        cvLine(img, cvPoint(pt.x-radius/2, pt.y+radius/2), cvPoint(pt.x+radius/2, pt.y-radius/2),CV_RGB(250,0,0),1,8);
}

#define IDX(i,j,obj) (i*obj->widthStep + j*obj->nChannels)
#define RED(idx) idx+2
#define GRN(idx) idx+1
#define BLU(idx) idx+0

void FindRedPoint(IplImage *img, int *Max, CvPoint *maxPoint){
	int maxV=-255;
	CvPoint maxP;
	int val=0;

	for (int i = 0; i < img->height; i++) {
		for (int j = 0; j < img->width; j++) {
			unsigned char r = img->imageData[RED(IDX(i,j,img))];
			unsigned char g = img->imageData[GRN(IDX(i,j,img))];
			unsigned char b = img->imageData[BLU(IDX(i,j,img))];

			val = r - g - b;

			if (val > maxV) {
				maxV = val;
				maxP.y = i;
				maxP.x = j;
			}
		}
	}
	*Max = maxV;
	*maxPoint = maxP;
}

// функция-обработчик ползунка -
void BRIGHTNESSCallback(int pos) {
	double val = (double)pos/100.f;
	printf("BRIGHTNESS = %f\n", val);
	cvSetCaptureProperty(capture, CV_CAP_PROP_BRIGHTNESS, val);
}

void CONTRASTCallback(int pos) {
	double val = (double)pos/100.f;
	printf("CONTRAST = %f\n", val);
	cvSetCaptureProperty(capture, CV_CAP_PROP_CONTRAST, val);
}

void SATURATIONCallback(int pos) {
	double val = (double)pos/100.f;
	printf("SATURATION = %f\n", val);
	cvSetCaptureProperty(capture, CV_CAP_PROP_SATURATION, val);
}

void MINTthresholdCallback(int pos) {
	MIN = pos;
}
