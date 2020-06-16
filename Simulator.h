#ifndef SIMULATOR_H
#define SIMULATOR_H


class Simulator
{
    public:
        Simulator();
        void showEaten();
        void showStarved();
        void showPlants(int plants_population, int size);
        void showPopulation();
        //void showMap(int rows, int cols,string **map);
        void showMap();
    protected:
    private:
};

#endif
