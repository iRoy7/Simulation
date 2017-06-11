/* Sel Lumbers Box and find maximum profit */


#include <stdio.h>
const int BMAX = 11;	// 1 <= BOX <= 10
const int CMAX = 21;	// 1 <= BOX내 나무도막개수 <= 20
const int LMAX = 1001;	// 1 <= 나무도막길이 <= 1000
const int IMIN = -2147483648;

int BOX[BMAX][CMAX];
int maxP;		// Maximum of Profit
int BP[BMAX];	// BOX Profit

void qsort(int s, int e)
{
	if (s >= e) return;
	int l, r, p, tmp;
	l = s - 1, r = e + 1, p = BP[(s + e) / 2];
	while (1)
	{
		while (BP[++l] > p);
		while (BP[--r] < p);
		if (l >= r) break;
		tmp = BP[l], BP[l] = BP[r], BP[r] = tmp;
	}
	qsort(s, l - 1);
	qsort(r + 1, e);
}

// Return total profits after cutting lumbers
int cutLumbers(int bi, int cl, int ucc, int up)
{
	int totalP = 0;
	int nc = BOX[bi][0];

	for (int i = 0; i < nc; i++)
	{
		int p = 0, c = 0;
		int l = BOX[bi][i];
		int unit = l % cl;
		int cutTimes = l / cl;

		if (unit == 0)
		{
			p = cutTimes * cl * up;
			cutTimes--;
			c = cutTimes * ucc;
		}
		else
		{
			p = cutTimes * cl * up;
			c = cutTimes * ucc;
		}

		if (p > c)
			totalP += (p - c);
	}

	return totalP;
}

void selLumbersBox()
{
	freopen("selLumbersBox.txt", "r", stdin);

	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int NB; // Number of Box
		int UnitCC, UnitP; // Unit Cut Cost, Unit Price
		scanf("%d", &NB);
		scanf("%d %d", &UnitCC, &UnitP);

		int maxLen = IMIN;

		for (int i = 0; i < NB; i++)
		{
			int nc; scanf("%d", &nc);
			BOX[i][0] = nc;

			for (int j = 0; j < nc; j++)
			{
				int l; scanf("%d", &l);
				BOX[i][j + 1] = l;

				if (l > maxLen) maxLen = l;
			}
		}

		maxP = IMIN;
		for (int cl = 1; cl <= maxLen; cl++)
		{
			for (int bi = 0; bi < NB; bi++)
			{
				BP[bi] = 0;
				int p = cutLumbers(bi, cl, UnitCC, UnitP);
				BP[bi] = p;
			}

			qsort(0, NB - 1);

			int sumB = 0;
			for (int i = 0; i < 3; i++)
				sumB += BP[i];

			if (sumB > maxP) maxP = sumB;
		}

		printf("%d\n", maxP);
	}
}
