cmake_minimum_required(VERSION 3.10)

project(UTESTS)

#
# 基準となるディレクトリの定義
#
## テスト対象コードのルートディレクトリのパスの設定
set(SRC_ROOT_DIR ${CMAKE_SOURCE_DIR}/../../src)

## テストコードのルートディレクトリのパスの設定
set(TEST_ROOT_DIR ${CMAKE_SOURCE_DIR}/..)
set(TEST_SRC_DIR ${TEST_ROOT_DIR}/src)

message(STATUS "TEST_SRC_DIR = ${TEST_SRC_DIR}")

### テストフレームワークのディレクトリのパスの設定
set(TEST_FRAMEWORK_DIR ${TEST_ROOT_DIR}/framework)
set(TEST_FRAMEWORK_INCLUDE_DIR ${TEST_FRAMEWORK_DIR}/googletest/include)
set(TEST_FRAMEWORK_LIB_DIR ${TEST_FRAMEWORK_DIR}/googletest/lib)
set(TEST_FRAMEWORK_LIB_FILES 
	${TEST_FRAMEWORK_LIB_DIR}/libgtest.a
	${TEST_FRAMEWORK_LIB_DIR}/libgtest_main.a
	${TEST_FRAMEWORK_LIB_DIR}/libgmock.a
	${TEST_FRAMEWORK_LIB_DIR}/libgmock_main.a
)

# add_subdirectory(CLC)
add_subdirectory(UTIL)
