OPT = -std=c++11 -c -g -Wall -Wextra
DIR = /home/cs689/progs/16s/p$N
DAT = ${DIR}/prog$N.d
OBJ = prog$N.o Date.o

prog$N.exe: ${OBJ}
	g++ -o $@ ${OBJ}

prog$N.o: prog$N.cc Date.h
	g++ ${OPT} prog$N.cc

Date.o: Date.cc Date.h
	g++ ${OPT} Date.cc

execute:
	prog$N.exe < ${DAT} 2>&1 | tee prog$N.out

clean:
	/bin/rm -f *.o *.exe
