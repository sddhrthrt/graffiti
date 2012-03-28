all:
	g++ -lglut -lGL -lGLU -lGLEW basic.cpp -g -o basic  
	./basic < data/co2.txt
