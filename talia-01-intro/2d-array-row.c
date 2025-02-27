int array[ROWS][COLS];

for (int i = 0; i < ROWS; i++) {
	for (int j = 0; j < COLS; j++) {
		array[i][j] = i * COLS + j;
	}
}
