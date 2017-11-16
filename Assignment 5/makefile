OPT = -std=c++11 -c -g -Wall -Wextra
DAT = /home/cs689/progs/16s/p$N/prog$N.d

prog$N.exe: prog$N.o
	g++ -o $@ prog$N.o

prog$N.o: prog$N.cc prog$N.h
	g++ ${OPT} prog$N.cc

execute:
	prog$N.exe < ${DAT} 2>&1 | tee prog$N.out

clean:
	/bin/rm -f *.o *.exe
