#ifndef HERBIVORES_H
#define HERBIVORES_H


class Herbivores
{
    public:
        static int population;
        static int eaten;
        static int starved;

        Herbivores();
        int getPopulation();
        int getEaten();
        int getStarved();
    protected:
    private:
};

#endif
