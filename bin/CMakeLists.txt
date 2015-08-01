PROJECT(chess)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Qt library
FIND_PACKAGE(Qt5Widgets REQUIRED)

#Add resources
set(IMG_RES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/res/Images/")
set(IMG_BIN_RES_DIR "${CMAKE_CURRENT_BINARY_DIR}/res/Images/")

set(chess_RESOURCES pic1.png)

foreach(FILENAME ${chess_RESOURCES})
  FILE(COPY "${IMG_RES_DIR}${FILENAME}" DESTINATION "${IMG_BIN_RES_DIR}")
endforeach(FILENAME)

SET(chess_SOURCES main.cpp
    src/MainWindow.cpp)
SET(chess_HEADERS include/MainWindow.h)
SET(chess_FORMS ui/MainWindow.ui)

QT5_WRAP_CPP(chess_HEADERS_MOC ${chess_HEADERS})
QT5_WRAP_UI(chess_FORMS_HEADERS ${chess_FORMS})

ADD_EXECUTABLE(chess ${chess_SOURCES}
    ${chess_HEADERS_MOC}
    ${chess_FORMS_HEADERS})

QT5_USE_MODULES(chess Widgets)

TARGET_LINK_LIBRARIES(chess ${QT_LIBRARIES})

