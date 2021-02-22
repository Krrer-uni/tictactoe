#include "lib.h"
#include <algorithm>
#include <iostream>
//siemasiema
int min(int a, int b){
    return (a < b) ? a : b;
}

int check(int board[3][3]){
    int kk;
    int state_a, state_b;

    for(int x = 0; x < 3; x++){
        state_a = state_b = 0;
        for(int y = 0; y < 3; y++){
        state_a += board[x][y];
        state_b += board[y][x];
        }
        if(state_a == 3 || state_b == 3) return 1;
        if(state_a == -3 || state_b == -3) return -1;
    }

    state_a = state_b = 0;
    for(int i = 0; i < 3; i++){
        state_a += board[i][i];
        state_b += board[i][2 -i];
    }
    if(state_a == 3 || state_b == 3) return 1;
    if(state_a == -3 || state_b == -3) return -1;

    if(space_left(board) == 0) return 0;

    return -3;
}

//wejście przed zrobieniem ruchu
int dopisz (int board[3][3]){
    int copied[3][3];
    std::copy(&board[0][0], &board[3][3], &copied[0][0]);
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            if(board[x][y] == 0){
            std::copy(&board[0][0], &board[3][3], &copied[0][0]);
                copied[x][y] = 1;
               // show(copied);
                if(check(copied) == 1) {
                   // std::cout << x << " " << y << " <-wyniki\n";
                    return (10*(x+1) + (y+1));
                }
            }
        }
    }

    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            if(board[x][y] == 0){
            std::copy(&board[0][0], &board[3][3], &copied[0][0]);
                copied[x][y] = 1;
               // show(copied);
                if(dla_o(copied) == 1) {
                    // std::cout << x << " " << y << " <-wyniki1\n";
                    return (10*(x+1) + (y+1));
                }
            }
        }
    }

    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            if(board[x][y] == 0){
            std::copy(&board[0][0], &board[3][3], &copied[0][0]);
                copied[x][y] = 1;
               // show(copied);
                if(dla_o(copied) == 0) {
                    // std::cout << x << " " << y << " <-wyniki2\n";
                    return (10*(x+1) + (y+1));
                }
            }
        }
    }

    return 1337;
}

int dla_o (int board[3][3]){
    int copied[3][3];
    int wynik = 1;
    if(space_left(board) == 0) return 0;
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            if(board[x][y] == 0){
                std::copy(&board[0][0], &board[3][3], &copied[0][0]);
                copied[x][y] = -1;
                if(check(copied) == -1) return -1;
                wynik = min(wynik, ist_x(copied));
            }
        }
    }    
    return wynik;
}

int ist_x (int board[3][3]){
    int copied[3][3];
    if(space_left(board) == 0) return 0;
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            if(board[x][y] == 0){
            std::copy(&board[0][0], &board[3][3], &copied[0][0]);
                copied[x][y] = 1;
                if(check(copied) == 1)// { show(copied);
                 return 1;//}
            }
        }
    }
    if(space_left(board) == 1) return 0;
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            if(board[x][y] == 0){
            std::copy(&board[0][0], &board[3][3], &copied[0][0]);
                copied[x][y] = 1;
                if(dla_o(copied) == 1) return 1;
            }
        }
    }

    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            if(board[x][y] == 0){
            std::copy(&board[0][0], &board[3][3], &copied[0][0]);
                copied[x][y] = 1;
                if(check(copied) == 0)// { show(copied);
                 return 0;//}
            }
        }
    }
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            if(board[x][y] == 0){
            std::copy(&board[0][0], &board[3][3], &copied[0][0]);
                copied[x][y] = 1;
                if(dla_o(copied) == 0) return 0;
            }
        }
    }

    return -1;
}

void show(int board[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
        if(board[i][j] == -1) std::cout << "o ";
        else if(board[i][j] == 1) std::cout << "x ";
        else if(board[i][j] == 0) std::cout << "- ";
        else std::cout << "% ";
        }
        std::cout << "\n";
    }  
    std::cout << "\n";
}

int space_left(int board[3][3]){
    int c = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == 0) c++;
        }
    }  
    return c;
}