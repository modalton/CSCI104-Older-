
OBJ := obj/User.o obj/Set.o obj/datetime.o obj/Tweet.o 
CC = g++
LFLAGS = -Wall 




all: twitter

test: include/User.h include/Set.h include/datetime.h include/Tweet.h src/User.cpp src/Set.cpp src/datetime.cpp src/Tweet.cpp
	g++ -Wall -o src/twitter.cpp 

twitter: src/twitter.cpp  $(OBJ)
	$(CC) $(LFLAGS) -o $@ $^

obj/User.o: include/User.h
	$(CC) $(CFLAGS) -c src/User.cpp

obj/Set.o: src/Set.cpp include/Set.h include/AList.h
	$(CC) $(CFLAGS) -c $@ 

obj/datetime.o: src/datetime.cpp include/datetime.h
	$(CC) $(CFLAGS) -c $@ 

obj/Tweet.o: src/Tweet.cpp include/Tweet.h 
	$(CC) $(CFLAGS) -c $@ 	