#include <iostream>
#include <vector>
#include <queue>

#define START '@'
#define GOLD  '%'
#define WALL  '#'
#define EMPTY '.'

using namespace std;

int n_rows;
int n_cols;
int gold = 0;

struct tile {
    char c;
    bool checked;

    tile(char c) : c(c), checked(false) {};
};

vector< vector<tile> > map;
queue< pair<int, int> > q;

void add_to_queue(int x, int y) {
    if(x < 0 || y < 0 || x >= n_rows || y >= n_cols || map[x][y].checked)
        return;

    map[x][y].checked = true;
    q.push(make_pair<int, int>(x, y));
}

void flood() {
    while(!q.empty()) {
        pair<int, int> current = q.front();
        q.pop(); // lol @ this API
        int x = current.first;
        int y = current.second;

        tile t = map[x][y];

        switch(map[x][y].c) {
            case WALL:
                continue;
            case GOLD:
                gold++;
            default:
                add_to_queue(x + 1, y);
                add_to_queue(x - 1, y);
                add_to_queue(x, y + 1);
                add_to_queue(x, y - 1);
        }
    }
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
    cin >> n_cols
        >> n_rows;

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
            tile t = tile(c);
            row.push_back(t);
            if(c == START) {
                q.push(make_pair<int, int>(i, j));
            }
        }

        map.push_back(row);
    }

#ifdef DEBUG
    print_map();
#endif

    flood();
    cout << gold << endl;
    return 0;
}

