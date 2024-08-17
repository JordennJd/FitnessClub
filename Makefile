TARGET = FitnessClub
CC = g++

PREF_SRC = $(wildcard ./src/***/Implementation/*.cpp) PREF_SRC = $(wildcard ./src/***/**/Implementation/*.cpp) 
PREF_OBJ = ./bin/

SRC = $(wildcard $(PREF_SRC)*.cpp)
OBJ = $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(SRC))

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o: $(PREF_SRC)
	$(CC) -c $< -o $@