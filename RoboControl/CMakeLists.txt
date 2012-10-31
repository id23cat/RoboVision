set ( PROJECT RoboControl )
project ( ${PROJECT}  )
cmake_minimum_required ( VERSION 2.8 )

set ( SOURCES main.cpp mainwindow.cpp qimagegrabber.cpp qimagegrabbermjpeg.cpp networker.cpp )
set ( HEADERS mainwindow.h qimagegrabber.h qimagegrabbermjpeg.h networker.h)
#qimagegrabber_global.h
set ( LIBRARIES m opencv_core opencv_highgui opencv_video opencv_imgproc)
set ( UI mainwindow.ui)
	
set ( LANGUAGES )
set ( RESOURCE_PATH resources )
set ( RESOURCES )
set (TRANSLATIONS_PATH /resources/translations)

# enable warnings
add_definitions ( -Wall )

# by default only QtCore and QtGui modules are enabled
# other modules must be enabled like this:
set( QT_USE_QT3SUPPORT TRUE )   
set( QT_USE_QTXML TRUE )

find_package ( OpenCV )
find_package (Qt4 REQUIRED)
find_package(Qt4 COMPONENTS QtCore QtGui QtNetwork REQUIRED)
include (${QT_USE_FILE})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

qt4_wrap_cpp (MOC_SOURCES ${HEADERS})
qt4_add_resources (QRC_SOURCES ${RESOURCES})
qt4_wrap_ui( UI_HEADERS ${UI} )

foreach (LANGUAGE ${LANGUAGES})
	set (TS ${TRANSLATIONS_PATH}/${LANGUAGE}.ts)
	set (QM ${TRANSLATIONS_PATH}/${LANGUAGE}.qm)
	set (TRANSLATIONS ${TRANSLATIONS} ${TS})
	set (TRANSLATIONS_BINARY ${TRANSLATIONS_BINARY} ${QM})
	add_custom_command (
		OUTPUT ${QM}
		COMMAND ${QT_LRELEASE_EXECUTABLE} ${TS}
		MAIN_DEPENDENCY ${TS})
endforeach()
add_custom_target (
	translations 
	COMMAND ${QT_LUPDATE_EXECUTABLE} ${HEADERS} ${SOURCES} -ts ${TRANSLATIONS})
add_custom_command (
	TARGET translations
	COMMAND ${QT_LRELEASE_EXECUTABLE} ${TRANSLATIONS})
 
#foreach (LIBRARY ${LIBRARIES})
#	add_subdirectory (../${LIBRARY}/build bin/${LIBRARY})
#endforeach ()

if ( MSVC )
	add_definitions ( /W4 )
elseif ( CMAKE_COMPILER_IS_GNUCXX )
	add_definitions ( -Wall -pedantic )
else ()
	message ( "Unknown compiler" )
endif ()

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})
source_group ("Generated Files" FILES ${MOC_SOURCES})
source_group ("Resource Files" FILES ${QRC_SOURCES})

add_executable (${PROJECT} ${HEADERS} ${SOURCES} ${MOC_SOURCES} ${QRC_SOURCES} ${TRANSLATIONS} ${UI_HEADERS})
 
target_link_libraries (${PROJECT} ${LIBRARIES} ${QT_LIBRARIES})

