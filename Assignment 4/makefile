OPT = -std=c++11 -c -g -Wall -Wextra

prog$N-out.exe: prog$N-out.o
	g++ -o $@ prog$N-out.o

prog$N-out.o:prog$N-out.cc
	g++ ${OPT} prog$N-out.cc
	
prog$N-out.cc:prog$N.exe
	prog$N.exe | tee prog$N-out.cc

prog$N.exe: prog$N.o
	g++ -o $@ prog$N.o
	
prog$N.o:prog$N.cc prog$N.cc
	g++ ${OPT} prog$N.cc

execute:
	prog$N-out.exe | tee prog$N-out.out

clean:
	/bin/rm -f *.o *.exe
