BIN = bin
OBJ = obj
SRC = src
INCLUDE = include
LIB = lib
CPPFLAGS = -I$(INCLUDE) -std=c++11 -Wall -g 

.PHONY: doc all clean distclean zip valgrind

all:$(BIN)/tsp

# Creamos los ejecutables
$(BIN)/tsp: $(SRC)/main.cpp $(OBJ)/Solucion.o $(OBJ)/Problema.o $(OBJ)/Punto.o
	g++ -o $@ $^ $(CPPFLAGS) 

# Creamos los objetos
$(OBJ)/Problema.o: $(SRC)/Problema.cpp
	g++ -c $(CPPFLAGS) -o $@ $<

$(OBJ)/Solucion.o: $(SRC)/Solucion.cpp
	g++ -c $(CPPFLAGS) -o $@ $<

$(OBJ)/Punto.o: $(SRC)/Punto.cpp 
	g++ -c $(CPPFLAGS) -o $@ $< 

doc: 
	doxygen doc/Doxyfile
	
# Creamos el dstino clean que elimina objeto, librerias y ejecutables previos
clean:
	@echo Borrando...
	-rm $(OBJ)/*
	@echo Objetos borrados.

distclean: clean
	-rm $(LIB)/*
	@echo Librerias borradas.
	-rm $(BIN)/*
	@echo Ejecutables borrados.
	-rm codigoP4.zip
	@echo Zip borrado
	-rm -r doc/html doc/rtf
	@echo documentacion borrada
	
zip: distclean
	zip -v9r codigoP4.zip *
	
valgrind: $(BIN)/tsp 
	valgrind --leak-check=full --track-origins=yes $(BIN)/tsp c10.tsp
	@echo
	@echo
