#include <iostream>
//#include "lib.h"
#include <algorithm>
#include "lib.h"
#include <vector>
int main(){
    int size ;
    std::cin >> size;
    std::vector<int> score(2*(size+1) + 1, 0);
    std::vector<std::vector<int>> board;
    std::vector<int> arr (size, 0);
    for(int i = 0; i < size; i++){
        board.push_back(arr);
    }
    char first;
    int x,y;    
    int control;
    bool game = true;
    std::cout << "Do you want to move first? (y/n) \n";
    std::cin >> first;

    if(first == 'y'){
        std::cin >> x >> y;
        board[x][y] = -1;
    }
    std::cout << "\n";
    show(size, board);
    // std::cout << min(x,y) << "\n";

    while(score[2*size +2] < size*size){
        //computer1

        int cords = compute(size, board, score);
        int x = cords / 10 - 1;
        int y = cords % 10 - 1;
        std::cout << cords << "\n";
        write(size, x, y, 1, board, score);

        show(size, board);

        if(check(size, score) == 1){
            std::cout << "computer won!\n";
            break;
        }
        
        std::cout << score[2*size + 2] <<" score\n";

        //player
        int xp,yp;
        std::cin >> yp >> xp;
        std::cout << "\n";
        while(board[xp][yp] != 0){
            std::cout << "zły ruch! powtórz \n";
            std::cin >> yp >> xp;
        }
       write(size, xp, yp, -1, board, score);
       show(size, board);

        if(check(size, score) == -1){
            std::cout << "player won!\n";
            break;
        }
        std::cout << score[2*size + 2] <<" score\n";
        if(score[2*size +2] = size*size) break;
    }
}

