#include "lib.h"
#include <algorithm>
#include <iostream>
int min(int a, int b){
    return (a < b) ? a : b;
}

int check(int size, std::vector<int> score){
    for(int i = 0; i < 2*(size+1); i++){
        if(score[i] == size) return 1;
        if(score[i] == -size) return -1;
    }
    if(score[2*(size+1)] == size) return 0;
    return -3;
}

//wejście przed zrobieniem ruchu
int compute (int size, std::vector<std::vector<int>> board, std::vector<int> score){


    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            if(board[x][y] == 0){
            std::vector<std::vector<int>> copied (board);
            std::vector<int> copied_score (score);
               write(size, x, y, 1, copied, copied_score);
               // show(copied);
                if(check(size, copied_score) == 1) {
                   // std::cout << x << " " << y << " <-wyniki\n";
                    return (10*(x+1) + (y+1));
                }
            }
        }
    }

    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            if(board[x][y] == 0){
            std::vector<std::vector<int>> copied (board);
            std::vector<int> copied_score (score);
                write(size, x, y, 1, copied, copied_score);
               // show(copied);
                if(dla_o(size, copied, copied_score) == 1) {
                    // std::cout << x << " " << y << " <-wyniki1\n";
                    return (10*(x+1) + (y+1));
                }
            }
        }
    }

    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            if(board[x][y] == 0){
            std::vector<std::vector<int>> copied (board);
            std::vector<int> copied_score (score);
                write(size, x, y, 1, copied, copied_score);
               // show(copied);
                if(dla_o(size, copied, copied_score) == 0) {
                    // std::cout << x << " " << y << " <-wyniki2\n";
                    return (10*(x+1) + (y+1));
                }
            }
        }
    }

    return 1337;
}

int dla_o (int size, std::vector<std::vector<int>> board, std::vector<int> score){
    int wynik = 1;
    if(score[2*size +2] == size*size) return 0;
    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            if(board[x][y] == 0){
                std::vector<std::vector<int>> copied (board);
                std::vector<int> copied_score (score);
                write(size, x, y, -1, copied, copied_score);
                if(check(size, copied_score) == -1) return -1;
                wynik = min(wynik, ist_x(size, copied, copied_score));
            }
        }
    }    
    return wynik;
}

int ist_x (int size, std::vector<std::vector<int>> board, std::vector<int> score){
    if(score[2*size +2] == size*size) return 0;
    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            if(board[x][y] == 0){
            std::vector<std::vector<int>> copied (board);
            std::vector<int> copied_score (score);
                write(size, x, y, 1, copied, copied_score);
                if(check(size, copied_score) == 1)// 
                { show(size, copied);
                 return 1;}
            }
        }
    }
    if(score[2*size +2] == size*size-1) return 0;
    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            if(board[x][y] == 0){
            std::vector<std::vector<int>> copied (board);
            std::vector<int> copied_score (score);
                write(size, x, y, 1, copied, copied_score);
                if(dla_o(size, copied, copied_score) == 1) return 1;
            }
        }




    }

    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            if(board[x][y] == 0){
            std::vector<std::vector<int>> copied (board);
            std::vector<int> copied_score (score);
                write(size, x, y, 1, copied, copied_score);
                if(check(size, copied_score) == 0)// { show(copied);
                 return 0;//}
            }
        }
    }
    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            if(board[x][y] == 0){
            std::vector<std::vector<int>> copied (board);
            std::vector<int> copied_score (score);
                write(size, x, y, 1, copied, copied_score);
                if(dla_o(size, copied, copied_score) == 0) return 0;
            }
        }
    }

    return -1;
}

void show(int size, std::vector<std::vector<int>> board){
    std::cout << "  ";
    for(int i = 0; i < size; i++) std::cout<< i << " ";
        std::cout << "\n";
    for(int i = 0; i < size; i++){
        std::cout << i << " ";
        for(int j = 0; j < size; j++){
        if(board[i][j] == -1) std::cout << "o ";
        else if(board[i][j] == 1) std::cout << "x ";
        else if(board[i][j] == 0) std::cout << "- ";
        else std::cout << "% ";
        }
        std::cout << "\n";
    }  
    std::cout << "\n";
}


void write (int size, int x, int y, int value, std::vector<std::vector<int>> &board, std::vector<int> &score){
    board[x][y] = value;

    score[x] += value;
    score[size + y] += value;

    if(x + y == 0) score[2*size] += value;
    if(x - y == 0) score[2*size + 1] += value;

    score[2*size + 2] += 1;
}