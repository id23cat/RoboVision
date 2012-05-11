project( RoVi )
find_package( OpenCV REQUIRED )
add_executable( RoVi RoVi )
target_link_libraries( RoVi ${OpenCV_LIBS} )
