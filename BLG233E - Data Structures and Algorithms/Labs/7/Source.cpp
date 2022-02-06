#include <iostream>
#include <cstdio>
#include "Header.h"

using namespace std;

StackOP s;
lab maz;
lab *path;
lab *cycle;

int main(){

	char maze[15][22] = {
		"#o###################",
		"#     #      #    # #",
		"# ### # ###### ## # #",
		"# # #        # #  # #",
		"# # ### ######## ## #",
		"#     # # ##   #    #",
		"### # # # ## # # ####",
		"# # # # #    #      #",
		"# # # # # ######### #",
		"# # # # # #       # #",
		"# # #   # # #####   #",
		"# # ##### # #   #####",
		"#         #   #     #",
		"###################E#" };

	maz.x = 0;
	maz.y = 1;

	while (maze[maz.x + 1][maz.y] != 'E'){

		for (int i = 0; i < 15; i++){
			for (int j = 0; j < 22; j++){
				cout << maze[i][j];
			}
			cout << endl;
		}

		maz.down = 0;
		maz.left = 0;
		maz.right = 0;
		maz.up = 0;

		if (maz.x<22 && maze[maz.x + 1][maz.y] == ' ')
			maz.down = 1;

		if (maz.x>0 && maze[maz.x-1][maz.y] == ' ')
			maz.up = 1;

		if (maz.y<22 && maze[maz.x][maz.y+1] == ' ')
			maz.right = 1;

		if (maz.y>0 && maze[maz.x][maz.y-1] == ' ')
			maz.left = 1;


		if (maz.down == 1){
			maz.x++;
			maze[maz.x][maz.y] = 'o';
			maz.prev = 'u';
		}

		else if (maz.right == 1){
			maz.y++;
			maze[maz.x][maz.y] = 'o';
			maz.prev = 'l';
		}

		else if (maz.up == 1){
			maz.x--;
			maze[maz.x][maz.y] = 'o';
			maz.prev = 'd';
		}

		else if (maz.left == 1){
			maz.y--;
			maze[maz.x][maz.y] = 'o';
			maz.prev = 'r';
		}

		if (maz.up + maz.down + maz.right + maz.left > 1){
			maz.criticalpoint[0][0] = maz.x;
			maz.criticalpoint[0][1] = maz.y;
		}
			
		if ((maz.up + maz.down + maz.right + maz.left == 0) || ((maze[maz.x + 1][maz.y] == 'o' && maz.prev != 'd') || (maze[maz.x - 1][maz.y] == 'o'  && maz.prev != 'u') || (maze[maz.x][maz.y + 1] == 'o'  && maz.prev != 'r') || (maze[maz.x][maz.y - 1] == 'o' && maz.prev != 'l'))){
			while (maz.x != maz.criticalpoint[0][0] && maz.y != maz.criticalpoint[0][1]){
				maze[maz.x][maz.y] == ' ';
				if (maz.prev == 'u')
					maz.x--;

				if (maz.prev == 'd')
					maz.x++;

				if (maz.prev == 'l')
					maz.y--;

				if (maz.prev == 'r')
					maz.y++;
			}
		}
		getchar();
		system("cls");
	}
	
	return 0;
}