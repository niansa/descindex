.PHONY: build bindir clean

build: bindir
	$(CXX) -std=c++17 -l fmt -o bin/descindex src/*.cpp

bindir:
	mkdir -p bin

clean:
	rm -rf bin
