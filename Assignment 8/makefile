OPT = -std=c++11 -c -g -Wall -Wextra
DAT = /home/cs689/progs/16s/p$N/prog$N.d
OBJ = prog$N.o Rational.o

prog$N.exe: ${OBJ}
	g++ -o $@ ${OBJ}

prog$N.o: prog$N.cc Rational.h
	g++ ${OPT} prog$N.cc

Rational.o: Rational.cc Rational.h
	g++ ${OPT} Rational.cc

execute:
	prog$N.exe < ${DAT} 2>&1 | tee prog$N.out

clean:
	/bin/rm -f *.o *.exe
