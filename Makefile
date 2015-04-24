#######################################################
#
#    Aland Sailing Robot
#    ===========================================
#    servocontroller
#    -------------------------------------------
#
#######################################################

CC = g++
FLAGS = -pedantic -std=c++14
LIBS =

SOURCES_MAESTRO = MaestroController.cpp
HEADERS_MAESTRO = MaestroController.h
FILE_MAESTRO = MaestroController.o

SOURCES_MOCK = MockMaestroController.cpp
HEADERS_MOCK = MockMaestroController.h
FILE_MOCK = MockMaestroController.o

SOURCES_SERVO = ServoObject.cpp
HEADERS_SERVO = ServoObject.h
FILE_SERVO = ServoObject.o

SOURCES_SENSOR = SensorObject.cpp
HEADERS_SENSOR = SensorObject.h
FILE_SENSOR = SensorObject.o

HEADERS = $(HEADERS_MAESTRO) $(HEADERS_SERVO) $(HEADERS_SENSOR) $(HEADERS_MOCK)
SOURCES = $(SOURCES_MAESTRO) $(SOURCES_SERVO) $(SOURCES_SENSOR) $(SOURCES_MOCK)

all : $(FILE_MAESTRO) $(FILE_SERVO) $(FILE_SENSOR) $(FILE_MOCK)

$(FILE_MAESTRO) : $(SOURCES_MAESTRO) $(HEADERS_MAESTRO)
	$(CC) $(SOURCES_MAESTRO) $(FLAGS) $(LIBS) -c -o $(FILE_MAESTRO)

$(FILE_MOCK) : $(SOURCES_MOCK) $(HEADERS_MOCK)
	$(CC) $(SOURCES_MOCK) $(FLAGS) $(LIBS) -c -o $(FILE_MOCK)
	
$(FILE_SERVO) : $(SOURCES_SERVO) $(HEADERS_SERVO)
	$(CC) $(SOURCES_SERVO) $(FLAGS) $(LIBS) -c -o $(FILE_SERVO)

$(FILE_SENSOR) : $(SOURCES_SENSOR) $(HEADERS_SENSOR)
	$(CC) $(SOURCES_SENSOR) $(FLAGS) $(LIBS) -c -o $(FILE_SENSOR)

example : $(SOURCES) $(HEADERS)
	$(CC) $(SOURCES) example.cpp $(FLAGS) $(LIBS) -o example

clean :
	rm -f $(FILE_MAESTRO) $(FILE_SERVO) $(FILE_SENSOR) $(FILE_MOCK)
	rm -f example
