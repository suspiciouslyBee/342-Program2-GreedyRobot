#!/bin/bash

##
# Name: June
#
# File: Robot Tester
# 
# Description: Unit Tests for Robot. Freshly compiles program and tests.
##

echo "Compile Testing (Not Scored)"

make clean
make

TESTINGSCORE=0

echo -e "Bounds Testing\n"
echo "Overflow Handle"
./greedy_robot 1 1234567890 3 4 5
if [[ $? -eq 1 ]];
then
  echo -e "\tPassed"
  TESTINGSCORE=$((TESTINGSCORE + 1))
fi

echo "Underflow Handle"
./greedy_robot 2 -3 -1234567890 2 3
if [[ $? -eq 1 ]];
then
  echo -e "\tPassed"
  TESTINGSCORE=$((TESTINGSCORE + 1))
fi

echo -e "Correctness Testing\n"

echo "(1, 2) -> (3, 5) @ 2"
if [[ $(./greedy_robot 2 1 2 3 5 | tail -n 1) == "Number of paths: 7" ]];
then
  echo -e "\tPassed"
  TESTINGSCORE=$((TESTINGSCORE + 1))
fi

echo "(1, 2) -> (3, 5) @ -2 - Inverted Max Distance Handling"
if [[ $(./greedy_robot -2 1 2 3 5 | tail -n 1) == "Number of paths: 7" ]];
then
  echo -e "\tPassed"
  TESTINGSCORE=$((TESTINGSCORE + 1))
fi

echo "(2, 3) -> (3, 3) @ 7"
if [[ $(./greedy_robot 7 2 3 3 3 | tail -n 1) == "Number of paths: 1" ]];
then
  echo -e "\tPassed"
  TESTINGSCORE=$((TESTINGSCORE + 1))
fi

echo "(3, 4) -> (4, 3) @ 2"
if [[ $(./greedy_robot 2 3 4 4 3 | tail -n 1) == "Number of paths: 2" ]];
then
  echo -e "\tPassed"
  TESTINGSCORE=$((TESTINGSCORE + 1))
fi

echo "(1, 1) -> (1, 1) @ 2 - Already Solved"
if [[ $(./greedy_robot 2 1 1 1 1 | tail -n 1) == "Number of paths: 0" ]];
then
  echo -e "\tPassed"
  TESTINGSCORE=$((TESTINGSCORE + 1))
fi

echo "(-1, 1) -> (-1, 1) @ 4 - Already Solved"
if [[ $(./greedy_robot 4 -1 1 -1 1 | tail -n 1) == "Number of paths: 0" ]];
then
  echo -e "\tPassed"
  TESTINGSCORE=$((TESTINGSCORE + 1))
fi

echo "(1, 0) -> (1, 0) @ 1 - Already Solved"
if [[ $(./greedy_robot 2 1 0 1 0 | tail -n 1) == "Number of paths: 0" ]];
then
  echo -e "\tPassed"
  TESTINGSCORE=$((TESTINGSCORE + 1))
fi

echo "(1, 1) -> (5, 1) @ 1 - Non-Solvable"
if [[ $(./greedy_robot 1 1 1 5 1 | tail -n 1) == "Number of paths: 0" ]];
then
  echo -e "\tPassed"
  TESTINGSCORE=$((TESTINGSCORE + 1))
fi

echo "(1, 1) -> (5, 1) @ 0 - Non-Solvable"
if [[ $(./greedy_robot 0 1 1 5 1 | tail -n 1) == "Number of paths: 0" ]];
then
  echo -e "\tPassed"
  TESTINGSCORE=$((TESTINGSCORE + 1))
fi

echo "(0, 0) -> (-2, -3) @ 2"
if [[ $(./greedy_robot 2 0 0 -2 -3 | tail -n 1) == "Number of paths: 7" ]];
then
  echo -e "\tPassed"
  TESTINGSCORE=$((TESTINGSCORE + 1))
fi

echo "(1, 1) -> (2, -3) @ 2"
if [[ $(./greedy_robot 2 1 1 2 -3 | tail -n 1) == "Number of paths: 1" ]];
then
  echo -e "\tPassed"
  TESTINGSCORE=$((TESTINGSCORE + 1))
fi

echo "(1, 1) -> (2, -3) @ 4"
if [[ $(./greedy_robot 4 1 1 2 -3 | tail -n 1) == "Number of paths: 5" ]];
then
  echo -e "\tPassed"
  TESTINGSCORE=$((TESTINGSCORE + 1))
fi

echo -e "(1, 2) -> (3, 5) @ 2 (repeated) - Print Check (not auto scored)"
./greedy_robot 2 1 2 3 5


echo -e "\n\nFinal Score: ${TESTINGSCORE}\n"



