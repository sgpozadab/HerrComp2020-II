# comentario
# all: sumas.x datos.txt  originalmente sería así pero datos.x depende de sumas.x entonces no es necesario
# @: target
# ^: todas las dep
# <: la primera dep
# %: cuando se repita la misma instruccion

all: datos.txt

sumas.x: sumas.cpp
	g++ sumas.cpp -o sumas.x

#sumas.x: sumas.cpp
#	g++ $< -o $@

datos.txt: sumas.x
	./sumas.x > datos.txt

clean:
	rm -f a.out *.x datos.txt
