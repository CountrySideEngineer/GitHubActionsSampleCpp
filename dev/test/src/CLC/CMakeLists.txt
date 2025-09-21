cmake_minimum_required(VERSION 3.10)
project(UTEST_TravelSpeed)

include(GoogleTest)

# テスト対象コードのルートディレクトリのパスの設定
if(DEFINED SRC_ROOT_DIR)
	message(STATUS "SRC_ROOT_DIR is defined: ${SRC_ROOT_DIR}")
else()
	set(SRC_ROOT_DIR ${CMAKE_SOURCE_DIR}/../../../src)
	message(STATUS "SRC_ROOT_DIR is not defined"	)
	message(STATUS "SRC_ROOT_DIR is defined: ${SRC_ROOT_DIR}")
endif()

# テストコードのルートディレクトリのパスの設定
if(DEFINED TEST_ROOT_DIR)
	message(STATUS "TEST_ROOT_DIR is defined: ${TEST_ROOT_DIR}")
else()
	set(TEST_ROOT_DIR ${CMAKE_SOURCE_DIR}/../../../test)
	message(STATUS "TEST_ROOT_DIR is not defined"	)
	message(STATUS "TEST_ROOT_DIR is defined: ${TEST_ROOT_DIR}")
endif()

if (DEFINED TEST_SRC_DIR)
	message(STATUS "TEST_SRC_DIR is defined: ${TEST_SRC_DIR}")
else()
	set(TEST_SRC_DIR ${TEST_ROOT_DIR}/src)
	message(STATUS "TEST_SRC_DIR is not defined"	)
	message(STATUS "TEST_SRC_DIR is defined: ${TEST_SRC_DIR}")
endif()


# テストフレームワークの設定
if(DEFINED TEST_FRAMEWORK_DIR)
	message(STATUS "TEST_FRAMEWORK_DIR is defined: ${TEST_FRAMEWORK_DIR}")
	message(STATUS "TEST_FRAMEWORK_INCLUDE_DIR = ${TEST_FRAMEWORK_INCLUDE_DIR}"	)
	message(STATUS "TEST_FRAMEWORK_LIB_DIR = ${TEST_FRAMEWORK_LIB_DIR}"	)
else()
	set(TEST_FRAMEWORK_DIR ${TEST_ROOT_DIR}/framework)
	set(TEST_FRAMEWORK_INCLUDE_DIR ${TEST_FRAMEWORK_DIR}/googletest/include)
	set(TEST_FRAMEWORK_LIB_DIR ${TEST_FRAMEWORK_DIR}/googletest/lib)
	set(TEST_FRAMEWORK_LIB_FILES 
		${TEST_FRAMEWORK_LIB_DIR}/libgtest.a
		${TEST_FRAMEWORK_LIB_DIR}/libgtest_main.a
		${TEST_FRAMEWORK_LIB_DIR}/libgmock.a
		${TEST_FRAMEWORK_LIB_DIR}/libgmock_main.a
	)
	message(STATUS "TEST_FRAMEWORK_DIR is not defined"	)
	message(STATUS "TEST_FRAMEWORK_DIR is defined: ${TEST_FRAMEWORK_DIR}")
	message(STATUS "TEST_FRAMEWORK_INCLUDE_DIR is not defined"	)
	message(STATUS "TEST_FRAMEWORK_INCLUDE_DIR is defined: ${TEST_FRAMEWORK_INCLUDE_DIR}")
	message(STATUS "TEST_FRAMEWORK_LIB_DIR is not defined"	)
	message(STATUS "TEST_FRAMEWORK_LIB_DIR is defined: ${TEST_FRAMEWORK_LIB_DIR}")
endif()

# テスト対象ソースファイル
set(TEST_SRC
	${SRC_ROOT_DIR}/CLC/CLC_TravelSpeed.cpp
	${TEST_SRC_DIR}/CLC/UTEST_TravelSpeed_init_travel_speed.cpp
)

message(STATUS "TEST_SRC : ${TEST_SRC}")

# テスト実行ファイル生成
add_executable(UTEST_TravelSpeed ${TEST_SRC})

# インクルードディレクトリ
include_directories(
    ${TEST_FRAMEWORK_INCLUDE_DIR}
	${SRC_ROOT_DIR}/include
	${SRC_ROOT_DIR}/UTIL
)

# コンパイラオプション
set(CMAKE_BUILD_TYPE Debug)

# リンク
target_link_libraries(UTEST_TravelSpeed ${TEST_FRAMEWORK_LIB_FILES} pthread)

message(STATUS "COMMAND = ${COMMAND}")

# テスト追加
enable_testing()
gtest_add_tests(TARGET UTEST_TravelSpeed)
