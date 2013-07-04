PROJECT(SWMetrics)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6) 

SET(CMAKE_COLOR_MAKEFILE ON)
SET(CMAKE_VERBOSE_MAKEFILE ON)
SET(CMAKE_INCLUDE_CURRENT_DIR TRUE)

FILE(GLOB_RECURSE ASTM ./ASTM/*.cpp)
FILE(GLOB_RECURSE TINYXML ./TinyXML/*.cpp)
FILE(GLOB_RECURSE MODULES ./Modules/*.cpp)

ADD_CUSTOM_COMMAND(OUTPUT ${PROJECT_SOURCE_DIR}/Frontends/C++/cpp.tab.cpp PRE_BUILD COMMAND flex -o ${PROJECT_SOURCE_DIR}/Frontends/C++/lex.yy.c ${PROJECT_SOURCE_DIR}/Frontends/C++/cpp.l COMMAND bison -d -o ${PROJECT_SOURCE_DIR}/Frontends/C++/cpp.tab.cpp ${PROJECT_SOURCE_DIR}/Frontends/C++/cpp.ypp COMMAND ${PROJECT_SOURCE_DIR}/Frontends/C++/editor.sh ${PROJECT_SOURCE_DIR}/Frontends/C++/cpp.tab.cpp COMMAND cd ${PROJECT_BINARY_DIR} COMMENT "Flex & Bison: building the lexer & parser.")

ADD_EXECUTABLE(sw_metrics ${ASTM} ${TINYXML} ${MODULES} ./Frontends/C++/cpp.tab.cpp ./Frontends/C++/ActualParsingUnit.cpp ./Frontends/C++/CppParser.cpp main.cpp)
LINK_LIBRARIES(lfl)
