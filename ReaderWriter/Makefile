CC ?= gcc
CXX ?= g++
CPP ?= g++

# Ejecutables
APP_NAME1 = Reader
APP_NAME2 = Writer
 
# Objetos
OBJ_1 = Reader.o
OBJ_2 = Writer.o
 
LIB_DIRS = .
 
all: $(APP_NAME1) $(APP_NAME2)
 
$(APP_NAME1): $(OBJ_1)
	$(CC) $^ -o $@ -L$(LIB_DIRS)
 
$(APP_NAME2): $(OBJ_2)
	$(CC) $^ -o $@ -L$(LIB_DIRS)
 
%.o: %.c
	$(CC) -c $^ -o $@ -g
 
clean:
	rm -f *.o $(APP_NAME1) $(APP_NAME2)
 
fresh:
	make clean
	make all
