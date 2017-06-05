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
	return v >= 0 && v <= 9;
}

bool sudoku_esTableroValido(Tablero t) {
	bool esTableroValido = true;
	int j, i = 0;
	while (i < 9 && esTableroValido){
		j = 0;
		while (j < 9 && esTableroValido){
			if (!valorEnRango(t[i][j])){
				esTableroValido = false;
			}
			j++;
		}
		i++;
	}
	return esTableroValido;
}

int cantEnFila(Tablero t, int f, int value){
	int c = 0;
	int count = 0;

	while(c < 9){
		if(t[f][c] == value)
			count++;
		c++;
	}

	return count;
}

bool filasOk(Tablero t){
	int i = 0;
	bool result = true;

	while(i < 9 && result){
		int j = 0;
		while(j < 9 && result){
			if(t[i][j] != 0 && cantEnFila(t, i, t[i][j]) != 1)
				result = false;
			j++;
		}
		i++;
	}
	return result;
}

int cantEnColumna(Tablero t, int c, int value){
	int f = 0;
	int count = 0;

	while(f < 9){
		if(t[f][c] == value)
			count++;
		f++;
	}

	return count;
}


bool columnasOk(Tablero t){
	int j = 0;
	bool result = true;

	while(j < 9 && result){
		int i = 0;
		while(i < 9 && result){
			if(t[i][j] != 0 && cantEnColumna(t, j, t[i][j]) != 1)
				result = false;
			i++;
		}
		j++;
	}
	return result;
}
int cantEnRegion(Tablero t, int x, int y, int value){
	int f = 0;
	int count = 0;

	while(f < 3){
		int c = 0;
		while(c < 3){
			if(t[3*x + f][3*y + c] == value)
				count++;
			c++;
		}
		f++;
	}

	return count;
}
bool regionValida(Tablero t, int x, int y){
	int f = 0;
	bool result = true;

	while(f < 3 && result){
		int c = 0;
		while(c < 3 && result){
			if(t[3*x + f][3*y + c] != 0 && cantEnRegion(t, x, y, t[3*x + f][3*y + c]) != 1)
				result = false;
			c++;
		}
		f++;
	}
	return result;
}

bool regionesOk(Tablero t){
	int x = 0;
	bool result = true;

	while(x < 3 && result){
		int y = 0;
		while(y < 3 && result){
			if(!regionValida(t, x, y))
				result = false;
			y++;
		}
		x++;
	}
	return result;
}

bool sudoku_esTableroParcialmenteResuelto(Tablero t) {
	bool res;

	if(!sudoku_esTableroValido(t))
		res = false;
	else
		res = filasOk(t) && columnasOk(t) && regionesOk(t);

	return res;
}

bool sudoku_esTableroTotalmenteResuelto(Tablero t) {
	return sudoku_esTableroParcialmenteResuelto(t) && sudoku_nroDeCeldasVacias(t) == 0;
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

