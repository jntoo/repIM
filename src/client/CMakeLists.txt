CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(server)


file(GLOB CLIENT_SRC ./*.cpp)

#add_executable(rapIMClient ${CLIENT_SRC} ${SCITER_SRC})
#target_link_libraries(rapIMClient PRIVATE asio asio::asio)