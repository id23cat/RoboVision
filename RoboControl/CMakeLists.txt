set ( PROJECT RoboControl )
project ( ${PROJECT}  )
cmake_minimum_required ( VERSION 2.8 )

# Sources
set( SOURCES main.cpp mainwindow.cpp qimagegrabber.cpp qimagegrabbermjpeg.cpp networker.cpp )
# Includes
set( HEADERS mainwindow.h networker.h qimagegrabber_global.h qimagegrabber.h qimagegrabbermjpeg.h )

# Libraries

#set( LIBRARIES m opencv_core opencv_highgui opencv_video opencv_imgproc)
set( UI mainwindow.ui)
	
set( LANGUAGES )
set( RESOURCE_PATH resources )
set( RESOURCES )
set(TRANSLATIONS_PATH /resources/translations)

# enable warnings
add_definitions ( -Wall )

# by default only QtCore and QtGui modules are enabled
# other modules must be enabled like this:
set( QT_USE_QT3SUPPORT TRUE )   
set( QT_USE_QTXML TRUE )

# Finding reqirements
find_package(Qt4 REQUIRED)
find_package(Qt4 COMPONENTS QtCore QtGui QtNetwork REQUIRED)
include(${QT_USE_FILE})
#include_directories(${CMAKE_CURRENT_BINARY_DIR})


# Qt settings
qt4_wrap_cpp(MOC_SOURCES ${HEADERS})
qt4_add_resources(QRC_SOURCES ${RESOURCES})
qt4_wrap_ui( UI_HEADERS ${UI} )

foreach (LANGUAGE ${LANGUAGES})
	set(TS ${TRANSLATIONS_PATH}/${LANGUAGE}.ts)
	set(QM ${TRANSLATIONS_PATH}/${LANGUAGE}.qm)
	set(TRANSLATIONS ${TRANSLATIONS} ${TS})
	set(TRANSLATIONS_BINARY ${TRANSLATIONS_BINARY} ${QM})
	add_custom_command(
		OUTPUT ${QM}
		COMMAND ${QT_LRELEASE_EXECUTABLE} ${TS}
		MAIN_DEPENDENCY ${TS})
endforeach()

#add_custom_target (
#	translations
#	COMMAND ${QT_LUPDATE_EXECUTABLE} ${HEADERS} ${SOURCES} -ts ${TRANSLATIONS})
#add_custom_command (
#	TARGET translations
#	COMMAND ${QT_LRELEASE_EXECUTABLE} ${TRANSLATIONS})
 

if ( MSVC )
	add_definitions ( /W4 )
elseif ( CMAKE_COMPILER_IS_GNUCXX )
	add_definitions ( -Wall -pedantic )
else ()
	message ( "Unknown compiler" )
endif ()

##########################
###	Vision libraries
set(VISION RoboVision)
set(VISIONLIB ${VISION})

# Set path to RoboVision directory
set( ROBO_VISION_DIR ${CMAKE_CURRENT_BINARY_DIR}/../${VISION} )
set( HEADERS ${HEADERS} ${ROBO_VISION_DIR}/RedPoint.h  )


#link_directories ( ${CMAKE_BINARY_DIR}../RoboVision/lib )
link_directories(${ROBO_VISION_DIR}/lib)
include_directories(${ROBO_VISION_DIR})

###	OpenCV libralies
find_package( OpenCV )
set ( OpenCV_USE_LIBS opencv_core opencv_imgproc opencv_highgui opencv_ml opencv_video opencv_features2d opencv_calib3d opencv_objdetect opencv_contrib opencv_legacy opencv_flann )


set ( EXECUTABLE_OUTPUT_PATH  ${CMAKE_CURRENT_BINARY_DIR}/../bin )
##########################

#source_group ("Header Files" FILES ${HEADERS})
#source_group ("Source Files" FILES ${SOURCES})
#source_group ("Generated Files" FILES ${MOC_SOURCES})
#source_group ("Resource Files" FILES ${QRC_SOURCES})

#${HEADERS}
add_executable (${PROJECT} ${SOURCES} ${MOC_SOURCES} ${QRC_SOURCES} ${TRANSLATIONS} ${UI_HEADERS})

 
target_link_libraries (${PROJECT}  ${QT_LIBRARIES} ${VISIONLIB} ${OpenCV_USE_LIBS})

