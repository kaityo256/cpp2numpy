all: a.out

a.out: test.cc
	g++ -std=c++11 test.cc
