add_library(Character_lib STATIC
  Data/CharacterData.cpp

  List/CharacterList.cpp
  include/List/CharacterList.hpp

  Sheet/CharacterWindow.cpp
  Sheet/CharacterWindow.ui
  include/Sheet/CharacterWindow.hpp
)

target_include_directories(Character_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Character_lib PUBLIC
  Qt${QT_VERSION_MAJOR}::Widgets
)