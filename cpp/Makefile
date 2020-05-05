ln5644: main.o Timer.o LN5644.o Arduino.o
	gcc -o ln5644 main.o Timer.o LN5644.o Arduino.o

main.o: main.cpp
	gcc -c main.cpp

Timer.o: Timer.cpp
	gcc -c Timer.cpp

LN5644.o: LN5644.cpp
	gcc -c LN5644.cpp

Arduino.o: Arduino.cpp
	gcc -c Arduino.cpp

clean:
	rm *.o
