#ifndef HERBIVORES2_H
#define HERBIVORES2_H


class Herbivores2
{
    public:
        static int population;
        static int eaten;
        static int starved;

        static const int speed = 2;
        static const int frequency = 3;
        static const int life = 5;

        Herbivores2();
        void setPopulation(int p);
        int getPopulation();
        int getEaten();
        int getStarved();
    protected:
    private:
};

#endif
