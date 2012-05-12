set (PROJECT RoboVision)
project ( ${PROJECT}  )
cmake_minimum_required(VERSION 2.6)

set( OpenCV_USE_LIBS opencv_core opencv_imgproc opencv_highgui opencv_ml opencv_video opencv_features2d opencv_calib3d opencv_objdetect opencv_contrib opencv_legacy opencv_flann )
find_package ( OpenCV )
#include(${OpenCV_USE_FILE})
set (SOURCES RoVi.cpp)

add_executable ( ${PROJECT} ${SOURCES} )
target_link_libraries ( ${PROJECT} ${OpenCV_LIBS} )