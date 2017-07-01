set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-register")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.2)
project(Prysme)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(parser
             src/pry_parser.yy
           ${CMAKE_CURRENT_BINARY_DIR}/pry_parser.tab.cpp)

FLEX_TARGET(scanner
            src/pry_lexer.l
          ${CMAKE_CURRENT_BINARY_DIR}/pry_lexer.yy.cpp)

ADD_FLEX_BISON_DEPENDENCY(scanner parser)

add_executable(prysme
    src/main.cpp
    src/pry_driver
    src/pry_scanner

    src/variable/row
    src/variable/table
    src/variable/variable
    src/variable/already_defined_exception
    src/variable/not_found_exception

    src/tree/list
    src/tree/scope

    src/node/node
    src/node/variable
    src/node/primitive

    ${FLEX_scanner_OUTPUTS}
    ${BISON_parser_OUTPUTS}
)

target_link_libraries(prysme ${FLEX_LIBRARIES} ${BISON_LIBRARIES})

target_include_directories(prysme
    PRIVATE
        src
        .
        ${CMAKE_CURRENT_BINARY_DIR})

install (TARGETS prysme RUNTIME DESTINATION bin)
