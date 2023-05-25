cmake_minimum_required(VERSION 3.16)	 # Проверка версии CMake.
										# Если версия установленой программы
										# старее указаной, произайдёт аварийный выход.

project(lex_analizer)			# Название проекта

# Включаем C++ 2020
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_CXX_COMPILER /usr/bin/g++)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wshadow")


add_subdirectory(states)

add_subdirectory(context)

add_subdirectory(builder)

add_subdirectory(hashMap)

add_subdirectory(scope)
#file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "libs/my_string/*.cpp")
add_executable(${PROJECT_NAME}
    main.cpp
)
# set(SOURCE_LIB  libs/mlib_input.cpp) 			# Тоже самое, но для библиотеки
#
#
# add_library(lib STATIC ${SOURCE_LIB})	# Создание статической библиотеки с именем foo
# add_library(str_libs STATIC ${SOURCES})	# Создает исполняемый файл с именем main
# add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main
#
#add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main

# target_link_libraries(hash_tree lib str_libs)		# Линковка программы с библиотекой
target_link_libraries(${PROJECT_NAME}
    states
    context
)		# Линковка программы с библиотекой
