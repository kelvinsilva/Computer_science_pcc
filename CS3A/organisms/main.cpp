#include <iostream>
#include "organism.h"

using namespace std;

int main()
{

    world new_world(20, 20);

    new_world.Initialize(5, 100);

    while(1){
        new_world.Draw();

        new_world.Run();


        cin.get();
    }

    return 0;
}

