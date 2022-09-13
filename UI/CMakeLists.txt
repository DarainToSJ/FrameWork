cmake_minimum_required (VERSION 3.8)

project ("UI")
#######################���������ļ�
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../CMake)



set(CMAKE_INCLUDE_CURRENT_DIR ON)

################################# 4������������Qt�ļ�
find_package(Qt5  COMPONENTS Widgets Core Gui REQUIRED)   

add_definitions(-DDLL_EXPORTS)


set(INC_LIST 
	 ./inc/Export_Dll.h
	 ./inc/TitleBar.h
     ./inc/BaseWidget.h
	 ./inc/ContentW.h 
	 ./inc/MainWindow.h
	 
	 
	 )


set(SRC_LIST 
 ./src/TitleBar.cpp
 ./src/BaseWidget.cpp
 ./src/ContentW.cpp 
 ./src/MainWindow.cpp
 
 
 )

set(RES_LIST 
	./res/Control.qrc
)

include_directories(${PROJECT_SOURCE_DIR}/inc)

# include_directories(${PROJECT_SOURCE_DIR}/../Base/inc)



add_library(${PROJECT_NAME} SHARED ${INC_LIST}  ${SRC_LIST} ${RES_LIST})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/../Base/inc)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets)



target_link_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/../${PREFIX_DIR})


target_link_libraries(${PROJECT_NAME} PRIVATE Base.lib)

include(configDll)