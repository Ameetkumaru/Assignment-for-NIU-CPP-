OPT =-std=c++11 -c -g -Wall -Wextra
D1=/home/cs689/progs/16s/p3/$T.d1

$T.exe:$T.o
	g++ -o $@ $T.o
	
$T.o: $T.cc $T.h
	g++ ${OPT} $T.cc

execute:
	$T.exe<${D1} 2>&1 | tee $T.out
	
clean:
	/bin/rm -f *.o *.exe
