#include "../lib/gtest/gtest.h"
#include "sudoku.h"

TEST(SudokuTests, celdaVacia) {
	Tablero t;
	sudoku_vaciarTablero(t);
	bool rv = sudoku_esCeldaVacia(t, 0,0);
    ASSERT_EQ(true, rv);
}

TEST(SudokuTests, celdaNoVacia) {
	Tablero t;
	sudoku_vaciarTablero(t);
	sudoku_llenarCelda(t,0,0,1);
	bool rv = sudoku_esCeldaVacia(t, 0,0);
    ASSERT_EQ(false, rv);
}

TEST(SudokuTests, cantCeldasVaciasEnTableroVacio) {
	Tablero t;
	sudoku_vaciarTablero(t);
	int rv = sudoku_nroDeCeldasVacias(t);
    ASSERT_EQ(81, rv);
}

TEST(SudokuTests, cantCeldasVaciasEnTableroNoVacio) {
	Tablero t;
	sudoku_vaciarTablero(t);
	sudoku_llenarCelda(t,0,0,1);
	int rv = sudoku_nroDeCeldasVacias(t);
    ASSERT_EQ(80, rv);
}

TEST(SudokuTests, primerCeldaVaciaEnTableroVacio) {
	Tablero t;
	sudoku_vaciarTablero(t);
	int f = sudoku_primerCeldaVaciaFila(t);
	int c = sudoku_primerCeldaVaciaColumna(t);
    ASSERT_EQ(0, f);
    ASSERT_EQ(0, c);
}

TEST(SudokuTests, primerCeldaVaciaEnTableroNoVacio) {
	Tablero t;
	sudoku_vaciarTablero(t);
	sudoku_llenarCelda(t,0,0,1);
	int f = sudoku_primerCeldaVaciaFila(t);
	int c = sudoku_primerCeldaVaciaColumna(t);
    ASSERT_EQ(0, f);
    ASSERT_EQ(1, c);
}

TEST(SudokuTests, primerCeldaVaciaEnTableroNoVacioFilaCompleta) {
	Tablero t;
	sudoku_vaciarTablero(t);
	for (int i= 0; i<9;i++) {
		sudoku_llenarCelda(t,0,i,i+1);
	}
	int f = sudoku_primerCeldaVaciaFila(t);
	int c = sudoku_primerCeldaVaciaColumna(t);
    ASSERT_EQ(1, f);
    ASSERT_EQ(0, c);
}

TEST(SudokuTests, llenarCeldaVacia) {
	Tablero t;
	sudoku_vaciarTablero(t);
	sudoku_llenarCelda(t,0,0,5);
	int rv = sudoku_valorEnCelda(t,0,0);
	ASSERT_EQ(5,rv);
}

TEST(SudokuTests, llenarCeldaNoVacia) {
	Tablero t;
	sudoku_vaciarTablero(t);
	sudoku_llenarCelda(t,4,4,5);
	sudoku_llenarCelda(t,4,4,7);
	int rv = sudoku_valorEnCelda(t,4,4);
	ASSERT_EQ(7,rv);
}

TEST(SudokuTests, resolverTableroVacio) {
	Tablero t;
	sudoku_vaciarTablero(t);
	bool resolver_rv = sudoku_resolver(t);
	ASSERT_EQ(true,resolver_rv);
	bool totalmente_resuelto_rv = sudoku_esTableroTotalmenteResuelto(t);
	ASSERT_EQ(true,totalmente_resuelto_rv);
}

TEST(SudokuTests, tableroSinCeldasVacias) {
	Tablero t;
	sudoku_vaciarTablero(t);
	bool resolver_rv = sudoku_resolver(t);
	ASSERT_EQ(true, resolver_rv);
	int celdas_vacias_rv = sudoku_nroDeCeldasVacias(t);
	ASSERT_EQ(0, celdas_vacias_rv);
	int primer_celda_vacia_fila_rv = sudoku_primerCeldaVaciaFila(t);
	int primer_celda_vacia_columna_rv = sudoku_primerCeldaVaciaColumna(t);
	ASSERT_EQ(-1, primer_celda_vacia_fila_rv);
	ASSERT_EQ(-1, primer_celda_vacia_columna_rv);
}

TEST(SudokuTests, vaciarCelda) {
	Tablero t;
	sudoku_vaciarTablero(t);
	bool esCeldaVacia0 = sudoku_esCeldaVacia(t,0,0);
	ASSERT_EQ(true, esCeldaVacia0);
	sudoku_llenarCelda(t,0,0,1);
	bool esCeldaVacia1 = sudoku_esCeldaVacia(t,0,0);
	ASSERT_EQ(false, esCeldaVacia1);
	sudoku_vaciarCelda(t,0,0);
	bool esCeldaVacia2 = sudoku_esCeldaVacia(t,0,0);
	ASSERT_EQ(true, esCeldaVacia2);
}

TEST(SudokuTests, tableroNoTotalmenteResuelto) {
	Tablero t;
	sudoku_vaciarTablero(t);
	bool tablero_valido = sudoku_esTableroValido(t);
	ASSERT_EQ(true, tablero_valido);
	bool tablero_parc_resuelto = sudoku_esTableroParcialmenteResuelto(t);
	ASSERT_EQ(true, tablero_parc_resuelto);
	bool tablero_tot_resuelto = sudoku_esTableroTotalmenteResuelto(t);
	ASSERT_EQ(false, tablero_tot_resuelto);
}

TEST(SudokuTests, tableroInvalido) {
	Tablero t;
	sudoku_vaciarTablero(t);
	t[0][0] = 10;
	bool tablero_valido = sudoku_esTableroValido(t);
	ASSERT_EQ(false, tablero_valido);
	bool tablero_parc_resuelto = sudoku_esTableroParcialmenteResuelto(t);
	ASSERT_EQ(false, tablero_parc_resuelto);
	bool tablero_tot_resuelto = sudoku_esTableroTotalmenteResuelto(t);
	ASSERT_EQ(false, tablero_tot_resuelto);
}

TEST(SudokuTests, esSubTablero) {
	Tablero t0;
	Tablero t1;
	sudoku_vaciarTablero(t0);
	sudoku_vaciarTablero(t1);
	bool esSubTablero0 = sudoku_esSubTablero(t0,t1);
	ASSERT_EQ(true, esSubTablero0);
	sudoku_llenarCelda(t0,0,0,1);
	bool esSubTablero1 = sudoku_esSubTablero(t0,t1);
	ASSERT_EQ(false, esSubTablero1);
	bool esSubTablero2 = sudoku_esSubTablero(t1,t0);
	ASSERT_EQ(true, esSubTablero2);
}

TEST(SudokuTests, printSudokuVacio){
	Tablero t;
	sudoku_vaciarTablero(t);
	sudoku_llenarCelda(t,0,0,1);
	sudoku_print(t);
}

TEST(SudokuTests, cantOperaciones){
	Tablero t;
	sudoku_vaciarTablero(t);
	int nroOperaciones = 0;
	bool resolver0= sudoku_resolver(t, nroOperaciones);
	ASSERT_EQ(true, resolver0);
	ASSERT_LT(0, nroOperaciones);
	bool resolver1= sudoku_resolver(t, nroOperaciones);
	ASSERT_EQ(true, resolver1);
	ASSERT_EQ(0, nroOperaciones);
}
