CXX = g++
CXXFLAGS = -std=c++14 -Werror -Wall -MMD
OBJECTS = object.o grid.o room.o robot.o main.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = robotRoomCleaner

default : ${EXEC}

debug: CXXFLAGS += -DDEBUG -g
debug: ${EXEC}

${EXEC}: ${OBJECTS}
				${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm *.o *.d ${EXEC}
