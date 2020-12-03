CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#项目名称
PROJECT(HelloWorld)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)

# 根目录/代码路径
aux_source_directory(. DIR_MAIN)

#dubug 模式-----------------------it's very import for Debug
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# 添加子目录
include_directories("${PROJECT_SOURCE_DIR}/leetCode")   # head file
add_subdirectory(leetCode)         # source file search the catalog


# 编译成可执行文件
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)       ###### 输出可执行文件目录
add_executable(main ${DIR_MAIN})

# 链接hellolib库，注意下面子目录src的CMakeLists
link_directories("${PROJECT_SOURCE_DIR}/lib")
target_link_libraries(main leetCodelib)




####################################   Makefile.txt   #######################################
# CPP = g++
# CFLAGS = -Wall -O2 -g -IGeomtry -IInput -IOutput -IPostProcess -ISolver
# TARGET = ./Bin/main.exe
# DIRS = Common Geomtry Parser PostProcess Solver Main .
# FILES = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))
# OBJS = $(patsubst %.cpp,%.o,$(patsubst %.cpp,%.o,$(FILES)))
# $(TARGET):$(OBJS)
# 	$(CPP) -o $(TARGET) $(OBJS)
# clean:
# 	-$(RM) $(TARGET)
# 	-$(RM) $(OBJS)