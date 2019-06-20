CXX = c++
all:
	${CXX} -std=c++17 -I /usr/local/include/ -L /usr/local/lib -lboost_filesystem -O2 main.cpp
