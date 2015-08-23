#include <stdlib.h>
#include <iostream>
#include "RPG.hpp"

using namespace std;

RPG minirpg = RPG();

int main() {

    while (!minirpg.isGameOver() ) {
        try {
            minirpg.action();
        } catch(int thrownINT){
            cout << "Something strange happened. Error code: " << thrownINT << endl;
            break;
        }
    }
    
	return 0;
}
