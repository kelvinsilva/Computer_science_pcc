
#include "organism.h"
extern char uninit_sentinel;
bool world::_rand_call = false;

world::world(int sx, int sy){
    ssx = sx;
    ssy = sy;
    org_world = new Organism** [ssx];
    for (int i = 0; i < ssx; i++){
        org_world[i] = new Organism*[ssy];
    }


    if (! _rand_call){
        srand(time(0));
        _rand_call = true;
    }

}

void world::Initialize(int doodle, int ant){

    for (int i = 0; i < ssx; i++){
        for (int j = 0; j < ssy; j++){
            org_world[i][j] = (Organism*)BORDER_UNIQUE_PTR;
        }
    }

    for (int i = 1; i < ssx-1; i++){
        for (int j = 1; j < ssy-1; j++){
            org_world[i][j] = NULL;
        }
    }

    /*{
        int j = 0;
        int i = 0;

        for (; j < ssy; j++){
            //top edge
            org_world[i][j] = (Organism*)BORDER_UNIQUE_PTR;
        }
        for (; i < ssx; i++){
            //left edge
            org_world[i][j] = (Organism*)BORDER_UNIQUE_PTR;
        }
        for (i = ssy-1, j = 0; j < ssy; j++){
            //bottom edge
            org_world[i][j] = (Organism*)BORDER_UNIQUE_PTR;
        }
        for (i = 0; i < ssx; i++){
            //right edge
            org_world[i][ssx-1] = (Organism*)BORDER_UNIQUE_PTR;
        }
    }*/

    int rx, ry;

    /*rx = rand()%19+1;
    ry = rand()%19+1;

    rx = (rx >= 19) ? 18 : rx;
    ry = (ry >= 19) ? 18 : ry;*/


    for (int i = 0; i < doodle; i++){
        rx = rand()%19+1;
        ry = rand()%19+1;

        rx = (rx >= 19) ? 18 : rx; //make sure we are placed not on border
        ry = (ry >= 19) ? 18 : ry;


        Organism *temp = new Doodlebug(rx, ry);
        org_world[rx][ry] = temp;


    }
    for (int i = 0; i < ant; i++){
        rx = rand()%19+1;
        ry = rand()%19+1;

        rx = (rx >= 19) ? 18 : rx; //make sure we are placed not on border
        ry = (ry >= 19) ? 18 : ry;

        Organism *temp = new Ant(rx, ry);
        org_world[rx][ry] = temp;

    }

}

void world::Draw(){

    for (int i = 0; i < ssx; i++){
        for (int j = 0; j < ssy; j++){

            if (org_world[i][j] == NULL){
                cout << " ";
            }else if (org_world[i][j] != BORDER_UNIQUE_PTR){

                if(org_world[i][j]->getID() == 3){
                    cout << "X";
                }else if (org_world[i][j]->getID() == 2){
                    cout << "o";
                }

            }else if (org_world[i][j] == BORDER_UNIQUE_PTR){
                cout << "*";
            }
        }
        cout << endl;
    }

}
void world::Run(){

    for (int i = 0; i < ssx; i++){

        for (int j = 0; j < ssy; j++){ //for every non null pointer (i.e existing) object...

            if (org_world[i][j] != NULL && org_world[i][j] != BORDER_UNIQUE_PTR){

                Organism *temp_ptrs[5];

                temp_ptrs[0] = org_world[i][j];
                temp_ptrs[1] = org_world[i+1][j];
                temp_ptrs[2] = org_world[i][j+1];
                temp_ptrs[3] = org_world[i-1][j];
                temp_ptrs[4] = org_world[i][j-1];

                org_world[i][j]->move(temp_ptrs); //cause change in temps;

                org_world[i][j]   = temp_ptrs[0];   //Reassign the temps to world
                org_world[i+1][j] = temp_ptrs[1];
                org_world[i][j+1] = temp_ptrs[2];
                org_world[i-1][j] = temp_ptrs[3];
                org_world[i][j-1] = temp_ptrs[4];

            }
        }
    }
}

Organism::Organism(int a, int b){

    xpos = a;
    ypos = b;
    stepCT = 0;


}


int Organism::getXpos(){

    return xpos;
}

int Organism::getYpos(){

    return ypos;
}

void Organism::setXpos(int a){

    xpos = a;
}

void Organism::setYpos(int a){

    ypos = a;
}

int Organism::getStepCT(){

    return stepCT;
}

void Organism::setStepCT(int a){

    stepCT = a;
}

void Organism::incStepCT(){

    stepCT = stepCT + 1;


}

/////

Doodlebug::Doodlebug(int a, int b) : Organism(a, b){

    ant_eaten = true;
    move_ct = 0;

}

void Doodlebug::move(Organism* temp[]){

    for (int i = 0; i < 5; i++){
        if (temp[i] != NULL && temp[i] != BORDER_UNIQUE_PTR){
                if (temp[i]->getID() == 2){
                    ant_eaten = true;

                    delete temp[i]; //Deallocate memory for ant

                    temp[i] = temp[0];
                    temp[0] = NULL;
                    incStepCT();

                    move_ct++;
                    if (move_ct > 3){
                        move_ct = 0;
                        ant_eaten = false;
                    }
                    breed(temp);
                    starve(temp);


                    return; //Exit function
                }
        }
    }

        int i = rand() % 5;

        if (temp[i] == NULL){
            temp[i] = temp[0];
            temp[0] = NULL;
                incStepCT();
        }else if (temp[i] != BORDER_UNIQUE_PTR){

            if (temp[i]->getID() == 3){
                //Do nothinging;
            }else if (temp[i]->getID() == 2){ //Must be an ant;
                ant_eaten = true;

                delete temp[i]; //Deallocate memory for ant

                temp[i] = temp[0];
                temp[0] = NULL;
                incStepCT();

            }
        }

    move_ct++;
    if (move_ct > 3){
        move_ct = 0;
        ant_eaten = false;
    }
    breed(temp);
    starve(temp);

}

Doodlebug::~Doodlebug(){

}

void Doodlebug::breed(Organism* temp[]){

    int mov = rand() % 5;
    if (getStepCT() % 8 == 0){
        if (temp[mov] == NULL && temp[mov] != BORDER_UNIQUE_PTR){
            temp[mov] = new Doodlebug(0, 0);

        }
    }

}

int Doodlebug::getID(){
    return 3;
}

void Doodlebug::starve(Organism* temp[]){

    if (ant_eaten){
        //Do nothing
    }else {
        temp[0] = NULL;



    }

}

/////////////////////////////////

Ant::Ant(int a, int b) : Organism(a, b){

}

Ant::~Ant(){

}

void Ant::breed(Organism* temp[]){

    int mov = rand() % 5;
    if (getStepCT() % 3 == 0){
        if (temp[mov] == NULL && temp[mov] != BORDER_UNIQUE_PTR){
            temp[mov] = new Ant(0, 0);

        }
    }

}

void Ant::move(Organism* temp[]){

int i = rand() % 5;

    if (temp[i] == NULL){

        temp[i] = temp[0];
        temp[0] = NULL;
        incStepCT();

    }else {
            //Do nothinging;
    }

  breed(temp);


}

int Ant::getID(){
    return 2;
}










































