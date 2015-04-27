/*
ID: dcdexte1
LANG: C++
PROG: castle
*/

#include <cstdlib>
#include <cstdio>
#include <queue>
#include <set>
#include <vector>

#define N_MAX 50

using namespace std;

int m, n;

int walls[N_MAX][N_MAX];
int explored[N_MAX][N_MAX];
int sectionCount[N_MAX * N_MAX + 1];
vector<set<pair<int, int> > > adj;

struct roomWall {
    int i;
    int j;
    int size;
    char wall;
};

roomWall findBestRoomWall() {
    roomWall ret;

    ret.i = -1;
    ret.j = -1;
    ret.size = 0;
    for (int j = 0; j < n;  ++j) {
        for (int i = m - 1; i >= 0; --i) {
            // Check North
            if (walls[i][j] & 2 && i > 0 && explored[i][j] != explored[i-1][j]) {
                int tmp = sectionCount[explored[i][j]] + sectionCount[explored[i-1][j]];
                if (tmp > ret.size) {
                    ret.i = i;
                    ret.j = j;
                    ret.size = tmp;
                    ret.wall = 'N';
                }
            }

            // Check East
            if (walls[i][j] & 4 && j < n && explored[i][j] != explored[i][j+1]) {
                int tmp = sectionCount[explored[i][j]] + sectionCount[explored[i][j+1]];
                if (tmp > ret.size) {
                    ret.i = i;
                    ret.j = j;
                    ret.size = tmp;
                    ret.wall = 'E';
                }
            }
        }
    }

    return ret;
}

void calcRooms() {
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            if (explored[i][j] == 0) {
                int sz = 0;
                set<pair<int, int> > roomAdj;

                queue<pair<int, int> > q;
                q.push(make_pair(i, j));
                explored[i][j] = adj.size() + 1;

                while (!q.empty())  {
                    ++sz;
                    pair<int, int> room = q.front();
                    q.pop();

                    // Left wall
                    if (room.second - 1 >= 0)
                    {
                        if (walls[room.first][room.second] & 1)
                            roomAdj.insert(make_pair(room.first, room.second-1));
                        else if(explored[room.first][room.second-1] == 0) {
                            q.push(make_pair(room.first, room.second-1));
                            explored[room.first][room.second-1] = adj.size() + 1;
                        }
                    }

                    // Top wall
                    if (room.first -1 >= 0)
                    {
                        if (walls[room.first][room.second] & 2)
                            roomAdj.insert(make_pair(room.first-1, room.second));
                        else if(explored[room.first-1][room.second] == 0) {
                            q.push(make_pair(room.first-1, room.second));
                            explored[room.first-1][room.second] = adj.size() + 1;
                        }
                    }

                    // Right wall
                    if (room.second + 1 != n)
                    {
                        if (walls[room.first][room.second] & 4)
                            roomAdj.insert(make_pair(room.first, room.second+1));
                        else if(explored[room.first][room.second+1] == 0) {
                            q.push(make_pair(room.first, room.second+1));
                            explored[room.first][room.second+1] = adj.size() + 1;
                        }
                    }

                    // Bottom wall
                    if (room.first + 1 != m) {
                        if (walls[room.first][room.second] & 8)
                            roomAdj.insert(make_pair(room.first+1, room.second));
                        else if(explored[room.first+1][room.second] == 0) {
                            q.push(make_pair(room.first+1, room.second));
                            explored[room.first+1][room.second] = adj.size() + 1;
                        }
                    }
                }
                
                sectionCount[adj.size() + 1] = sz;
                adj.push_back(roomAdj);
            }
        }
}


int main() {
    FILE* in = fopen("castle.in", "r");
    FILE* out = fopen("castle.out", "w");

    fscanf(in, "%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            fscanf(in, "%d", &walls[i][j]);
    fclose(in);

    calcRooms();
    fprintf(out, "%lu\n", adj.size());
    int best = -1;
    for (int i = 0; i < adj.size(); ++i) {
        if ( sectionCount[i+1] > best) {
            best = sectionCount[i+1];
        }
    }
    fprintf(out, "%d\n", best);

    /*
     * Prints maze rooms
    for (int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            printf(" %d", explored[i][j]);
        }
        printf("\n");
    }

     * Prints room sizes
    for (int i = 0; i < adj.size(); ++i) {
        printf(" %d", sectionCount[i+1]);
    }
    printf("\n");
    */


    roomWall ret = findBestRoomWall();
    fprintf(out, "%d\n", ret.size);
    fprintf(out, "%d %d %c\n", ret.i + 1, ret.j + 1, ret.wall);
    fclose(out);

    return 0;
}
