all:
	g++ -lglut -lGL -lGLU -lGLEW basic.cpp -o basic  
	./basic < co2.txt
