
#include <iostream>
#include <vector>
using namespace std;


struct map
{
  int n_rows, n_cols;
  char** tile;
  int gold;
};

map magic_map;


void flood(int row, int col) {

  if ( row < 0 || col < 0 || row > magic_map.n_rows || col > magic_map.n_cols)
    return;

  char tile = magic_map.tile[row][col];

  if (tile == '#')
    return;
  if (tile == '%')
    magic_map.gold++;

  magic_map.tile[row][col] = '#';

  flood (row -1, col   );
  flood (row   , col -1);
  flood (row +1, col   );
  flood (row   , col +1);
}

int main () {
  int pos_row;
  int pos_col;

  magic_map.gold = 0;

  cin >> magic_map.n_cols;
  cin >> magic_map.n_rows;

  magic_map.tile = new char*[magic_map.n_rows];
  for(int i = 0; i < magic_map.n_rows; i++)
      magic_map.tile[i] = new char[magic_map.n_cols];

  for ( int r = 0; r < magic_map.n_rows; r++) {
    for ( int c = 0; c < magic_map.n_cols; c++) {
      char tile;
      cin >> tile;
      magic_map.tile[r][c] = tile;
      if (tile == '@') {
        pos_col = c;
        pos_row = r;
      }
    }
  }

  flood(pos_row, pos_col);
  cout << magic_map.gold << endl;

  return 0;
}
