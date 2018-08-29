CC = gcc
CCFLAGS = -g -W -Wall -Wpedantic -std=c11

FLEX = flex
FLEX_OPTS = -PCalc

BISON = bison
BISON_OPTS = -t -pCalc

OBJS = Compiler.o Absyn.o Lexer.o Parser.o Printer.o

.PHONY: clean distclean

all: TestCalc Main

clean:
	rm -f *.o TestCalc Calc.aux Calc.log Calc.pdf Calc.dvi Calc.ps Calc

distclean: clean
	rm -f Absyn.h Absyn.c Test.c Parser.c Parser.h Lexer.c Skeleton.c Skeleton.h Printer.c Printer.h Makefile Calc.l Calc.y Calc.tex 

TestCalc: ${OBJS} Test.o
	@echo "Linking TestCalc..."
	${CC} ${CCFLAGS} ${OBJS} Test.o -o TestCalc

Main: ${OBJS} Main.o
	${CC} ${CCFLAGS} ${OBJS} Main.o -o hvm

Compiler.o: Compiler.c Compiler.h
	${CC} ${CCFLAGS} -c Compiler.c

Absyn.o: Absyn.c Absyn.h
	${CC} ${CCFLAGS} -c Absyn.c

Lexer.c: Calc.l
	${FLEX} ${FLEX_OPTS} -oLexer.c Calc.l

Parser.c: Calc.y
	${BISON} ${BISON_OPTS} Calc.y -o Parser.c

Lexer.o: Lexer.c Parser.h
	${CC} ${CCFLAGS} -c Lexer.c 

Parser.o: Parser.c Absyn.h
	${CC} ${CCFLAGS} -c Parser.c

Printer.o: Printer.c Printer.h Absyn.h
	${CC} ${CCFLAGS} -c Printer.c

Test.o: Test.c Parser.h Printer.h Absyn.h
	${CC} ${CCFLAGS} -c Test.c

