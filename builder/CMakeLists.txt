project(builder)			# Название проекта

add_library(${PROJECT_NAME}
	STATIC
	TokenBuilder.cpp
)
target_link_libraries(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC . )

