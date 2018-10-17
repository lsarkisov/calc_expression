all:
	g++ -Wall -Wpedantic -std=c++17 -g main.cpp -o build/main

run:
	./build/main
