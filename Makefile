all:
	g++ -lglut -lGL -lGLU -lGLEW basic.cpp -g -o basic  
	./basic < co2.txt
