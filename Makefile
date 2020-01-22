CXX = g++-5
CXXFLAGS = -std=c++14
OBJECTS = main.o Block.o Board.o cell.o iblock.o jblock.o tblock.o sblock.o zblock.o lblock.o oblock.o singleblock.o Level.o LevelZero.o player.o subject.o textdisplay.o LevelOne.o LevelTwo.o LevelThree.o LevelFour.o Printer.o exception.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = biquadris

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	-rm *.o quadris
