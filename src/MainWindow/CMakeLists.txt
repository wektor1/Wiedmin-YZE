add_library(MainWindow_lib STATIC
  MainWindow.cpp

  include/MainWindow.hpp
)

target_include_directories(MainWindow_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(MainWindow_lib
  PRIVATE
  Qt${QT_VERSION_MAJOR}::Widgets

  PUBLIC
  Character_lib
)