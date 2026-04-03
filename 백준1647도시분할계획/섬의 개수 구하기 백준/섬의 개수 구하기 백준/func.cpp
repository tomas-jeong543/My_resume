#include"func.h"


int dfs_search(int xpos, int ypos, int w, int h, int*** ptr)
{
	int** mapinfo = *ptr;
	mapinfo[ypos][xpos] = 0;
	cout << "mapinfo" << endl;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << mapinfo[i][j] << " ";
		}
		cout << endl;
	}


	if (0 <= xpos + 1 && xpos + 1 < w && 0 <= ypos && ypos < h && mapinfo[ypos][xpos + 1] == 1) {
		dfs_search(xpos + 1, ypos, w, h, &(*ptr));
	}

	if (0 <= xpos - 1 && xpos - 1 < w && 0 <= ypos && ypos < h && mapinfo[ypos][xpos - 1] == 1) {
		
		dfs_search(xpos - 1, ypos, w, h, &(*ptr));
	}

	if (0 <= xpos && xpos < w && 0 <= ypos + 1 && ypos + 1 < h && mapinfo[ypos + 1][xpos] == 1) {
	
		dfs_search(xpos, ypos + 1, w, h, &(*ptr));
	}
	
	if (0 <= xpos && xpos < w && 0 <= ypos - 1 && ypos - 1 < h && mapinfo[ypos - 1][xpos] == 1) {
		dfs_search(xpos, ypos - 1, w, h, &(*ptr));
	}
	
	if (0 <= xpos + 1 && xpos + 1 < w && 0 <= ypos + 1 && ypos + 1 < h && mapinfo[ypos + 1][xpos + 1] == 1) {
		dfs_search(xpos + 1, ypos + 1, w, h, &(*ptr));
	}

	if (0 <= xpos - 1 && xpos - 1 < w && 0 <= ypos - 1 && ypos - 1 < h && mapinfo[ypos - 1][xpos - 1] == 1) {

		dfs_search(xpos - 1, ypos - 1, w, h, &(*ptr));
	}

	if (0 <= xpos - 1 && xpos - 1 < w && 0 <= ypos + 1 && ypos + 1 < h && mapinfo[ypos + 1][xpos - 1] == 1) {

		dfs_search(xpos - 1, ypos + 1, w, h, &(*ptr));
	}

	if (0 <= xpos + 1 && xpos + 1 < w && 0 <= ypos - 1 && ypos - 1 < h && mapinfo[ypos - 1][xpos + 1] == 1) {
		dfs_search(xpos + 1, ypos - 1, w, h, &(*ptr));
	}

	return 0;
}
int Find_iland_NUm(int w, int h, int** ptr)
{
		int ans = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (ptr[i][j] == 1) {
					ans += 1;
					dfs_search(j, i, w, h, &ptr);
				}
			}
		}

		return ans;
}

