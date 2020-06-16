#ifndef CARNIVORES2_H
#define CARNIVORES2_H


class Carnivores2
{
    public:
        static int population;
        static int eaten;
        static int starved;

        static const int speed = 3;
        static const int frequency = 2;
        static const int life = 2; //ποσοι γυροι εχουν περασει χωρισ να φαει

        Carnivores2();
        void setPopulation(int p);
        int getPopulation();
        int getEaten();
        int getStarved();

    protected:
    private:
};

#endif
