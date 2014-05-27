#######################################################
#
#    Aland Sailing Robot
#    ===========================================
#    servocontroller
#    -------------------------------------------
#
#######################################################

CC = g++
FLAGS = -pedantic
LIBS =

SOURCES_MAESTRO = MaestroController.cpp
HEADERS_MAESTRO = MaestroController.h
FILE_MAESTRO = MaestroController.o

SOURCES_SERVO = ServoObject.cpp
HEADERS_SERVO = ServoObject.h
FILE_SERVO = ServoObject.o

SOURCES_SENSOR = SensorObject.cpp
HEADERS_SENSOR = SensorObject.h
FILE_SENSOR = SensorObject.o

HEADERS = $(HEADERS_MAESTRO) $(HEADERS_SERVO) $(HEADERS_SENSOR)
SOURCES = $(SOURCES_MAESTRO) $(SOURCES_SERVO) $(SOURCES_SENSOR)

all : $(FILE_MAESTRO) $(FILE_SERVO)

$(FILE_MAESTRO) : $(SOURCES_MAESTRO) $(HEADERS_MAESTRO)
	$(CC) $(SOURCES_MAESTRO) $(FLAGS) $(LIBS) -c -o $(FILE_MAESTRO)

$(FILE_SERVO) : $(SOURCES_SERVO) $(HEADERS_SERVO)
	$(CC) $(SOURCES_SERVO) $(FLAGS) $(LIBS) -c -o $(FILE_SERVO)

$(FILE_SENSOR) : $(SOURCES_SENSOR) $(HEADERS_SENSOR)
	$(CC) $(SOURCES_SENSOR) $(FLAGS) $(LIBS) -c -o $(FILE_SERVO)

example : $(SOURCES) $(HEADERS)
	$(CC) $(SOURCES) example.cpp $(FLAGS) $(LIBS) -o example

