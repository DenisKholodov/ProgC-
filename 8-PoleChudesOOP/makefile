all: main.exe run

main.exe: WhillWithDividedClass.o Round.o Word.o
	g++ WhillWithDividedClass.o Round.o Word.o -o main.exe

WhillWithDividedClass.o: WhillWithDividedClass.cpp
	g++ -c WhillWithDividedClass.cpp -o WhillWithDividedClass.o

Round.o: Round.cpp
	g++ -c Round.cpp -o Round.o

Node.o: Word.cpp
	g++ -c Word.cpp -o Word.o

run: main.exe
	./main.exe


clean:
	rm -rf *.o main