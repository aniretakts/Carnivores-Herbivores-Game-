#ifndef CARNIVORES_H
#define CARNIVORES_H


class Carnivores
{
    public:
        static int population;
        static int eaten;
        static int starved;

        Carnivores();
        int getPopulation();
        int getEaten();
        int getStarved();
    protected:
    private:
};

#endif
