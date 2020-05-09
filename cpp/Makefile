stimer: stimer.o Timer.o LN5644.o Arduino.o
	g++ -o stimer stimer.o Timer.o LN5644.o Arduino.o

stimer.o: stimer.cpp
	g++ -c stimer.cpp

Timer.o: Timer.cpp
	g++ -c Timer.cpp

LN5644.o: LN5644.cpp
	g++ -c LN5644.cpp

Arduino.o: Arduino.cpp
	g++ -c Arduino.cpp

clean:
	rm *.o
