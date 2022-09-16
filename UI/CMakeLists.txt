cmake_minimum_required (VERSION 3.8)

project ("UI")
#######################���������ļ�
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../CMake)

include(ConfigQt)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

################################# 4������������Qt�ļ�
find_package(Qt5  COMPONENTS Widgets Core Gui  Quick QuickWidgets Qml REQUIRED)




set(INC_LIST 
	 ./inc/Ui_Export_Dll.h
     ./inc/BaseWidget.h
	 ./inc/FramelessWindow.hpp
	 ./inc/BaseQmlWidget.h
	 ./inc/TitleBar.h
	 ./inc/MainWindow.h
	   "inc/DataObject.h" "inc/TitleBarData.h")


set(SRC_LIST 
 ./src/TitleBar.cpp
 ./src/BaseWidget.cpp
 ./src/BaseQmlWidget.cpp
 ./src/MainWindow.cpp
   "src/DataObject.cpp" "src/TitleBarData.cpp")

set(RES_LIST 
	./res/Control.qrc
	./res/qml.qrc
)



# include_directories(${PROJECT_SOURCE_DIR}/../Base/inc)
add_definitions(-DUI_DLL_EXPORTS)
add_definitions(-DQT_ANGLE_PLATFORM)
# add_compile_definitions(DLL_EXPORTS)


add_library(${PROJECT_NAME} SHARED ${INC_LIST}  ${SRC_LIST} ${RES_LIST})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/../Base/inc ${PROJECT_SOURCE_DIR}/inc)

include(configDll)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Qml
	Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets  Qt${QT_VERSION_MAJOR}::Quick  Qt${QT_VERSION_MAJOR}::QuickWidgets)



target_link_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/../${PREFIX_DIR})


target_link_libraries(${PROJECT_NAME} PRIVATE Base.lib)

