project(context)			# Название проекта

add_library(${PROJECT_NAME}
	STATIC
	context.cpp
)

target_link_libraries(${PROJECT_NAME} builder states scope)
target_include_directories(${PROJECT_NAME} PUBLIC . )

