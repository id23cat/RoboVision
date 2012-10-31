set ( PROJECT RoVi-gui )
project ( ${PROJECT}  )
cmake_minimum_required ( VERSION 2.8 )

add_subdirectory ( RoboVision )
add_subdirectory ( RoboContol )

#add_subdirectory ( src lib )

##set( OpenCV_USE_LIBS opencv_core opencv_imgproc opencv_highgui opencv_ml opencv_video opencv_features2d opencv_calib3d opencv_objdetect opencv_contrib opencv_legacy opencv_flann )
##find_package ( OpenCV )

#include_directories ( ${PROJECT_SOURCE_DIR}/include ) 
#link_directories ( ${CMAKE_BINARY_DIR}/lib ) 

#if ( MSVC )
#	add_definitions ( /W4 )
#elseif ( CMAKE_COMPILER_IS_GNUCXX )
#	add_definitions ( -Wall -pedantic )
#else ()
#	message ( "Unknown compiler" )
#endif ()


#add_executable ( ${PROJECT} RoVi.cpp )
##target_link_libraries ( ${PROJECT} ${OpenCV_USE_LIBS} RoboVision )
#target_link_libraries ( ${PROJECT} RoboVision )

