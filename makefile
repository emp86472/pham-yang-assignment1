compile:
	g++ -c -Wall -pedantic-errors Student.cpp
	g++ -c -Wall -pedantic-errors Instructor.cpp
	g++ -c -Wall -pedantic-errors Main.cpp

link:
	g++ -o main Instructor.o Student.o main.o

run:
	./main

clean:
	rm -f main main.o Instructor.o Student.o
