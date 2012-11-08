/*
 * RedPoint.h
 *
 *  Created on: 06.06.2012
 *      Author: id23cat
 */

#ifndef REDPOINT_H_
#define REDPOINT_H_
#include <opencv/cv.h>


#define FindRedPoint FindRedPointRGB
#define FindRedPoint FindRedPointHSV

int ProcessImage(IplImage *inimg, IplImage *outimg);

void FindRedPoint(IplImage *img, int *Max, CvPoint *maxPoint);
void VideoRed(int argc, char* argv[]);
void ImageRed(int argc, char* argv[]);
void drawTarget(IplImage* img, CvPoint pt, int radius);


#endif /* REDPOINT_H_ */
