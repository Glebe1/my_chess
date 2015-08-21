PROJECT(chess)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Qt library
FIND_PACKAGE(Qt5Widgets REQUIRED)

#Add resources
set(IMG_RES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/res/Images/")
set(IMG_BIN_RES_DIR "${CMAKE_CURRENT_BINARY_DIR}/res/Images/")

set(images_RESOURCES pic1.png
                    Bishop_white.png
                    Bishop_black.png
                    Knight_white.png
                    Knight_black.png)

foreach(FILENAME ${images_RESOURCES})
  FILE(COPY "${IMG_RES_DIR}${FILENAME}" DESTINATION "${IMG_BIN_RES_DIR}")
endforeach(FILENAME)

set(BRD_RES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/res/Boards/")
set(BRD_BIN_RES_DIR "${CMAKE_CURRENT_BINARY_DIR}/res/Boards/")

set(boards_RESOURCES Default_Board.cbb)

foreach(FILENAME ${boards_RESOURCES})
  FILE(COPY "${BRD_RES_DIR}${FILENAME}" DESTINATION "${BRD_BIN_RES_DIR}")
endforeach(FILENAME)

SET(chess_SOURCES main.cpp
    src/MainWindow.cpp
    src/Board.cpp
    src/Square.cpp
    src/Piece.cpp
    src/Knight.cpp
    src/Bishop.cpp)

SET(chess_HEADERS include/MainWindow.h
    include/Board.h
    include/Square.h
    include/Piece.h
    include/Knight.h
    include/Bishop.h)

SET(chess_FORMS ui/MainWindow.ui)

QT5_WRAP_CPP(chess_HEADERS_MOC ${chess_HEADERS})
QT5_WRAP_UI(chess_FORMS_HEADERS ${chess_FORMS})

ADD_EXECUTABLE(chess ${chess_SOURCES}
    ${chess_HEADERS_MOC}
    ${chess_FORMS_HEADERS})

QT5_USE_MODULES(chess Widgets)

TARGET_LINK_LIBRARIES(chess ${QT_LIBRARIES})

