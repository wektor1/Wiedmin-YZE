add_executable(Character_ut
  CharacterListTests.cpp
)
target_link_libraries(Character_ut
  PRIVATE
  Character_lib
  Qt${QT_VERSION_MAJOR}::Test
)

# set_property(SOURCE CharacterListTests.cpp PROPERTY SKIP_AUTOMOC ON)
add_test(Character_ut Character_ut)
