for (int i = 0; i < length-1; i++) {
  for (int j = i; j < length-1; j++) {
    matriz[j+1][i] += matriz[i][j+1];
    matriz[i][j+1]=0;
  }
}

