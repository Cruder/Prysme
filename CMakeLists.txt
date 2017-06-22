set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-deprecated-register")
cmake_minimum_required(VERSION 3.2)

project(Prysme)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(pry_parser
             src/pry_parser.yy
             ${CMAKE_CURRENT_BINARY_DIR}/pry_parser.tab.cc)

FLEX_TARGET(pry_lexer
            src/pry_lexer.l
            ${CMAKE_CURRENT_BINARY_DIR}/pry_lexer.yy.cc)

# ADD_FLEX_BISON_DEPENDENCY(pry_parser pry_lexer)

add_executable(prysme
    src/main.cpp
    src/pry_driver

    ${FLEX_pry_lexer_OUTPUTS}
    ${BISON_pry_parser_OUTPUTS}
)
target_include_directories(prysme
    PRIVATE
        .
        ${CMAKE_CURRENT_BINARY_DIR})

set_property(TARGET prysme
             PROPERTY CXX_STANDARD 14)
