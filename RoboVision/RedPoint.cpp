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


#define WINNAME (char*)"capture"
#define HSVWIN (char*)"hsvwin"

void BRIGHTNESSCallback(int pos);
void CONTRASTCallback(int pos);
void SATURATIONCallback(int pos);
void MINTthresholdCallback(int pos);

CvCapture* capture;
int MIN;


void OpenWindow(){
    cvNamedWindow(WINNAME, CV_WINDOW_AUTOSIZE);
    cvNamedWindow(HSVWIN, CV_WINDOW_AUTOSIZE);
    cvMoveWindow(HSVWIN, 500, 0);
//        cvNamedWindow("GAUSSIAN", CV_WINDOW_AUTOSIZE);
//        cvNamedWindow("BILATERAL", CV_WINDOW_AUTOSIZE);

//    // показываем ползунок
//    int BRposition = 0;
//    int CTposition = 0;
//    int SNposition = 100;
//    int MINt = 90;
//    MIN = MINt;
//    cvCreateTrackbar("BRIGHTNESS", WINNAME, &BRposition, 100, BRIGHTNESSCallback);
//    cvCreateTrackbar("CONTRAST", WINNAME, &CTposition, 100, CONTRASTCallback);
//    cvCreateTrackbar("SATURATION", WINNAME, &SNposition, 100, SATURATIONCallback);
//    cvCreateTrackbar("Thrashold", WINNAME, &MINt, 200, MINTthresholdCallback);
//
//    // устанавливаем настройки видео по-умолчанию
//	cvSetCaptureProperty(capture, CV_CAP_PROP_BRIGHTNESS, BRposition/100);
//	cvSetCaptureProperty(capture, CV_CAP_PROP_CONTRAST, CTposition/100);
//	cvSetCaptureProperty(capture, CV_CAP_PROP_SATURATION, SNposition/100);

}

void ToWindow(IplImage* frame, char *name=WINNAME){
	cvShowImage(name, frame);
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
	RedPoint redPoint(width, height);
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


//		fprintf(stderr, "Start process\n");


//		ProcessImage(frame, frame);
		redPoint.ProcessImage(frame);


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


	int max;
	CvPoint maxP;
	FindRedPoint(inimg, &max, &maxP);
//	if(max > MIN)
		drawTarget(outimg, maxP, 8);

	//outimg = (void*)outframe->imageData;

	return 0;
}

void FindRedPointRGB(IplImage *img, int *Max, CvPoint *maxPoint){
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

void FindRedPointHSV(IplImage *img, int *Max, CvPoint *maxPoint){
	CvSize size = cvGetSize(img);
	IplImage *hsv = cvCreateImage(size, IPL_DEPTH_8U, 3);
	IplImage *h_plane = cvCreateImage(size, IPL_DEPTH_8U, 1);
	IplImage *s_plane = cvCreateImage(size, IPL_DEPTH_8U, 1);
	IplImage *v_plane = cvCreateImage(size, IPL_DEPTH_8U, 1);
	IplImage *hsv_and = cvCreateImage( size, IPL_DEPTH_8U, 1 );

	//  конвертируем в HSV
	cvCvtColor(img, hsv, CV_BGR2HSV);
	cvCvtPixToPlane(hsv, h_plane, s_plane, v_plane, 0);

	cvInRangeS(h_plane, cvScalar(Hmin), cvScalar(Hmax), h_plane);
	cvInRangeS(s_plane, cvScalar(Smin), cvScalar(Smax), s_plane);
	cvInRangeS(v_plane, cvScalar(Vmin), cvScalar(Vmax), v_plane);

	// складываем
	cvAnd(h_plane, s_plane, hsv_and);
	cvAnd(hsv_and, v_plane, hsv_and);
	ToWindow(hsv_and, HSVWIN);
	double min;
	double max;
	CvPoint pMin;
	CvPoint pMax;

	cvMinMaxLoc(hsv_and, &min, &max, &pMin, &pMax);
	cvReleaseImage(&hsv);
	cvReleaseImage(&h_plane);
	cvReleaseImage(&s_plane);
	cvReleaseImage(&v_plane);
	cvReleaseImage(&hsv_and);
	*Max = max;
	*maxPoint = pMax;
//	return pMax;
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


RedPoint::~RedPoint(){
	cvReleaseImage(&img3ch);
	cvReleaseImage(&chnl1);
	cvReleaseImage(&chnl2);
	cvReleaseImage(&chnl3);
	cvReleaseImage(&chnl_and);
}

RedPoint::RedPoint(int width, int height){
	size = cvSize(width, height);
	img3ch = cvCreateImage( size, IPL_DEPTH_8U, 3 );
	chnl1 = cvCreateImage( size, IPL_DEPTH_8U, 1 );
	chnl2 = cvCreateImage( size, IPL_DEPTH_8U, 1 );
	chnl3 = cvCreateImage( size, IPL_DEPTH_8U, 1 );
	chnl_and = cvCreateImage( size, IPL_DEPTH_8U, 1 );
}

CvPoint RedPoint::ProcessImage(IplImage *src, IplImage *dst){
	CvPoint pMax;
	if(!dst){
		cvCopy(src, img3ch);
		pMax = FindRedPoint(img3ch);
		drawTarget(src, pMax, 8);

	}else{
		cvCopy(src, dst);
		pMax = FindRedPoint(dst);
		drawTarget(dst, pMax, 8);
	}

	return pMax;

}

CvPoint RedPoint::FindRedPointHSV(IplImage *img){
	IplImage* hsv = img;
	IplImage* h_plane = chnl1;
	IplImage* s_plane = chnl2;//		cvAdaptiveThreshold(h_plane, h_range, Hmax,
	//				CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_TOZERO_INV);
	//		cvAdaptiveThreshold(h_range, h_range, Hmin,
	//				CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_TOZERO);
	//
	//		cvAdaptiveThreshold(s_plane, s_range, Smax,
	//				CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_TOZERO_INV);
	//		cvAdaptiveThreshold(s_range, s_range, Smin,
	//				CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_TOZERO);
	//				//		cvAdaptiveThreshold(h_plane, h_range, Hmax,
	//				CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_TOZERO_INV);
	//		cvAdaptiveThreshold(h_range, h_range, Hmin,
	//				CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_TOZERO);
	//
	//		cvAdaptiveThreshold(s_plane, s_range, Smax,
	//				CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_TOZERO_INV);
	//		cvAdaptiveThreshold(s_range, s_range, Smin,
	//				CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_TOZERO);
	//
	//		cvAdaptiveThreshold(v_plane, v_range, Vmax,
	//				CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_TOZERO_INV);
	//		cvAdaptiveThreshold(v_range, v_range, Vmin,
	//				CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_TOZERO);
	//		cvAdaptiveThreshold(v_plane, v_range, Vmax,
	//				CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_TOZERO_INV);
	//		cvAdaptiveThreshold(v_range, v_range, Vmin,
	//				CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_TOZERO);wwwwww
	IplImage* v_plane = chnl3;
	//  конвертируем в HSV
	cvCvtColor( img, hsv, CV_BGR2HSV );
	cvCvtPixToPlane( hsv, h_plane, s_plane, v_plane, 0 );

	cvInRangeS(h_plane, cvScalar(Hmin), cvScalar(Hmax), h_plane);
	cvInRangeS(s_plane, cvScalar(Smin), cvScalar(Smax), s_plane);
	cvInRangeS(v_plane, cvScalar(Vmin), cvScalar(Vmax), v_plane);

	// складываем
	cvAnd(h_plane, s_plane, chnl_and);
	cvAnd(chnl_and, v_plane, chnl_and);
	double min;
	double max;
	CvPoint pMin;
	CvPoint pMax;

	cvMinMaxLoc(chnl_and,&min, &max, &pMin, &pMax);
	return pMax;
}
