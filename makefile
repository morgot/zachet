objects = main.o common.o

zac : $(objects)
	g++ $(objects) -o zac

main.o : main.cpp
	g++ -c main.cpp

common.o : common.cpp
	g++ -c common.cpp

clean :
	rm $(objects) zac