/* Solving Gloin using a flood fill */

#include <iostream>
#include <vector>

#define START '@'
#define GOLD  '%'
#define WALL  '#'
#define EMPTY '.'

using namespace std;

int n_rows;
int n_cols;
int current_x;
int current_y;
int gold = 0;

struct tile {
    char c;
    bool checked;

    tile(char c) : c(c), checked(false) {};
};

vector< vector<tile> > map;

void flood(int x, int y) {
    if(x < 0 || y < 0 || x > n_rows || y > n_cols)
        return;

    tile t = map[x][y];

    if(t.checked || t.c == WALL)
        return;

    map[x][y].checked = true;

    if(t.c == GOLD)
        gold++;

    flood(x + 1, y);
    flood(x - 1, y);
    flood(x, y + 1);
    flood(x, y - 1);
}

#ifdef DEBUG
void print_map() {
    for(int i = 0; i < map.size(); i++) {
        for(int j = 0; j < map[i].size(); j++)
            cout << map[i][j].c;
        cout << endl;
    }
}
#endif

int main() {
    cin >> n_cols;
    cin >> n_rows;

#ifdef DEBUG
    cout << "n_rows: "
        << n_rows
        << "; n_cols: "
        << n_cols
        << endl;
#endif

    for(int i = 0; i < n_rows; i++) {
        vector<tile> row;
        for(int j = 0; j < n_cols; j++) {
            char c;
            cin >> c;
            row.push_back(tile(c));
            if(c == START) {
                current_x = i;
                current_y = j;
            }
        }

        map.push_back(row);
    }

#ifdef DEBUG
    print_map();
#endif

    flood(current_x, current_y);
    cout << gold;

    return 0;
}
