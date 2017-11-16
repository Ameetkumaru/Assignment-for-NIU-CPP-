OPT = -std=c++11 -c -g -Wall -Wextra
DRV = /home/cs689/progs/16s/p$N/prog$N.cc

SRC1 = ${DRV}
OBJ1 = prog$N.o

SRC2 = Shape2.cc Shape3.cc
OBJ2 = ${SRC2:.cc=.o}

SRC = ${SRC1} ${SRC2}
OBJ = ${OBJ1} ${OBJ2}
EXE = ${OBJ1:.o=.exe}
OUT = ${OBJ1:.o=.out}

${EXE}: ${OBJ}
	g++ -o $@ ${OBJ}

${OBJ1}: ${SRC1}
	g++ ${OPT} ${SRC1}

Shape2.o: Shape2.cc
	g++ ${OPT} Shape2.cc

Shape3.o: Shape3.cc
	g++ ${OPT} Shape3.cc

execute:
	${EXE} 2>&1 | tee ${OUT}

clean:
	/bin/rm -f *.o *.exe
