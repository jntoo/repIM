cmake_minimum_required(VERSION 3.2)
project(rapIM)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_C_STANDARD 99)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set(CMAKE_DEBUG_POSTFIX "_d")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/../lib)


if(DEFINED $ENV{SCITER_ROOT})
    set(SCITER_SDK_INC $ENV{SCITER_ROOT})
else()
    set(SCITER_SDK_INC "${PROJECT_SOURCE_DIR}/third_party/sciter")
endif()

if(DEFINED $ENV{SQLITE_ROOT})
    set(SQLITE_SDK_INC $ENV{SQLITE_ROOT})
else()
    set(SQLITE_SDK_INC "${PROJECT_SOURCE_DIR}/third_party/sqlite")
endif()


message(STATUS "SCITER_SDK_INC: ${SCITER_SDK_INC}")
message(STATUS "Using toolchain file: ${CMAKE_TOOLCHAIN_FILE}.")



set(SCITER_SRC ${SCITER_SDK_INC}/sciter-win-main.cpp)

IF(WIN32) #windows
    add_definitions(-DUNICODE -D_UNICODE)  # unicode 支持
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:wWinMainCRTStartup")
endif()

file(GLOB SQLITE_SRC ${SQLITE_SDK_INC}/*.cpp ${SQLITE_SDK_INC}/*.c)


include_directories(BEFORE ${SCITER_SDK_INC})



#find_package(asio CONFIG REQUIRED)

message(STATUC "${SQLITE_SRC}")
#add_library(SQLITE STATIC ${SQLITE_SRC})

add_subdirectory(src)


#target_link_libraries(main PRIVATE asio asio::asio)
#add_executable(rapIM main.cpp)