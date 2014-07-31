#ifndef ORGANISM_H
#define ORGANISM_H

#include <iostream>
#include <ctime>
#include <cstdlib>

static char uninit_sentinel;
#define BORDER_UNIQUE_PTR ((void *)&uninit_sentinel)


using namespace std;


class Organism{

    private:
        int xpos, ypos;
        int stepCT;

    public:
        Organism(int a, int b);
        virtual ~Organism(){};
        int getXpos();
        int getYpos();

        void setXpos(int a);
        void setYpos(int a);

        int getStepCT();
        void setStepCT(int a);
        void incStepCT();


        virtual void move(Organism* temp[]){}
        virtual void breed(Organism* temp[]){}
        virtual int getID(){} //ID of 2 is ant, ID of 3 is doodlebug

};

class Ant: public Organism{

    private:
        void breed(Organism* temp[]);


    public:
        Ant(int a, int b);
        ~Ant();
        void move(Organism* temp[]);
        int getID();


};

class  Doodlebug : public Organism{

    private:

        void starve(Organism* temp[]);
        bool ant_eaten;
        void breed(Organism* temp[]);
        int move_ct;

    public:

        Doodlebug(int a, int b);
        ~Doodlebug();
        void move(Organism* temp[]);
        int getID();


};

class world{

    private:
            Organism ***org_world;
            int ssx, ssy;
            static bool _rand_call;
    public:
            world(int sx, int sy);
            void Initialize(int doodle, int ant);
            void Run();
            void Draw();
};

#endif // ORGANISM_H
