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
	int j, i = 0;
	while (i < 9){
		j = 0;
		while (j < 9){
			t[i][j] = 0;
			j++;
		}
		i++;
	}
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
	pair<int,int> result = make_pair(-1, -1);
	while (i < 9 && result.first == -1){
		j = 0;
		while (j < 9 && result.first == -1){
			if (t[i][j] == 0){
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

bool valorEnRango(int v){
	return v >= 1 && v <= 9;
}

bool sudoku_esTableroValido(Tablero t) {
	bool esTableroValido = true;
	int j, i = 0;
	while (i < 9 && esTableroValido == true){
		j = 0;
		while (j < 9 && esTableroValido == true){
			if (!valorEnRango(t[i][j])){
				esTableroValido = false;
			}
			j++;
		}
		i++;
	}
	return esTableroValido;
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

