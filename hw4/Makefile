
OBJ = obj/User.o obj/datetime.o obj/Tweet.o 
CC = g++
CPPFLAGS = -Wall 
HEADER_DIR = include/



all: twitter

test: include/User.h include/Set.h include/datetime.h include/Tweet.h src/User.cpp include/Set.cpp src/datetime.cpp src/Tweet.cpp
	g++ -Wall -o src/twitter.cpp 

twitter: src/twitter.cpp include/AList.h include/AListImpl.h include/Set.h include/SetImpl.h $(OBJ)
	$(CC) $(CPPLAGS) -o $@ $^ -I $(HEADER_DIR)

obj/User.o: src/User.cpp include/User.h
	$(CC) $(CPPLAGS) -c -o $@ $< -I $(HEADER_DIR)

obj/datetime.o: src/datetime.cpp include/datetime.h
	$(CC) $(CPPLAGS) -c -o $@ $< -I $(HEADER_DIR)

obj/Tweet.o: src/Tweet.cpp include/Tweet.h
	$(CC) $(CPPLAGS) -c -o $@ $< -I $(HEADER_DIR)

