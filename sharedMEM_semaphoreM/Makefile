# Ejecutables
APP_NAME1 = shm_readr
APP_NAME2 = shm_writer
 
# Objetos
OBJ_1 = shm_reader.o
OBJ_2 = shm_writer.o
 
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
