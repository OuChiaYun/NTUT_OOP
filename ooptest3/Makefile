.PHONY: directories clean stat

all: directories bin/ut_all

bin/ut_all: test/ut_main.cpp test/ut_drink.h src/drink.h
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -pthread --coverage -fkeep-inline-functions -fno-inline -fno-inline-small-functions -fno-default-inline -g -O0

directories:
	mkdir -p bin

clean:
	rm -rf bin

stat:
	wc src/* test/*
