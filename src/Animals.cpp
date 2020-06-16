#include <iostream>
#include <string>
#include <stdlib.h>
#include "Animals.h"
#include "Simulator.h"
#include "Herbivores.h"
#include "Carnivores.h"

using namespace std;

Animals::Animals()
{
}

static int starved;
int hunger = 0;     //ποσοι γυροι εχουν περασει χωρισ να φαει κατι το ζωω
    void Animals::feed(Animals **Objects, string **map, bool **plants, int plants_population, int i, int j, int rows, int cols, int hunger){
        int life = 0;
        if (map[i][j] == "C1"){
            life = Carnivores1::life;
        }
        else if (map[i][j] == "C2"){
            life = Carnivores2::life;
        }
        else if (map[i][j] == "H1"){
            life = Herbivores1::life;
        }
        else if (map[i][j] == "H2"){
            life = Herbivores2::life;
        }

         //Για τα φυτοφάγα
        if ((map[i][j] == "H1" || map[i][j] == "H2")){
            if (plants[i][j] == true){
                plants[i][j] = false;
                plants_population--;
            }
            else{
                hunger++;
                Objects[i][j].setHunger(hunger);

                if (Objects[i][j]::getHunger()>life){
                    Objects[i][j]::starved++;
                }
            }
        }

        //Για τα σαρκοφάγα
        if (map[i][j] == "C1" || map[i][j] == "C2"){
            if (i - 1>0){
                if (map[i - 1][j] == "H1"){
                    map[i - 1][j] = map[i][j];
                    map[i][j] = "\0";
                    Objects[i - 1][j] = Objects[i][j];
                    Objects[i][j] = "\0";
                    Objects[i - 1][j]::setHunger(0);
                    Herbivores1::population--;
                    Herbivores::population--;
                    Herbivores1::eaten++;
                }
                else if (map[i - 1][j] == "H2"){
                    map[i - 1][j] = map[i][j];
                    map[i][j] = "\0";
                    Objects[i - 1][j] = Objects[i][j];
                    Objects[i][j] = "\0";
                    Objects[i - 1][j].setHunger(0);
                    Herbivores2::population--;
                    Herbivores::population--;
                    Herbivores2::eaten++;
                }
            }
            else if (j + 1<cols){
                if (map[i][j + 1] == "H1"){
                    map[i][j + 1] = map[i][j];
                    map[i][j] = "\0";
                    Objects[i][j + 1] = Objects[i][j];
                    Objects[i][j] = "\0";
                    Objects[i][j + 1].setHunger(0);
                    Herbivores1::population--;
                    Herbivores::population--;
                    Herbivores1::eaten++;
                }
                else if (map[i][j + 1] == "H2"){
                    map[i][j + 1] = map[i][j];
                    map[i][j] = "\0";
                    Objects[i][j + 1] = Objects[i][j];
                    Objects[i][j] = "\0";
                    Objects[i][j + 1].setHunger(0);
                    Herbivores2::population--;
                    Herbivores::population--;
                    Herbivores2::eaten++;
                }
            }
            else if (i + 1<rows){
                if (map[i + 1][j] == "H1"){
                    map[i + 1][j] = map[i][j];
                    map[i][j] = "\0";
                    Objects[i + 1][j] = Objects[i][j];
                    Objects[i][j] = "\0";
                    Objects[i + 1][j].setHunger(0);
                    Herbivores1::population--;
                    Herbivores::population--;
                    Herbivores1::eaten++;
                }
                else if (map[i + 1][j] == "H2"){
                    map[i + 1][j] = map[i][j];
                    map[i][j] = "\0";
                    Objects[i + 1][j] = Objects[i][j];
                    Objects[i][j] = "\0";
                    Objects[i + 1][j].setHunger(0);
                    Herbivores2::population--;
                    Herbivores::population--;
                    Herbivores2::eaten++;
                }
            }
            else if (j - 1>0){
                if (map[i][j - 1] == "H1"){
                    map[i][j - 1] = map[i][j];
                    map[i][j] = "\0";
                    Objects[i][j - 1] = Objects[i][j];
                    Objects[i][j] = "\0";
                    Objects[i][j + 1].setHunger(0);
                    Herbivores1::population--;
                    Herbivores::population--;
                    Herbivores1::eaten++;
                }
                else if (map[i][j - 1] == "H2"){
                    map[i][j - 1] = map[i][j];
                    map[i][j] = "\0";
                    Objects[i][j - 1] = Objects[i][j];
                    Objects[i][j] = "\0";
                    Objects[i][j - 1].setHunger(0);
                    Herbivores2::population--;
                    Herbivores::population--;
                    Herbivores2::eaten++;
                }
            }
            else{
                hunger++;
                Objects[i][j].setHunger(hunger);
                if (Objects[i][j].getHunger()>life){
                    Objects[i][j].starved++;
                    Objects[i][j] = "\0";
                    map[i][j] = "\0";
                }
            }
        }   //end of feed
    }

    void Animals::move(Animals **Objects, string **map, int i, int j, int rows, int cols){
        if (map[i][j] != "\0"){
            int speed = 0;

            if (map[i][j] == "C1"){
                speed = Carnivores1::speed;
            }
            else if (map[i][j] == "C2"){
                speed = Carnivores2::speed;
            }
            else if (map[i][j] == "H1"){
                speed = Herbivores1::speed;
            }
            else if (map[i][j] == "H2"){
                speed = Herbivores2::speed;
            }

            if (i - speed>0){
                if (map[i - speed][j] == "\0"){
                    map[i - speed][j] = map[i][j];
                    map[i][j] = "\0";
                    Objects[i - speed][j] = Objects[i][j];
                    Objects[i][j] = "\0";
                }
            }
            else if (j + speed<cols){
                if (map[i][j + speed] == "\0"){
                    map[i][j + speed] = map[i][j];
                    map[i][j] = "\0";
                    Objects[i][j + speed] = Objects[i][j];
                    Objects[i][j] = "\0";
                }
            }
            else if (i + speed<rows){
                if (map[i + speed][j] == "\0"){
                    map[i + speed][j] = map[i][j];
                    map[i][j] = "\0";
                    Objects[i + speed][j] = Objects[i][j];
                    Objects[i][j] = "\0";
                }
            }
            else if (j - speed>0){
                if (map[i - speed][j] == "\0"){
                    map[i - speed][j] = map[i][j];
                    map[i][j] = "\0";
                    Objects[i][j - speed] = Objects[i][j];
                    Objects[i][j] = "\0";
                }
            }
        }
    }   //end of move

   void Animals::reproduce(Animals **Objects, string **map, int i, int j, int rows, int cols){
        if (map[i][j] != "\0"){
            if (i - 1>0){
                if (map[i - 1][j] == "\0"){
                    map[i - 1][j] = map[i][j];
                    Objects[i - 1][j] = Objects[i][j];
                    Objects[i - 1][j].setHunger(0);
                }
            }
            else if (j + 1<cols){
                if (map[i][j + 1] == "\0"){
                    map[i][j + 1] = map[i][j];
                    Objects[i][j + 1] = Objects[i][j];
                    Objects[i][j + 1].setHunger(0);
                }
            }
            else if (i + 1<rows){
                if (map[i + 1][j] == "\0"){
                    map[i + 1][j] = map[i][j];
                    Objects[i + 1][j] = Objects[i][j];
                    Objects[i + 1][j].setHunger(0);
                }
            }
            else if (j - 1>0){
                if (map[i][j - 1] == "\0"){
                    map[i][j - 1] = map[i][j];
                    Objects[i][j - 1] = Objects[i][j];
                    Objects[i][j - 1].setHunger(0);
                }
            }
        }
    }   //end of reproduce

    int Animals::getHunger(){
        return hunger;
    }
    void Animls::setHunger(int h){
        hunger = h;
    }

