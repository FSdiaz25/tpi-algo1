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
	int f = 0, c = 0;
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
	int f = 0, c = 0, count = 0;
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
	int f = 0, c = 0, valorCelda;
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
	int f = 0, c = 0;
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
	int f = 0, c = 0;
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
