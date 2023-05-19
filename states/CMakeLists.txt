project(states)			# Название проекта

add_library(${PROJECT_NAME}
	STATIC
    StartState.cpp
    CommentState.cpp
    IdentifierState.cpp
    KeywordStates.cpp
    NumberState.cpp
    OperatorStates.cpp
    StringState.cpp
    ERRORState.cpp
)

target_link_libraries(${PROJECT_NAME} builder context)
target_include_directories(${PROJECT_NAME} PUBLIC . )
