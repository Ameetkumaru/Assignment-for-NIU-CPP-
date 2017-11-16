OPT = -std=c++11 -c -g -Wall -Wextra
OBJ = prog$N.o Date.o

prog$N.exe: ${OBJ}
	g++ -o $@ ${OBJ}

prog$N.o: prog$N.cc Date.h
	g++ ${OPT} prog$N.cc

Date.o: Date.cc Date.h
	g++ ${OPT} Date.cc

execute:
	prog$N.exe 2>&1 | tee prog$N.out

clean:
	/bin/rm -f *.o *.exe
