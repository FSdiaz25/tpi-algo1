#include <iostream>
#include <vector>
#include "sudoku.h"

using namespace std;

pair<int, int> primerCeldaVacia(Tablero t) {
	pair<int, int> result = make_pair(-1, -1);
	int c, f = 0;
	while (f < 9 && result.first == -1) {
		c = 0;
		while (c < 9 && result.first == -1) {
			if (sudoku_esCeldaVacia(t, f, c)) {
				result = make_pair(f, c);
			}
			c++;
		}
		f++;
	}
	return result;
}

int cantEnFila(Tablero t, int f, int value) {
	int c = 0, count = 0;
	while (c < 9) {
		if (sudoku_valorEnCelda(t, f, c) == value) {
			count++;
		}
		c++;
	}
	return count;
}

int cantEnColumna(Tablero t, int c, int value) {
	int f = 0, count = 0;
	while (f < 9) {
		if (sudoku_valorEnCelda(t, f, c) == value) {
			count++;
		}
		f++;
	}
	return count;
}

int cantEnRegion(Tablero t, int x, int y, int value) {
	int f = 0, c = 0, count = 0;
	while (f < 3) {
		c = 0;
		while (c < 3) {
			if (sudoku_valorEnCelda(t, 3 * x + f, 3 * y + c) == value) {
				count++;
			}
			c++;
		}
		f++;
	}
	return count;
}

bool filasOk(Tablero t) {
	bool filasOk = true;
	int f = 0, c = 0;
	while (f < 9 && filasOk) {
		c = 0;
		while (c < 9 && filasOk) {
			if (!sudoku_esCeldaVacia(t, f, c) && cantEnFila(t, f, sudoku_valorEnCelda(t, f, c)) != 1) {
				filasOk = false;
			}
			c++;
		}
		f++;
	}
	return filasOk;
}

bool columnasOk(Tablero t) {
	int c = 0;
	bool columnasOk = true;
	while (c < 9 && columnasOk) {
		int f = 0;
		while (f < 9 && columnasOk) {
			if (!sudoku_esCeldaVacia(t, f, c) && cantEnColumna(t, c, sudoku_valorEnCelda(t, f, c)) != 1) {
				columnasOk = false;
			}
			f++;
		}
		c++;
	}
	return columnasOk;
}

bool regionValida(Tablero t, int x, int y) {
	bool regionValida = true;
	int f = 0, c = 0;
	while (f < 3 && regionValida) {
		c = 0;
		while (c < 3 && regionValida) {
			if (!sudoku_esCeldaVacia(t, 3 * x + f, 3 * y + c) && cantEnRegion(t, x, y, sudoku_valorEnCelda(t, 3 * x + f, 3 * y + c)) != 1) {
				regionValida = false;
			}
			c++;
		}
		f++;
	}
	return regionValida;
}

bool regionesOk(Tablero t) {
	bool result = true;
	int f = 0;
	while (f < 3 && result) {
		int c = 0;
		while (c < 3 && result) {
			if (!regionValida(t, f, c)) {
				result = false;
			}
			c++;
		}
		f++;
	}
	return result;
}
