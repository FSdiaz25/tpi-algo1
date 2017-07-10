#include <iostream>
#include <vector>
#include "sudoku.h"
#include "auxiliares.h"

using namespace std;

void sudoku_print(Tablero t) {
	cout << "-------------------";
	cout << endl;
	for (int i = 0; i < 9; i++) {
		cout << "|";
		for (int j = 0; j < 9; j++) {
			if (t[i][j] == 0) {
				cout << " ";
			} else {
				cout << t[i][j];
			}
			cout << "|";
		}
		cout << endl;
		if (i == 8) {
			cout << "+-+-+-+-+-+-+-+-+-+";
		} else {
			cout << "-------------------";
		}
		cout << endl;
	}
}

int sudoku_valorEnCelda(Tablero t, int f, int c) {
	return t[f][c];
}

void sudoku_llenarCelda(Tablero t, int f, int c, int v) {
	t[f][c] = v;
}

void sudoku_vaciarCelda(Tablero t, int f, int c) {
	sudoku_llenarCelda(t, f, c, 0);
}

bool sudoku_esCeldaVacia(Tablero t, int f, int c) {
	return sudoku_valorEnCelda(t, f, c) == 0;
}

void sudoku_vaciarTablero(Tablero t) {
	int c, f = 0;
	while (f < 9) {
		c = 0;
		while (c < 9) {
			sudoku_llenarCelda(t, f, c, 0);
			c++;
		}
		f++;
	}
}

int sudoku_nroDeCeldasVacias(Tablero t) {
	int c, f = 0, count = 0;
	while (f < 9) {
		c = 0;
		while (c < 9) {
			if (sudoku_esCeldaVacia(t, f, c)) {
				count++;
			}
			c++;
		}
		f++;
	}
	return count;
}

int sudoku_primerCeldaVaciaFila(Tablero t) {
	return primerCeldaVacia(t).first;
}

int sudoku_primerCeldaVaciaColumna(Tablero t) {
	return primerCeldaVacia(t).second;
}

bool sudoku_esTableroValido(Tablero t) {
	bool esTableroValido = true;
	int c, f = 0, valorCelda;
	while (f < 9 && esTableroValido) {
		c = 0;
		while (c < 9 && esTableroValido) {
			valorCelda = sudoku_valorEnCelda(t, f, c);
			if (valorCelda < 0 || valorCelda > 9) {
				esTableroValido = false;
			}
			c++;
		}
		f++;
	}
	return esTableroValido;
}

bool sudoku_esTableroParcialmenteResuelto(Tablero t) {
	return sudoku_esTableroValido(t) && filasOk(t) && columnasOk(t)	&& regionesOk(t);
}

bool sudoku_esTableroTotalmenteResuelto(Tablero t) {
	return sudoku_esTableroParcialmenteResuelto(t) && sudoku_nroDeCeldasVacias(t) == 0;
}

bool sudoku_esSubTablero(Tablero t0, Tablero t1) {
	bool result = true;
	int c, f = 0;
	while (f < 9 && result) {
		c = 0;
		while (c < 9 && result) {
			if (sudoku_valorEnCelda(t0, f, c) != 0 && sudoku_valorEnCelda(t0, f, c) != sudoku_valorEnCelda(t1, f, c)) {
				result = false;
			}
			c++;
		}
		f++;
	}
	return result;
}

void sudoku_copiarTablero(Tablero src, Tablero target) {
	int c, f = 0;
	while (f < 9) {
		c = 0;
		while (c < 9) {
			sudoku_llenarCelda(target, f, c, sudoku_valorEnCelda(src, f, c));
			c++;
		}
		f++;
	}
}

bool sudoku_resolver(Tablero t) {
	int count = 0;
	return sudoku_resolver(t, count);
}

bool sudoku_resolver(Tablero t, int& count) {
	int f = 0, c = 0;
	bool tieneSolucion = true;
	vector<pair<int, int> > path;
	count = 0;

	Tablero t0;
	sudoku_copiarTablero(t, t0);

	while (f < 9 && tieneSolucion == true) {
		c = 0;
		while (c < 9 && tieneSolucion == true) {
			if (t0[f][c] == 0) {

				// Iteramos hasta encontrar un valor valido para la celda.
				int initialValue = t[f][c];
				int k = initialValue + 1;
				while (k <= 9 && t[f][c] == initialValue) {
					t[f][c] = k;
					count++;
					if (!sudoku_esTableroParcialmenteResuelto(t)) {
						t[f][c] = initialValue;
						count++;
					}
					k++;
				}

				if (t[f][c] == initialValue) {
					// Volvemos un paso atras siempre y cuando sea posible.
					if (path.size() > 0) {
						t[f][c] = 0;
						count++;
						f = path[path.size() - 1].first;
						c = path[path.size() - 1].second - 1;
						path.pop_back();
					} else {
						tieneSolucion = false;
					}
				} else {
					path.push_back(make_pair(f, c));
				}
			}
			c++;
		}
		f++;
	}
	return tieneSolucion;
}


// Auxiliares

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

