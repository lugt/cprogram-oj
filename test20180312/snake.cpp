//
// Created by lugt on 2018/3/19.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <cstring>

using std::cin;
using std::cerr;
using std::cout;
using std::string;
using std::endl;

enum direction {
    GO_UP,
    GO_DOWN,
    GO_LEFT,
    GO_RIGHT
};

bool isWall(int x, int y, int size){
    return (x < 0 || x >= size || y < 0 || y >= size);
}


void real_go(int & x, int & y, direction &direction){
    switch (direction){
        case GO_RIGHT:
            x += 1;
            break;
        case GO_LEFT:
            x -= 1;
            break;
        case GO_DOWN:
            y += 1;
            break;
        case GO_UP:
            y -= 1;
            break;
    }
}

int test_go(int x, int y, direction &direction, int size, int* pool) {
    switch (direction){
        case GO_RIGHT:
            x += 1;
            break;
        case GO_LEFT:
            x -= 1;
            break;
        case GO_DOWN:
            y += 1;
            break;
        case GO_UP:
            y -= 1;
            break;
    }
    if(isWall(x, y, size)){
        return -1;
    }
    if(pool[x + y * size] != 0){
        return -1;
    }
    return 0;
}

direction make_turn(direction d_){
    direction alt;
    switch (d_){
        case GO_RIGHT:
            alt = GO_DOWN;
            break;
        case GO_LEFT:
            alt = GO_UP;
            break;
        case GO_DOWN:
            alt = GO_LEFT;
            break;
        case GO_UP:
            alt = GO_RIGHT;
            break;
    }
    return alt;
}

/**
 * Go to next position;
 * @param x
 * @param y
 * @param d
 * @param pool
 * @param size
 * @param step
 * @return
 */
int go_next(int & x, int & y, direction & d_, int *pool, int size, int & step) {
    if(isWall(x, y, size) || pool[y * size + x] != 0){
        return -1;// finished
    }
    step ++;
    pool[x + y * size] = step;
    if(test_go(x, y, d_, size, pool) == 0){
        // It's okay to get there;
        real_go(x, y, d_);
    }else{
        // No, change direction;
        direction alt = make_turn(d_);
        d_ = alt;
        real_go(x, y, d_);
    }
    return 0;
}


int main2() {
    int t, size, *matrix;
    direction now_direction;
    cin >> t;

    while (t--) {
        now_direction = GO_RIGHT;
        int pos_x = 0, pos_y = 0;
        int step = 0;
        cin >> size;
        if(size > 1){
            matrix = static_cast<int *>(malloc(sizeof(int) * size * size));
            memset(matrix, 0, sizeof(int) * size * size);
            while(-1 != go_next(pos_x, pos_y, now_direction, matrix, size, step)){
            }
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    cout << (int) matrix[i * size + j];
                    if(j != size - 1){
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }else if(size == 1){
            cout << "1" << endl;
        }
        cout << endl;
    }

    return 0;
}

