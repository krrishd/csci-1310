main: main.cpp Startup.o IntellectualProperty.o Employee.o
	g++ -std=c++11 -o main main.cpp Startup.o IntellectualProperty.o Employee.o

Startup.o: Startup.h Startup.cpp
	g++ -c Startup.cpp

IntellectualProperty.o: IntellectualProperty.h IntellectualProperty.cpp
	g++ -c IntellectualProperty.cpp

Employee.o: Employee.h Employee.cpp
	g++ -c Employee.cpp
