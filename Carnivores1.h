#ifndef CARNIVORES1_H
#define CARNIVORES1_H


class Carnivores1
{
    public:
    static int population;
    static int eaten;
    static int starved;

    static const int speed = 3;
    static const int frequency = 2;
    static const int life = 5;  //ποσοι γυροι εχουν περασει χωρισ να φαει

        Carnivores1();
        void setPopulation(int p);
        int getPopulation();
        int getEaten();
        int getStarved();
    protected:
    private:
};

#endif
