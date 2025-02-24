int array[ROWS][COLS];

for (int j = 0; j < COLS; j++) {
	for (int i = 0; i < ROWS; i++) {
		array[i][j] = i * COLS + j;
	}
}

