AddTwoNumbersAsLists: AddTwoNumbersAsLists.o
	g++ -g -o AddTwoNumbersAsLists.exe AddTwoNumbersAsLists.o -pthread    

AddTwoNumbersAsLists.o: AddTwoNumbersAsLists/AddTwoNumbersAsLists.cpp
	g++ -g  -c -pthread AddTwoNumbersAsLists/AddTwoNumbersAsLists.cpp
