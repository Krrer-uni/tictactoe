#include <iostream>
//#include "lib.h"
#include <algorithm>
#include "lib.h"
int main(){
    int board[3][3];
    char first;
    int x,y;
    int control;
    bool game = true;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
        board[i][j] = 0;
    }    

    std::cout << "Do you want to move first? (y/n) \n";
    std::cin >> first;

    if(first == 'y'){
        std::cin >> x >> y;
        board[x][y] = -1;
    }
    std::cout << "\n";
    show(board);
    // std::cout << min(x,y) << "\n";

    while(space_left(board)!=0){
        //computer
        int cords = dopisz(board);
        int x = cords / 10 - 1;
        int y = cords % 10 - 1;
        std::cout << cords << "\n";
        board[x][y] = 1;

        show(board);

        if(check(board) == 1) break;
        


        //player
        int xp,yp;
        std::cin >> yp >> xp;
        std::cout << "\n";
        while(board[xp][yp] != 0){
            std::cout << "zły ruch! powtórz \n";
            std::cin >> yp >> xp;
        }
       board[xp][yp] = -1;
       show(board);

       if(check(board) == -1) break;
    
    }
}

