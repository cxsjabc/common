#ifndef MATRIX_H
#define MATRIX_H

typedef struct
{
	long m_00;
	long m_01;
	long m_10;
	long m_11;
}MATRIX_2;

MATRIX_2 matrix2_mul(const MATRIX_2 *m1, const MATRIX_2 *m2);

MATRIX_2 matrix2_power(const MATRIX_2 *m, unsigned int n);

void matrix2_show(const MATRIX_2 *m);

#endif
