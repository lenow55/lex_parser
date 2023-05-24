project(hashMap)			# Название проекта

add_library(${PROJECT_NAME}
	STATIC
    HashMap.cpp
)
target_link_libraries(${PROJECT_NAME} builder)
target_include_directories(${PROJECT_NAME} PUBLIC . )

