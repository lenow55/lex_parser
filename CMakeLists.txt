cmake_minimum_required(VERSION 3.8)	 # Проверка версии CMake.
										# Если версия установленой программы
										# старее указаной, произайдёт аварийный выход.

project(main)			# Название проекта

# Включаем C++ 2020
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_COMPILER g++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wshadow")


#file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "libs/my_string/*.cpp")
set(SOURCE_EXE  main.cpp)		# Установка переменной со списком исходников для исполняемого файла
# set(SOURCE_LIB  libs/mlib_input.cpp) 			# Тоже самое, но для библиотеки
#
#
# add_library(lib STATIC ${SOURCE_LIB})	# Создание статической библиотеки с именем foo
# add_library(str_libs STATIC ${SOURCES})	# Создает исполняемый файл с именем main
add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main
#
#add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main

# target_link_libraries(hash_tree lib str_libs)		# Линковка программы с библиотекой
target_link_libraries(main)		# Линковка программы с библиотекой
