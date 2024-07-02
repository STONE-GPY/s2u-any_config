# Any Config
# Copyright (C) 2024 Wend4r
# Licensed under the GPLv3 license. See LICENSE file in the project root for details.

cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

if(POLICY CMP0092)
	cmake_policy(SET CMP0092 NEW) # Don't add -W3 warning level by default.
endif()

project(any_config
	VERSION 1.0.2
	DESCRIPTION "Any Config"
	HOMEPAGE_URL "https://github.com/Wend4r/s2u-any_config"
	LANGUAGES C CXX
)

if(NOT SOURCESDK_DIR)
	message(WARNING "SOURCESDK_DIR is empty")
	set(SOURCESDK_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../hl2sdk-wend4r/hl2sdk-cs2)
endif()

set(INCLUDE_DIR "include")
set(SOURCE_DIR "src")

include("cmake/platform/shared.cmake")

if(LINUX)
	include("cmake/platform/linux.cmake")
elseif(WINDOWS)
	include("cmake/platform/windows.cmake")
endif()

include("cmake/sourcesdk.cmake")

set(SOURCE_FILES
	${SOURCE_DIR}/any_config/base/base.cpp
	${SOURCE_DIR}/any_config/base/reader.cpp
	${SOURCE_DIR}/any_config/base/writer.cpp

	${SOURCE_DIR}/any_config/json/reader.cpp
	${SOURCE_DIR}/any_config/json/writer.cpp

	${SOURCE_DIR}/any_config/keyvalues/reader.cpp
	${SOURCE_DIR}/any_config/keyvalues/writer.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY C_EXTENSIONS OFF)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)

target_compile_options(${PROJECT_NAME} PRIVATE ${PLATFORM_COMPILER_OPTIONS})
target_link_options(${PROJECT_NAME} PRIVATE ${PLATFORM_LINKER_OPTIONS})

target_compile_definitions(${PROJECT_NAME} PRIVATE ${PLATFORM_COMPILE_DEFINITIONS} ${SOURCESDK_COMPILE_DEFINTIONS})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR} ${SOURCESDK_INCLUDE_DIR})
