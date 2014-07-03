CPP_FILES := $(wildcard src/*.cpp 
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CC = g++
LFLAGS = -Wall 
CFLAGS = -Wall -c


main.exe: $(OBJ_FILES)
   g++ $(LD_FLAGS) -o $@ $^



all: twitter

twitter: $(OBJ_FILES)
	$(CC) $(LFLAGS) -o $@ $^

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -o $@ $< 