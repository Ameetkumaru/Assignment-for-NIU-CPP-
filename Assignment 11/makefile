OPT = -std=c++11 -c -g -Wall -Wextra

SRC = prog$N.cc
HDR = ${SRC:.cc=.h}
OBJ = ${SRC:.cc=.o}
EXE = ${SRC:.cc=.exe}

${EXE}: ${OBJ}
	g++ -o $@ ${OBJ}

${OBJ}: ${SRC} ${HDR}
	g++ ${OPT} ${SRC}

execute:
	${EXE} 2>&1 | tee prog$N.out

clean:
	/bin/rm -f *.o *.exe
