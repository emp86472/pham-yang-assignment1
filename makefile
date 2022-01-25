compile:
	g++ -c -Wall -pedantic-errors Student.cpp
	g++ -c -Wall -pedantic-errors Instructor.cpp
	g++ -c -Wall -pedantic-errors main.cpp

link: compile
	g++ -o main Instructor.o Student.o main.o

run: link
	./main instructors.txt students.txt

clean:
	rm -f main main.o Instructor.o Student.o
