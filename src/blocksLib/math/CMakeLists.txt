add_library(math SHARED add.cpp divide.cpp library.cpp modulus.cpp multiply.cpp negate.cpp subtract.cpp)

target_include_directories(math PRIVATE ${CMAKE_SOURCE_DIR}/lib/)

