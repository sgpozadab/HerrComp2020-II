all: pdfs

CXX=g++
OBJECTS=main-md.o md-simul.o
CXXFLAGS=-O2 -g -std=c++14

main-md.x: $(OBJECTS) particle.h
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

data.txt: main-md.x
	./$< > $@

pdfs: data.txt plots.gp
	gnuplot plots.gp



clean:
	rm -f *.o *.x *.txt *.pdf

