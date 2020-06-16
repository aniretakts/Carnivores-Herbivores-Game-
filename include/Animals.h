#ifndef ANIMALS_H
#define ANIMALS_H
#include <string>

class Animals
{
    public:
        Animals();
        void feed();
        void move();
        void reproduce();
        //void feed(Animals **Objects,string **map, bool **plants, int plants_population, int i, int j, int rows, int cols, int hunger);
        //void move(Animals **Objects, string **map, int i, int j, int rows, int cols);
        //void reproduce(Animals **Objects, string **map, int i, int j, int rows, int cols);
        int getHunger();
        void setHunger(int h);
    protected:
    private:
};

#endif
