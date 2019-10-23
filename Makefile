CFLAGS = -O
CC = g++
SRC = main.cpp
OBJ = $(SRC:.cpp = .o)
theoldones: $(OBJ)
	$(CC) $(CFLAGS) -o bin/theoldones $(OBJ)
clean:
	rm -f core *.o 
