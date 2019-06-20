cmake_minimum_required(VERSION 2.6)
project(frand)
add_executable(frand main.cpp)

include_directories("lib")

find_package(Boost REQUIRED COMPONENTS filesystem)
if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
	target_link_libraries(frand Boost::filesystem)
endif()

install(TARGETS frand DESTINATION bin)
