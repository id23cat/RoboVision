/*
 * RedPoint.h
 *
 *  Created on: 06.06.2012
 *      Author: id23cat
 */

#ifndef REDPOINT_H_
#define REDPOINT_H_
#include <opencv/cv.h>

int ProcessImage(IplImage *inimg, IplImage *outimg);

void FindRedPoint(IplImage *img, int *Max, CvPoint *maxPoint);
void VideoRed(int argc, char* argv[]);
void ImageRed(int argc, char* argv[]);
void drawTarget(IplImage* img, CvPoint pt, int radius);
void BRIGHTNESSCallback(int pos);
void CONTRASTCallback(int pos);
void SATURATIONCallback(int pos);
void MINTthresholdCallback(int pos);

#endif /* REDPOINT_H_ */
