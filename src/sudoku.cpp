#include <iostream>
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
	// COMPLETAR
	return false;
}
void sudoku_vaciarTablero(Tablero t) {
	// COMPLETAR
}

int sudoku_nroDeCeldasVacias(Tablero t) {
	// COMPLETAR
	return -1;
}

int sudoku_primerCeldaVaciaFila(Tablero t) {
	// COMPLETAR
	return -1;
}

int sudoku_primerCeldaVaciaColumna(Tablero t) {
	// COMPLETAR
	return -1;
}

int sudoku_valorEnCelda(Tablero t, int f, int c) {
	// COMPLETAR
	return -1;
}

void sudoku_llenarCelda(Tablero t, int f, int c, int v) {
	// COMPLETAR
}

void sudoku_vaciarCelda(Tablero t, int f, int c) {
	// COMPLETAR
}

bool sudoku_esTableroValido(Tablero t) {
	// COMPLETAR
	return false;
}

bool sudoku_esTableroParcialmenteResuelto(Tablero t) {
	// COMPLETAR
	return false;
}

bool sudoku_esTableroTotalmenteResuelto(Tablero t) {
	// COMPLETAR
	return false;
}

bool sudoku_esSubTablero(Tablero t0, Tablero t1) {
	// COMPLETAR
	return false;
}


bool sudoku_resolver(Tablero t) {
	// COMPLETAR
	return false;
}

bool sudoku_resolver(Tablero t, int& count) {
	// COMPLETAR
	return false;
}

