# Makefile to help automate testing/debugging
# 
# Author: June

CXX=g++
OBJ=point.o robot.o main.o
CXXFLAGS=

all: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o greedy_robot
	chmod +x greedy_robot

debug: CXXFLAGS=-g
debug: $(OBJ)
	echo "debug compile..."
	$(CXX) $(CXXFLAGS) $^ -o greedy_robot
	chmod +x greedy_robot

clean :
	rm *.o *.c greedy_robot

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $^ -o $@

