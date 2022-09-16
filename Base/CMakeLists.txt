cmake_minimum_required (VERSION 3.8)

project ("Base")
#######################���������ļ�
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../CMake)



set(CMAKE_INCLUDE_CURRENT_DIR ON)

################################# 4������������Qt�ļ�
find_package(Qt5 COMPONENTS Widgets REQUIRED)    #widget

find_package(Qt5 COMPONENTS Core REQUIRED)

find_package(Qt5 COMPONENTS Gui REQUIRED)

add_definitions(-DBASE_DLL_EXPORTS)
# add_compile_definitions(DLL_EXPORTS)

set(INC_LIST 
 ./inc/Base_Export_Dll.h
 ./inc/FileHelper.h
 ./inc/Item.h
 ./inc/Notify.h
 
 )


set(SRC_LIST 
  ./src/FileHelper.cpp
  ./src/Notify.cpp
	


)

set(RES_LIST 



)

include_directories(${PROJECT_SOURCE_DIR}/inc)


add_library(${PROJECT_NAME} SHARED  ${INC_LIST} ${SRC_LIST} ${RES_LIST})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets)

include(configDll)