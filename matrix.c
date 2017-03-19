#include "common.h"

MATRIX_2 matrix2_mul(const MATRIX_2 *m1, const MATRIX_2 *m2)
{
	MATRIX_2 m;
	m.m_00 = m1->m_00 * m2->m_00 + m1->m_01 * m2->m_10;
	m.m_01 = m1->m_00 * m2->m_01 + m1->m_01 * m2->m_11;
	m.m_10 = m1->m_10 * m2->m_00 + m1->m_11 * m2->m_10;
	m.m_11 = m1->m_10 * m2->m_01 + m1->m_11 * m2->m_11;
	return m; 
}

MATRIX_2 matrix2_power(const MATRIX_2 *m, unsigned int n)
{
	ASSERT(n > 0);
	if(n == 1)
		return *m;
	else if(n % 2 == 0) {
		MATRIX_2 temp = matrix2_power(m, n / 2);
		return matrix2_mul(&temp, &temp);
	} else {
		MATRIX_2 temp = matrix2_power(m, (n - 1) / 2);
		MATRIX_2 temp1 = matrix2_mul(&temp, &temp);
		return matrix2_mul(m, &temp1);
		
	}
}
	
void matrix2_show(const MATRIX_2 *m)
{
	printf("matrix2: 00: %ld, 01:%ld, 10:%ld, 11:%ld\n", m->m_00, m->m_01, m->m_10, m->m_11);	
}
