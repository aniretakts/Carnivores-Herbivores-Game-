#ifndef HERBIVORES1_H
#define HERBIVORES1_H


class Herbivores1
{
    public:
       static int population;
        static int eaten;
        static int starved;

        static const int speed = 1;
        static const int frequency = 4;
        static const int life = 2;

        Herbivores1();
        void setPopulation(int p);
        int getPopulation();
        int getEaten();
        int getStarved();
    protected:
    private:
};

#endif
