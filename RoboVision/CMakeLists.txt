set ( PROJECT RoboVision )
project ( ${PROJECT}  )
cmake_minimum_required ( VERSION 2.8 )


set ( OpenCV_USE_LIBS opencv_core opencv_imgproc opencv_highgui opencv_ml opencv_video opencv_features2d opencv_calib3d opencv_objdetect opencv_contrib opencv_legacy opencv_flann )
find_package ( OpenCV )
set ( SOURCES RedPoint.cpp )
set ( HEADERS RedPoint.h )

message ( "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}" )
message ( "CMAKE_CURRENT_BINARY_DIR  = ${CMAKE_CURRENT_BINARY_DIR}" )
message ( "CMAKE_CURRENT_SOURCE_DIR  = ${CMAKE_CURRENT_SOURCE_DIR}" )
message ( "CMAKE_FILES_DIRECTORY  = ${CMAKE_FILES_DIRECTORY}" )
message ( "CMAKE_ROOT   = ${CMAKE_ROOT}" )
message ( "CMAKE_SOURCE_DIR  = ${CMAKE_SOURCE_DIR}" )
message ( "PROJECT_BINARY_DIR  = ${PROJECT_BINARY_DIR}" )
message ( "PROJECT_SOURCE_DIR  = ${PROJECT_SOURCE_DIR}" )

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

if ( MSVC )
	add_definitions ( /W4 )
elseif ( CMAKE_COMPILER_IS_GNUCXX )
	add_definitions ( -Wall -pedantic )
else ()
	message ( "Unknown compiler" )
endif ()


add_library ( ${PROJECT} ${SOURCES} )
target_link_libraries ( ${PROJECT} ${OpenCV_USE_LIBS} )
#CMAKE_BINARY_DIR
set ( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../lib )
set (INCLUDE_DIRECTORY ${PROJECT_SOURCE_DIR}/../include)
add_custom_target (project_include
    COMMAND ${CMAKE_COMMAND} -E  # Create a working directory.
        make_directory ${INCLUDE_DIRECTORY}
    COMMAND ${CMAKE_COMMAND} -E  # Copy a build system in there.
        copy ${HEADERS} ${INCLUDE_DIRECTORY})
        
