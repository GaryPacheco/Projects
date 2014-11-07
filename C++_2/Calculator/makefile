# Makefile for Midterm #1
# To use this makefile on Windows: mingw32-make
CXX = /usr/bin/g++
MAIN = midterm1.exe
FILE = unit_test.cpp
CXXFLAGS = -Wall

# Type 'make' to create the executable
${MAIN}: ${FILE} calculator.cpp calculator.h
	g++ ${CXXFLAGS} ${FILE} calculator.cpp -o ${MAIN}
	@echo 'Use .\${MAIN} to run'

# Clean-Up the executable
clean:
	del ${MAIN}
	
