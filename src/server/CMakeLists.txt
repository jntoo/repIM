CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(server)


file(GLOB SERVER_SRC ./*.cpp)
message(STATUS "SCITER_SRC: ${SCITER_SRC}")
message(STATUS "SQLITE_SDK_INC: ${SQLITE_SDK_INC}")



add_executable(rapIMServer ${SERVER_SRC} ${SCITER_SRC})
#target_link_libraries(rapIMServer PRIVATE asio asio::asio)
