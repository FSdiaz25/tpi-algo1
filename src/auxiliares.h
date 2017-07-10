#include <iostream>
#include <vector>

using namespace std;

pair<int, int> primerCeldaVacia(Tablero t);
int cantEnFila(Tablero t, int f, int value);
int cantEnColumna(Tablero t, int c, int value);
int cantEnRegion(Tablero t, int x, int y, int value);
bool filasOk(Tablero t);
bool columnasOk(Tablero t);
bool regionValida(Tablero t, int x, int y);
bool regionesOk(Tablero t);
