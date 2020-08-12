#include <stdlib.h>
#include <iostream>
#include "include/RPG.hpp"

using namespace std;

int main() {
	RPG minirpg = RPG();

    while (!minirpg.isGameOver() ) {
        try {
        	system("clear");
            minirpg.action();
        } catch(int thrownINT){
            cout << "Something strange happened. Error code: " << thrownINT << endl;
            break;
        }
    }

	return 0;
}
