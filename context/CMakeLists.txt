project(context)			# Название проекта

add_library(${PROJECT_NAME}
	STATIC
	context.cpp
)

add_subdirectory(../builder builder)

target_link_libraries(${PROJECT_NAME} builder)
target_include_directories(${PROJECT_NAME} PUBLIC . )

