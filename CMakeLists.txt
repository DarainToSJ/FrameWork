# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
################################## 1、最低CMake版本
cmake_minimum_required (VERSION 3.8)

set(PROJECT_NAME  FrameWork)

project (${PROJECT_NAME})


################################# 2、项目名qtCmake
project(${PROJECT_NAME} LANGUAGES CXX)

################################# 3、set模块
set(CMAKE_INCLUDE_CURRENT_DIR ON)
##################系统设置
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(SYSTEM_NAME Win32)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(SYSTEM_NAME MacOS)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(SYSTEM_NAME Linux)
endif()
message(STATUS "[${PROJECT_NAME}] " System:${SYSTEM_NAME})
##################### 操作平台设置
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(BUILD_PLATFORM x64)
else()
    set(BUILD_PLATFORM x86)
endif()
message(STATUS "[${PROJECT_NAME}] BUILD_PLATFORM:${BUILD_PLATFORM}")

# default RelWithDebInfo
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()
message(STATUS "[${PROJECT_NAME}] BUILD_TYPE:${CMAKE_BUILD_TYPE}")

##############设置路径变量参数
set(PREFIX_DIR "Build/${SYSTEM_NAME}/${BUILD_PLATFORM}/${CMAKE_BUILD_TYPE}")

message(STATUS "[${PROJECT_NAME}] PREFIX_DIR:${PREFIX_DIR}")
#######################Qt 元对象设置

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)



#######################添加配置文件
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)



################配置C++环境
include(ConfigCXX)

include(ConfigQt)

# 设置exe生成路径。喜欢用CMAKE_CURRENT_SOURCE_DIR，指CMakeLists.txt所在的路径
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/)
# 设置c++语言支持
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ################################# 4、查找依赖的Qt文件
# find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)    

# #########################包含当前目录
# set(CMAKE_INCLUDE_CURRENT_DIR ON)

message(STATUS "PROJECT_SOURCE_DIR:"${PROJECT_SOURCE_DIR})



# ################################添加子项目文件
# add_subdirectory(MainWindow)

 add_subdirectory(UI)

 add_subdirectory(Base)


# #################################DependsOn  依赖
 add_dependencies(UI Base)

