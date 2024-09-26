cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("curses-text-editor")
find_package(Curses REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/headers)
add_executable (curses-text-editor "curses-text-editor.cpp" "headers/utils.h" "utils.cpp")
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET curses-text-editor PROPERTY CXX_STANDARD 20)
endif()