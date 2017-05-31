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
	return t[f][c] == 0;
}

void sudoku_vaciarTablero(Tablero t) {
	// COMPLETAR
}

int sudoku_nroDeCeldasVacias(Tablero t) {
	int j, i = 0, count = 0;
	while (i < 9){
		j = 0;
		while (j < 9){
			if (t[i][j] == 0){
				count++;
			}
			j++;
		}
		i++;
	}
	return count;
}

pair<int,int> primerCeldaVacia(Tablero t) {
	int j, i = 0;
	bool pairFound = false;
	pair<int,int> result = make_pair(-1, -1);
	while (i < 9 && pairFound == false){
		j = 0;
		while (j < 9 && pairFound == false){
			if (t[i][j] == 0){
				result = make_pair(i, j);
				pairFound = true;
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

