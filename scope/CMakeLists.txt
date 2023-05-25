project(scope)			# Название проекта

add_library(${PROJECT_NAME}
	STATIC
	Scope.cpp
)
target_link_libraries(${PROJECT_NAME} hashMap)
target_include_directories(${PROJECT_NAME} PUBLIC . )

