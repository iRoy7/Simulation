#include <stdio.h>
const int NMAX = 70;
int M[NMAX][NMAX];	// N*N Matrix compose of 'n' blocks
int N;
int cnt;
enum QUARD {
	Q1 = 1,
	Q2,
	Q3,
	Q4,
};

int findCurQ(int sy, int sx, int D)
{
	int y, x;

	for (int i = sy; i < sy+D; i++)
		for (int j = sx; j < sx+D; j++)
			if (M[i][j])
			{
				y = i, x = j;
				break;
			}

	if ((sy <= y && y < sy + D / 2) &&
		(sx <= x && x < sx + D / 2))
		return Q1;
	else if ((sy <= y && y < sy + D / 2) &&
		(sx + D / 2 <= x&&x < sx + D))
		return Q2;
	else if ((sy + D / 2 <= y && y < sy + D) &&
		(sx <= x && x < sx + D / 2))
		return Q3;
	else if ((sy + D / 2 <= y && y < sy + D) &&
		(sx + D / 2 <= x && x < sx + D))
		return Q4;
	else
		return 0;
}

void buildupBlocks(int sy, int sx, int D)
{
	// Base cases
	if (D == 2)
	{
		cnt++;
		for (int i = sy; i <= sy + D / 2; i++)
		{
			for (int j = sx; j <= sx + D / 2; j++)
			{
				printf("MW: M[%d][%d] = %d\n", i, j, M[i][j]);
				if (!M[i][j])
				{
					M[i][j] = cnt;
				}
			}
		}
		return;
	}

	// General cases
	int curQ; // current quadrant
	curQ = findCurQ(sy, sx, D);
	if (!curQ)
	{
		printf("Wrong quadrant!\n");
		return;
	}
	else {
		cnt++;
		D = D / 2;
		int ny = sy, nx = sx;

		if (curQ == Q1)
		{
			M[ny + D - 1][nx + D] = cnt;
			M[ny + D][nx + D - 1] = cnt;
			M[ny + D][nx + D] = cnt;
			buildupBlocks(ny, nx, D);
			buildupBlocks(ny, nx + D, D);
			buildupBlocks(ny + D, nx, D);
			buildupBlocks(ny + D, nx + D, D);
		}
		else if (curQ == Q2)
		{
			M[ny + D - 1][nx + D - 1] = cnt;
			M[ny + D][nx + D - 1] = cnt;
			M[ny + D][nx + D] = cnt;
			buildupBlocks(ny, nx, D);
			buildupBlocks(ny, nx + D, D);
			buildupBlocks(ny + D, nx, D);
			buildupBlocks(ny + D, nx + D, D);
		}
		else if (curQ == Q3)
		{
			M[ny + D - 1][nx + D - 1] = cnt;
			M[ny + D - 1][nx + D] = cnt;
			M[ny + D][nx + D] = cnt;
			buildupBlocks(ny, nx, D);
			buildupBlocks(ny, nx + D, D);
			buildupBlocks(ny + D, nx, D);
			buildupBlocks(ny + D, nx + D, D);
		}
		else if (curQ == Q4)
		{
			M[ny + D - 1][nx + D - 1] = cnt;
			M[ny + D - 1][nx + D] = cnt;
			M[ny + D][nx + D - 1] = cnt;
			buildupBlocks(ny, nx, D);
			buildupBlocks(ny, nx + D, D);
			buildupBlocks(ny + D, nx, D);
			buildupBlocks(ny + D, nx + D, D);
		}
	}
}

void printMatrix()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			printf("%d ", M[i][j]);
		printf("\n");
	}
}

void initMatrix()
{
	for (int i = 0; i < NMAX * NMAX; i++)
		*((int *)M + i) = 0;
}

void makeBlocks()
{
	int T; scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		initMatrix();

		int n, zy, zx;
		scanf("%d %d %d", &n, &zy, &zx);

		N = 1;
		for (int i = 1; i <= n; i++) N *= 2;

		cnt = 0;
		M[zy][zx]--;
		buildupBlocks(1, 1, N);
		M[zy][zx]++;

		printMatrix();
	}
}