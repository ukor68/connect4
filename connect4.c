#include <stdio.h>
#include <stdbool.h>

void print_m(int rows, int cols, int m[][cols]);

int main () {
	int rows = 6;
	int cols = 7;
	int m[6][7] = {0};
	int t = 0;
	int c = 0;
	bool gameover = false;
	print_m(rows, cols, m);
	while (!gameover) {
		printf("Inserire 1 o 2 e il numero di colonna (0-6): ");
		if (scanf("%d", &t) == 1 && scanf("%d", &c) == 1) {

			if (t < 0 || t > 2 || c < 0 || c > rows) {
				printf("Numero non valido\n");
			}
			else {
				int r = rows-1;
				while (r >= 0 && m[r][c] == 1 || m[r][c] == 2) {
					r--;
				}
				m[r][c] = t;
				print_m(rows, cols, m);
				for(size_t i = 0; i < cols; ++i) {
					if(m[r][i] == m[r][i+1] && m[r][i+1] == m[r][i+2] && m[r][i+2] == m[r][i+3] && m[r][i] != 0) {
						gameover = true;
						printf("Ha vinto %d\n", m[r][i]);
						break;
					}
				}
				for(size_t i = 0; i < rows; ++i) {
					if(m[i][c] == m[i+1][c] && m[i+1][c] == m[i+2][c] && m[i+2][c] == m[i+3][c] && m[i][c] != 0) {
						gameover = true;
						printf("Ha vinto %d\n", m[i][c]);
						break;
					}
				}
			}
		}
		else {
			printf("Non inserire qualsiasi cosa che non sia un numero!\n");
			break;
		}
	}
}

void print_m(int rows, int cols, int m[][cols]) {
	printf("\n");
	printf("\x1b[3J\x1b[H\x1b[2J");
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
