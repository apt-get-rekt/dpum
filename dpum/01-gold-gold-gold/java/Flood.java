import java.util.Scanner;
import java.io.IOException;

/** Flood fill solution to the Gloin problem
 *  frm 28/10/2015
 */

class Flood {
    static Tile[][] map;
    static char WALL = '#';
    static char EMPTY = '.';
    static char START = '@';
    static char GOLD = '%';
    static int count = 0;
    static int n_rows;
    static int n_cols;

    static void flood(int x, int y) {
        if (x < 0 || y < 0 || x > n_rows || y > n_cols)
            return;

        Tile t = map[x][y];

        if(t.checked || t.c == WALL)
            return;

        if(t.c == GOLD)
            count++;

        t.checked = true;
        flood(x + 1, y);
        flood(x - 1, y);
        flood(x, y - 1);
        flood(x, y + 1);
    }

    public static void main(String[] args) throws IOException {
        int current_x = -1;
        int current_y = -1;

        Scanner in = new Scanner(System.in);
        n_cols = in.nextInt();
        n_rows = in.nextInt();

        map = new Tile[n_rows][n_cols];

        in.nextLine();

        for(int i = 0; i < n_rows; i++) {
            char[] line = in.nextLine().toCharArray();
            for(int j = 0; j < n_cols; j++) {
                char c = line[j];
                Tile t = new Tile(c);
                map[i][j] = t;
                if(c == START) {
                    current_x = i;
                    current_y = j;
                }
            }
        }

        flood(current_x, current_y);
        System.out.println(count);
    }
}

class Tile {
    public char c;
    public boolean checked;
    public Tile(char ch) {
        c = ch;
        checked = false;
    }
}
