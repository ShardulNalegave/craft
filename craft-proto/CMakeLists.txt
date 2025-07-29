cmake_minimum_required(VERSION 3.15)
project(craft-proto VERSION 0.1.0 LANGUAGES C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PROTOBUF_C REQUIRED libprotobuf-c>=1.0.0)

find_program(PROTOC_C_COMPILER protoc-c REQUIRED)
if(NOT PROTOC_C_COMPILER)
    message(FATAL_ERROR "protoc-c compiler not found!")
endif()

set(PROTO_DIR "${CMAKE_CURRENT_SOURCE_DIR}/proto")
set(GENERATED_DIR "${CMAKE_CURRENT_SOURCE_DIR}/generated")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/craft-proto")

file(MAKE_DIRECTORY ${GENERATED_DIR})
file(MAKE_DIRECTORY ${INCLUDE_DIR})

set(GENERATED_SOURCES)
set(GENERATED_HEADERS)
set(PUBLIC_HEADERS)

function(protobuf_generate_c PROTO_FILE)
    get_filename_component(PROTO_NAME ${PROTO_FILE} NAME_WE)
    set(GENERATED_C "${GENERATED_DIR}/${PROTO_NAME}.pb-c.c")
    set(GENERATED_H "${GENERATED_DIR}/${PROTO_NAME}.pb-c.h")
    set(PUBLIC_H "${INCLUDE_DIR}/${PROTO_NAME}.pb-c.h")
    
    add_custom_command(
        OUTPUT ${GENERATED_C} ${GENERATED_H}
        COMMAND protoc
        ARGS --c_out=${GENERATED_DIR} 
             --proto_path=${PROTO_DIR}
             ${PROTO_FILE}
        DEPENDS ${PROTO_FILE}
        COMMENT "Generating C code from ${PROTO_FILE}"
        VERBATIM
    )

    add_custom_command(
        OUTPUT ${PUBLIC_H}
        COMMAND mv ${GENERATED_H} ${PUBLIC_H}
        DEPENDS ${GENERATED_H}
        COMMENT "Moving ${PROTO_NAME}.pb-c.h to public include directory"
        VERBATIM
    )

    set(GENERATED_SOURCES ${GENERATED_SOURCES} ${GENERATED_C} PARENT_SCOPE)
    set(GENERATED_HEADERS ${GENERATED_HEADERS} ${GENERATED_H} PARENT_SCOPE)
    set(PUBLIC_HEADERS ${PUBLIC_HEADERS} ${PUBLIC_H} PARENT_SCOPE)
endfunction()

file(GLOB PROTO_FILES "${PROTO_DIR}/*.proto")

foreach(PROTO_FILE ${PROTO_FILES})
    protobuf_generate_c(${PROTO_FILE})
endforeach()

add_library(craft-proto STATIC ${GENERATED_SOURCES})

add_custom_target(generate_proto_files
    DEPENDS ${GENERATED_SOURCES} ${GENERATED_HEADERS} ${PUBLIC_HEADERS}
    COMMENT "Generating all protobuf files"
)

add_dependencies(craft-proto generate_proto_files)

target_include_directories(craft-proto
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/craft-proto>
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${PROTOBUF_C_INCLUDE_DIRS}
)

target_link_libraries(craft-proto
    PUBLIC
        ${PROTOBUF_C_LIBRARIES}
)

target_compile_options(craft-proto
    PRIVATE
        ${PROTOBUF_C_CFLAGS_OTHER}
)
