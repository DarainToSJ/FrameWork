#-------------------------------------------------------------------------------
set(CFG_QT_VERSION 5.15.1)
if(WIN32)
    set(QT_INSTALL_PATH "C:/Qt/${CFG_QT_VERSION}")
else()
    set(QT_INSTALL_PATH "/Applications/Qt${CFG_QT_VERSION}/${CFG_QT_VERSION}")
endif()

#-------------------------------------------------------------------------------
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#-------------------------------------------------------------------------------
if((NOT QT_DIR) AND (NOT IS_DIRECTORY "${QT_DIR}"))
    if(WIN32)
        if(${CMAKE_CL_64})
            set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${QT_INSTALL_PATH}/msvc2019_64")
        else()
            set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${QT_INSTALL_PATH}/msvc2019")
        endif()
    elseif(APPLE)
        set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${QT_INSTALL_PATH}/clang_64")
    endif()
endif()
