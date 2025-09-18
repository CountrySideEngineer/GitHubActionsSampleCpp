cmake_minimum_required(VERSION 3.10)
project(UTEST_util_init_buff)

# テスト対象コード、およびテストコードのルートディレクトリのパス
set(SRC_ROOT_DIR ${CMAKE_SOURCE_DIR}/../../../src)
set(TST_ROOT_DIR ${CMAKE_SOURCE_DIR}/../../../test)

message(STATUS "CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
message(STATUS "SRC_ROOT_DIR = ${SRC_ROOT_DIR}")
message(STATUS "TST_ROOT_DIR = ${TST_ROOT_DIR}")

# GoogleTestのパス
set(GTEST_ROOT "${TST_ROOT_DIR}/framework/googletest")
set(GTEST_INCLUDE_DIR "${GTEST_ROOT}/include")
set(GTEST_LIB_DIR "${GTEST_ROOT}/lib")

# テスト対象ソースのディレクトリ
set(TEST_DIR "${CMAKE_SOURCE_DIR}")

message(STATUS "TEST_DIR = ${TEST_DIR}")

# テスト対象ソースファイル
set(TEST_SRC
	${SRC_ROOT_DIR}/UTIL/util.cpp
	${TEST_DIR}/UTEST_util_init_buff.cpp
)

message(STATUS "TEST_SRC = ${TEST_SRC}")

# GoogleTestライブラリ
set(GTEST_LIBS
    ${GTEST_LIB_DIR}/libgtest.a
    ${GTEST_LIB_DIR}/libgtest_main.a
    ${GTEST_LIB_DIR}/libgmock.a
    ${GTEST_LIB_DIR}/libgmock_main.a
)

# テスト実行ファイル生成
add_executable(utest_util_init_buff ${TEST_SRC})

# インクルードディレクトリ
include_directories(
    ${GTEST_INCLUDE_DIR}
	${SRC_ROOT_DIR}/include
	${SRC_ROOT_DIR}/UTIL
)

# コンパイラオプション
set(CMAKE_BUILD_TYPE Debug)

# リンク
target_link_libraries(utest_util_init_buff ${GTEST_LIBS} pthread)

message(STATUS "COMMAND = ${COMMAND}")

# テスト追加
enable_testing()
add_test(NAME util_init_buff_test COMMAND utest_util_init_buff)
