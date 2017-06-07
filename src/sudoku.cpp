#include <iostream>
#include <vector>
#include "sudoku.h"

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

bool sudoku_esCeldaVacia(Tablero t, int f, int c) {
	return t[f][c] == 0;
}

void sudoku_vaciarTablero(Tablero t) {
	int j, i = 0;
	while (i < 9) {
		j = 0;
		while (j < 9) {
			t[i][j] = 0;
			j++;
		}
		i++;
	}
}

int sudoku_nroDeCeldasVacias(Tablero t) {
	int j, i = 0, count = 0;
	while (i < 9) {
		j = 0;
		while (j < 9) {
			if (t[i][j] == 0) {
				count++;
			}
			j++;
		}
		i++;
	}
	return count;
}

pair<int, int> primerCeldaVacia(Tablero t) {
	int j, i = 0;
	pair<int, int> result = make_pair(-1, -1);
	while (i < 9 && result.first == -1) {
		j = 0;
		while (j < 9 && result.first == -1) {
			if (t[i][j] == 0) {
				result = make_pair(i, j);
			}
			j++;
		}
		i++;
	}
	return result;
}

int sudoku_primerCeldaVaciaFila(Tablero t) {
	return primerCeldaVacia(t).first;
}

int sudoku_primerCeldaVaciaColumna(Tablero t) {
	return primerCeldaVacia(t).second;
}

int sudoku_valorEnCelda(Tablero t, int f, int c) {
	return t[f][c];
}

void sudoku_llenarCelda(Tablero t, int f, int c, int v) {
	t[f][c] = v;
}

void sudoku_vaciarCelda(Tablero t, int f, int c) {
	t[f][c] = 0;
}

bool valorEnRango(int v) {
	return v >= 0 && v <= 9;
}

bool sudoku_esTableroValido(Tablero t) {
	bool esTableroValido = true;
	int j, i = 0;
	while (i < 9 && esTableroValido) {
		j = 0;
		while (j < 9 && esTableroValido) {
			if (!valorEnRango(t[i][j])) {
				esTableroValido = false;
			}
			j++;
		}
		i++;
	}
	return esTableroValido;
}

int cantEnFila(Tablero t, int f, int value) {
	int c = 0;
	int count = 0;

	while (c < 9) {
		if (t[f][c] == value)
			count++;
		c++;
	}

	return count;
}

bool filasOk(Tablero t) {
	int i = 0;
	bool result = true;

	while (i < 9 && result) {
		int j = 0;
		while (j < 9 && result) {
			if (t[i][j] != 0 && cantEnFila(t, i, t[i][j]) != 1)
				result = false;
			j++;
		}
		i++;
	}
	return result;
}

int cantEnColumna(Tablero t, int c, int value) {
	int f = 0;
	int count = 0;

	while (f < 9) {
		if (t[f][c] == value)
			count++;
		f++;
	}

	return count;
}

bool columnasOk(Tablero t) {
	int j = 0;
	bool result = true;

	while (j < 9 && result) {
		int i = 0;
		while (i < 9 && result) {
			if (t[i][j] != 0 && cantEnColumna(t, j, t[i][j]) != 1)
				result = false;
			i++;
		}
		j++;
	}
	return result;
}
int cantEnRegion(Tablero t, int x, int y, int value) {
	int f = 0;
	int count = 0;

	while (f < 3) {
		int c = 0;
		while (c < 3) {
			if (t[3 * x + f][3 * y + c] == value)
				count++;
			c++;
		}
		f++;
	}

	return count;
}
bool regionValida(Tablero t, int x, int y) {
	int f = 0;
	bool result = true;

	while (f < 3 && result) {
		int c = 0;
		while (c < 3 && result) {
			if (t[3 * x + f][3 * y + c] != 0 && cantEnRegion(t, x, y,
					t[3 * x + f][3 * y + c]) != 1)
				result = false;
			c++;
		}
		f++;
	}
	return result;
}

bool regionesOk(Tablero t) {
	int x = 0;
	bool result = true;

	while (x < 3 && result) {
		int y = 0;
		while (y < 3 && result) {
			if (!regionValida(t, x, y))
				result = false;
			y++;
		}
		x++;
	}
	return result;
}

bool sudoku_esTableroParcialmenteResuelto(Tablero t) {
	bool res;

	if (!sudoku_esTableroValido(t))
		res = false;
	else
		res = filasOk(t) && columnasOk(t) && regionesOk(t);

	return res;
}

bool sudoku_esTableroTotalmenteResuelto(Tablero t) {
	return sudoku_esTableroParcialmenteResuelto(t) && sudoku_nroDeCeldasVacias(
			t) == 0;
}

bool sudoku_esSubTablero(Tablero t0, Tablero t1) {
	int f = 0;
	bool result = true;

	while (f < 9 && result) {
		int c = 0;
		while (c < 9 && result) {
			if (t0[f][c] != t1[f][c] && t0[f][c] != 0)
				result = false;
			c++;
		}
		f++;
	}
	return result;
}

void sudoku_copiarTablero(Tablero src, Tablero target) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			target[i][j] = src[i][j];
		}
	}
}

bool sudoku_resolver(Tablero t) {
	int count = 0;
	return sudoku_resolver(t, count);
}

bool sudoku_resolver(Tablero t, int& count) {

	int i = 0, j = 0;
	bool tieneSolucion = true;
	vector<pair<int, int> > path;
	count = 0;

	Tablero t0;
	sudoku_copiarTablero(t, t0);

	while (i < 9 && tieneSolucion == true) {
		j = 0;
		while (j < 9 && tieneSolucion == true) {
			if (t0[i][j] == 0) {

				// Iteramos hasta encontrar un valor valido para la celda.
				int initialValue = t[i][j];
				int k = initialValue + 1;
				while (k <= 9 && t[i][j] == initialValue) {
					t[i][j] = k;
					count++;
					if (!sudoku_esTableroParcialmenteResuelto(t)) {
						t[i][j] = initialValue;
						count++;
					}
					k++;
				}

				if (t[i][j] == initialValue) {
					// Volvemos un paso atras siempre y cuando sea posible.
					if (path.size() > 0) {
						t[i][j] = 0;
						count++;
						i = path[path.size() - 1].first;
						j = path[path.size() - 1].second - 1;
						if (i == 8) {
							i--;
						}
						path.pop_back();
					} else {
						tieneSolucion = false;
					}
				} else {
					path.push_back(make_pair(i, j));
				}
			}
			j++;
		}
		i++;
	}
	return tieneSolucion;
}

