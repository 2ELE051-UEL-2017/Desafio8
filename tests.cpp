#include "CppUTest/TestHarness.h"
#include <string.h>

extern "C"
{
	int crivoEratostenes(int arrayCrivo[], int listaPrimos[], int n);
}

TEST_GROUP(CrivoEratostenes)
{
};

TEST(CrivoEratostenes, nNegativo)
{
	LONGS_EQUAL(-1, crivoEratostenes(NULL, NULL, -1337));
}

TEST(CrivoEratostenes, ArrayCrivoZeroEUmNaoSaoPrimos)
{
	int arrayCrivo[11], listaPrimos[11];

	crivoEratostenes(arrayCrivo, listaPrimos, 10);

	LONGS_EQUAL(0, arrayCrivo[0]);
	LONGS_EQUAL(0, arrayCrivo[1]);
}

TEST(CrivoEratostenes, ArrayCrivo_n_10)
{
	int arrayCrivo[11], listaPrimos[11];
	int arrayCrivoExpected[11] = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0 };

	crivoEratostenes(arrayCrivo, listaPrimos, 10);

	MEMCMP_EQUAL(arrayCrivoExpected, arrayCrivo, sizeof(arrayCrivo));
}

TEST(CrivoEratostenes, Retorno_n_10)
{
	int arrayCrivo[11], listaPrimos[11];

	LONGS_EQUAL(4, crivoEratostenes(arrayCrivo, listaPrimos, 10));
}

TEST(CrivoEratostenes, ListaPrimos_n_10)
{
	int arrayCrivo[11], listaPrimos[11];
	int listaPrimosExpected[11] = { 2, 3, 5, 7 };

	crivoEratostenes(arrayCrivo, listaPrimos, 10);

	MEMCMP_EQUAL(listaPrimosExpected, listaPrimos, 4*sizeof(int));
}

TEST(CrivoEratostenes, Completo_n_0)
{
	int arrayCrivo[1], listaPrimos[1];
	int arrayCrivoExpected[1] = { 0 };

	LONGS_EQUAL(0, crivoEratostenes(arrayCrivo, listaPrimos, 0));

	MEMCMP_EQUAL(arrayCrivoExpected, arrayCrivo, sizeof(arrayCrivo));
}

TEST(CrivoEratostenes, Completo_n_1)
{
	int arrayCrivo[2], listaPrimos[2];
	int arrayCrivoExpected[2] = { 0, 0 };

	LONGS_EQUAL(0, crivoEratostenes(arrayCrivo, listaPrimos, 1));

	MEMCMP_EQUAL(arrayCrivoExpected, arrayCrivo, sizeof(arrayCrivo));
}

TEST(CrivoEratostenes, Completo_n_25)
{
	int arrayCrivo[26], listaPrimos[26];
	int arrayCrivoExpected[26];
	int listaPrimosExpected[26] = {
		2, 3, 5, 7, 11, 13, 17, 19, 23
	};
	int i;

	memset(arrayCrivoExpected, 0, sizeof(arrayCrivoExpected));
	for (i = 0; i < 9; i++)
		arrayCrivoExpected[listaPrimosExpected[i]] = 1;

	LONGS_EQUAL(9, crivoEratostenes(arrayCrivo, listaPrimos, 25));

	MEMCMP_EQUAL(arrayCrivoExpected, arrayCrivo, sizeof(arrayCrivo));
	MEMCMP_EQUAL(listaPrimosExpected, listaPrimos, 9*sizeof(int));
}

TEST(CrivoEratostenes, Completo_n_100)
{
	int arrayCrivo[101], listaPrimos[101];
	int arrayCrivoExpected[101];
	int listaPrimosExpected[101] = {
		 2,  3,  5,  7, 11, 13, 17, 19, 23, 29,
		31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
		73, 79, 83, 89, 97
	};
	int i;

	memset(arrayCrivoExpected, 0, sizeof(arrayCrivoExpected));
	for (i = 0; i < 25; i++)
		arrayCrivoExpected[listaPrimosExpected[i]] = 1;

	LONGS_EQUAL(25, crivoEratostenes(arrayCrivo, listaPrimos, 100));

	MEMCMP_EQUAL(arrayCrivoExpected, arrayCrivo, sizeof(arrayCrivo));
	MEMCMP_EQUAL(listaPrimosExpected, listaPrimos, 25*sizeof(int));
}

TEST(CrivoEratostenes, Completo_n_1000)
{
	int arrayCrivo[1001], listaPrimos[1001];
	int arrayCrivoExpected[1001];
	int listaPrimosExpected[1001] = {
		  2,   3,   5,   7,  11,  13,  17,  19,  23,  29,
		 31,  37,  41,  43,  47,  53,  59,  61,  67,  71,
		 73,  79,  83,  89,  97, 101, 103, 107, 109, 113,
		127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
		179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
		233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
		283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
		353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
		419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
		467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
		547, 557, 563, 569, 571, 577, 587, 593, 599, 601,
		607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
		661, 673, 677, 683, 691, 701, 709, 719, 727, 733,
		739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
		811, 821, 823, 827, 829, 839, 853, 857, 859, 863,
		877, 881, 883, 887, 907, 911, 919, 929, 937, 941,
		947, 953, 967, 971, 977, 983, 991, 997
	};
	int i;

	memset(arrayCrivoExpected, 0, sizeof(arrayCrivoExpected));
	for (i = 0; i < 168; i++)
		arrayCrivoExpected[listaPrimosExpected[i]] = 1;

	LONGS_EQUAL(168, crivoEratostenes(arrayCrivo, listaPrimos, 1000));

	MEMCMP_EQUAL(arrayCrivoExpected, arrayCrivo, sizeof(arrayCrivo));
	MEMCMP_EQUAL(listaPrimosExpected, listaPrimos, 168*sizeof(int));
}
