CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# generate lib
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)  ##### 

aux_source_directory(. LEETCODE_SRC)
add_library(leetCodelib ${LEETCODE_SRC})


# 用到其他的代码文件时，即头文件引用了其他的头文件
# link_directories("${PROJECT_SOURCE_DIR}/lib")
# target_link_libraries(addlib xxx xxx)