set ( PROJECT RoVi-gui )
project ( ${PROJECT}  )
cmake_minimum_required ( VERSION 2.8 )

add_subdirectory ( RoboVision )
#install(FILES "./RoboVision/lib/libRoboVision.a" DESTINATION "lib")
#install(FILES RoboVision/RedPoint.h DESTINATION "include/")

add_custom_command(TARGET RoboVision POST_BUILD        # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${PROJECT_SOURCE_DIR}/libs/test.dll"      # <--this is in-file
        $<TARGET_FILE_DIR:MyTest>)                 # <--this is out-file path


add_subdirectory ( RoboControl )

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

