//#include "opencv/cv.h"
//#include "opencv/highgui.h"
//#include <iostream>


//#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include "RedPoint.h"

//void FindRedPoint(IplImage *img, int *Max, CvPoint *maxPoint);
//void VideoRed(int argc, char* argv[]);
//void ImageRed(int argc, char* argv[]);
//void drawTarget(IplImage* img, CvPoint pt, int radius);
//void BRIGHTNESSCallback(int pos);
//void CONTRASTCallback(int pos);
//void SATURATIONCallback(int pos);
//void MINTthresholdCallback(int pos);
//int ProcessImage(void *inimg, int width, int height, void *outimg);

void BRIGHTNESSCallback(int pos);
void CONTRASTCallback(int pos);
void SATURATIONCallback(int pos);
void MINTthresholdCallback(int pos);

CvCapture* capture;
int MIN;

#define WINNAME "capture"

void OpenWindow(){
    cvNamedWindow(WINNAME, CV_WINDOW_AUTOSIZE);
//        cvNamedWindow("GAUSSIAN", CV_WINDOW_AUTOSIZE);
//        cvNamedWindow("BILATERAL", CV_WINDOW_AUTOSIZE);

    // показываем ползунок
    int BRposition = 0;
    int CTposition = 0;
    int SNposition = 100;
    int MINt = 90;
    MIN = MINt;
    cvCreateTrackbar("BRIGHTNESS", WINNAME, &BRposition, 100, BRIGHTNESSCallback);
    cvCreateTrackbar("CONTRAST", WINNAME, &CTposition, 100, CONTRASTCallback);
    cvCreateTrackbar("SATURATION", WINNAME, &SNposition, 100, SATURATIONCallback);
    cvCreateTrackbar("Thrashold", WINNAME, &MINt, 200, MINTthresholdCallback);

    // устанавливаем настройки видео по-умолчанию
	cvSetCaptureProperty(capture, CV_CAP_PROP_BRIGHTNESS, BRposition/100);
	cvSetCaptureProperty(capture, CV_CAP_PROP_CONTRAST, CTposition/100);
	cvSetCaptureProperty(capture, CV_CAP_PROP_SATURATION, SNposition/100);

}

void ToWindow(IplImage* frame){
	cvShowImage(WINNAME, frame);
}

void CloseWindow(){
	cvDestroyWindow(WINNAME);
}


void VideoRed(int argc, char* argv[]){
    // получаем любую подключённую камеру
	if(argc>1)
		if(argv[1][0]== 'n')
			capture = cvCreateFileCapture("http://192.168.1.2:8080/?action=stream");
		else
			capture = cvCreateCameraCapture(atoi(argv[1])); //cvCaptureFromCAM( 0 );
	else
		capture = cvCreateCameraCapture(CV_CAP_ANY); //cvCaptureFromCAM( 0 );
    assert( capture );
    if (capture == NULL)
		printf("camera is null\n");
	else
		printf("camera is not null");


    //cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 640);//1280);
    //cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 480);//960);

    // узнаем ширину и высоту кадра
    double width = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
    double height = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
    printf("[i] %.0f x %.0f\n", width, height );

    IplImage* frame=0;
    //IplImage* modified=0;


    printf("[i] press Enter for capture image and Esc for quit!\n\n");

    int counter=0;
    char filename[512];
//    int max;
//    CvPoint maxP;

	OpenWindow();
//	fprintf(stderr, "cvCreateImageHeader(%d,%d)\n");
//	IplImage *outframe = cvCreateImageHeader(cvSize(width, height), IPL_DEPTH_8U, 3);
    while (true) {
		// получаем кадр
		frame = cvQueryFrame(capture);
		counter++;
//		if (counter == 1) {
			//		modified = cvCloneImage(frame);

			//                cvSmooth(frame, modified, CV_GAUSSIAN, 3,3,15,15);
			//                cvShowImage("GAUSSIAN", modified);
			//                cvSmooth(frame, modified, CV_BILATERAL, 3,3,30,30);
			//                cvShowImage("BILATERAL", modified);

//			FindRedPoint(frame, &max, &maxP);
//			printf("MaxV = %d\n", max);
//			switch(frame->depth){
//			case IPL_DEPTH_8S:
//				printf("depth = IPL_DEPTH_8S\n");
//				break;
//			case IPL_DEPTH_16S:
//				printf("depth = IPL_DEPTH_16S\n");
//				break;
//			case IPL_DEPTH_32S:
//				printf("depth = IPL_DEPTH_32S\n");
//				break;
//			case IPL_DEPTH_1U:
//				printf("depth = IPL_DEPTH_1U\n");
//				break;
//			case IPL_DEPTH_8U:
//				printf("depth = IPL_DEPTH_8U\n");
//				break;
//			case IPL_DEPTH_16U:
//				printf("depth = IPL_DEPTH_16U\n");
//				break;
//			case IPL_DEPTH_32F:
//				printf("depth = IPL_DEPTH_32F\n");
//				break;
//			}
//			printf("chanels = %d\n", frame->nChannels);
//
//			counter=0;
//		}
//
//		if(max > MIN)
//			drawTarget(frame, maxP, 8);


		fprintf(stderr, "Start process\n");
		ProcessImage(frame, frame);


		// показываем			
		ToWindow(frame);


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

//		free(outframe->imageData);
//		cvReleaseImage(&frame);
	}
	// освобождаем ресурсы
    cvReleaseImage(&frame);
	cvReleaseCapture(&capture);
	CloseWindow();
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

int ProcessImage(IplImage *inimg, IplImage *outimg){

//	CvMat mat;
//	mat.height = height;
//	mat.width = width;
//	mat.step = width;
//	mat.data.ptr = (uchar*) inimg;

//	IplImage *frame = cvCreateImageHeader(cvSize(width,height), IPL_DEPTH_8U, 3);
//	IplImage *outframe = cvCreateImageHeader(cvSize(width,height), IPL_DEPTH_8U, 3);
////	frame = cvGetImage(&mat, frame);
//
////	IplImage *outframe = cvCloneImage(frame);
//	cvSetImageData(frame, inimg, width);
//	cvSetImageData(outframe, outimg, width);
//	cvCopy(frame, outframe);
	int max;
	CvPoint maxP;
	FindRedPoint(inimg, &max, &maxP);
	if(max > MIN)
		drawTarget(outimg, maxP, 8);

	//outimg = (void*)outframe->imageData;

	return 0;
}

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
