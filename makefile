all: a.out

a.out: test.cc
	g++ -std=c++11 test.cc


test: a.out
	./a.out
	python3 load.py

clean:
	rm -f *.dat a.out
