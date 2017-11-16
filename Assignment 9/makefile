OPT = -std=c++11 -c -g -Wall -Wextra

SRC = prog$N.cc
HDR = ${SRC:.cc=.h}
OBJ = ${SRC:.cc=.o}
EXE = ${SRC:.cc=.exe}

DAT1 = /home/cs689/progs/16s/p$N/prog$N.d1
DAT2 = /home/cs689/progs/16s/p$N/prog$N.d2

${EXE}: ${OBJ}
	g++ -o $@ ${OBJ}

${OBJ}: ${SRC} ${HDR}
	g++ ${OPT} ${SRC}

execute:
	${EXE} < ${DAT1} 2>&1 | tee prog$N.out1
	${EXE} < ${DAT2} 2>&1 | tee prog$N.out2

clean:
	/bin/rm -f *.o *.exe
