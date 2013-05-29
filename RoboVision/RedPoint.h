/*
 * RedPoint.h
 *
 *  Created on: 06.06.2012
 *      Author: id23cat
 */

#ifndef REDPOINT_H_
#define REDPOINT_H_
#include <opencv/cv.h>


//#define FindRedPoint FindRedPointRGB
#define FindRedPoint FindRedPointHSV

#define Hmin 0
#define Hmax 10

#define Smin 224
#define Smax 256

#define Vmin 56
#define Vmax 256

int ProcessImage(IplImage *inimg, IplImage *outimg);

void FindRedPoint(IplImage *img, int *Max, CvPoint *maxPoint);
void VideoRed(int argc, char* argv[]);
void ImageRed(int argc, char* argv[]);
void drawTarget(IplImage* img, CvPoint pt, int radius);

class RedPoint{
//	CvCapture* capture;
	int MIN;
	CvSize size;
	IplImage* img3ch;
	IplImage* chnl1;
	IplImage* chnl2;
	IplImage* chnl3;
	IplImage* chnl_and;

public:
//	RedPoint();
	RedPoint(int width, int height);
	~RedPoint();
	CvPoint ProcessImage(IplImage *src, IplImage *dst=NULL);

	CvPoint FindRedPoint(IplImage *img);
};

#endif /* REDPOINT_H_ */
