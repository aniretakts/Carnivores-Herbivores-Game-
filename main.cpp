#include <iostream>
#include <string>
#include <stdlib.h>
#include "Animals.h"
#include "Simulator.h"
#include "Herbivores.h"
#include "Herbivores1.h"
#include "Herbivores2.h"
#include "Carnivores.h"
#include "Carnivores1.h"
#include "Carnivores2.h"

using namespace std;

int main(){
    //Δημιουργια του χαρτη
    int rows, cols;
    cout << "Give size of the map" << endl;
    cout << "Rows " << endl;
    cin >> rows;
    cout << "Columns " << endl;
    cin >> cols;
    int size = rows * cols;

    //string map[rows][cols];
    //Animals Objects[rows][cols];
   // bool plants[rows][cols];

    //Για δυναμικη παραχωρηση μνημης
    string **map;
    Animals **Objects;
    bool **plants;

    map = new string*[rows];
    Objects = new Animals*[rows];   //Πινακας με αντικειμενα
    plants = new bool*[rows];   //Πινακας τυπου boolean για τα φυτα

    int i, j, k;    //i,j συντεταγμενες και το k ειναι το καθε ζωο που τοποθετουμε
    for (i = 0; i < rows; i++){
        map[i] = new string[cols];
        Objects[i] = new Animals[cols];
        plants[i] = new bool[cols];
    }

    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    int total = 0;
    int plants_population = 0;

    do{             //τυχαια παραγωγη ζωων
        num1 = rand()%size + 1;
        num2 = rand()%size + 1;
        num3 = rand()%size + 1;
        num4 = rand()%size + 1;
        total = num1+num2+num3+num4;
    }while(total>size);     //Για να χωρέσουν όλα τα ζώα στον χάρτη

    plants_population = rand()%size + 1;     //Τυχαια παραγωγη φυτών

    //Αρχικός αριθμός ζώων
    Herbivores1::population=num1;//Πληθυσμός φυτοφάγων1
    Herbivores2::population=num2;//Πληθυσμός φυτοφάγων2
    Carnivores1::population=num3;//Πληθυσμός Σαρκοφάγων1
    Carnivores2::population=num4;//Πληθυσμός Σαρκοφάγων2

    //Τοποθετηση Φυτοφαγων1
    for (k = 0; k<num1; k++){
        do{
            i = rand() % rows;
            j = rand() % cols;
        } while (map[i][j] != "\0");
        map[i][j] = "H1";
        //Objects[i][j] = Herbivores1();
        *(*Objects+((unsigned int)i)+((unsigned int)j)) = Herbivores1();
    }
    cout << "H1 are now placed";

    //Τοποθετηση Φυτοφαγων2
    for (k = 0; k<num2; k++){
        do{
            i = rand() % rows;
            j = rand() % cols;
        } while (map[i][j] != "\0");
        map[i][j] = "H2";
        Objects[i][j] = Herbivores2();
    }
    cout << "H2 are now placed";

    //Τοποθετηση Σαρκοφαγων1
    for (k = 0; k<num3; k++){
        do{
            i = rand() % rows;
            j = rand() % cols;
        } while (map[i][j] != "\0");
        map[i][j] = "C1";
        Objects[i][j] = Carnivores1();
    }
    cout << "C1 are now placed";

    //Τοποθετηση Σαρκοφαγων2
    for (k = 0; k<num4; k++){
        do{
            i = rand() % rows;
            j = rand() % cols;
        } while (map[i][j] != "\0");
        map[i][j] = "C2";
        Objects[i][j] = Carnivores2();
    }
    cout << "C2 are now placed";

    //Τοποθετηση φυτων
    for (k = 0; k<plants_population; k++){
        do{
            i = rand() % rows;
            j = rand() % cols;
        } while (plants[i][j] != false);
        plants[i][j] = true;
    }
    cout << "Plants are now placed";

    //μεταβλητες για τον τερματισμο της προσομοιωσης
    bool flag = true;   //Το κανω αληθες για να τρεξει την πρωτη φορα
    string reason = ""; //μυνημα για αιτια τερματισμου της προσομοιωσης
    int round = 0;
    int hunger = 0; //ποσοι γυροι περασαν χωρις να εχει φαει καποιο ζωω

    while (flag){
        round++;    //αυξανω τον γυρο της προσομοιωσης

        cout << "Simulation round: " << round;

        //λειτουργιες
        for (i = 0; i<rows; i++){
            for (j = 0; j<cols; j++){
                Objects[i][j].feed(Objects, map, plants, plants_population, i, j, rows, cols, hunger);
                Objects[i][j].move(Objects, map, i, j, rows, cols);
                int freq = -1;
                if (map[i][j] == "C1"){
                    freq = Carnivores1::frequency;
                }
                else if (map[i][j] == "C2"){
                    freq = Carnivores2::frequency;
                }
                else if (map[i][j] == "H1"){
                    freq = Herbivores1::frequency;
                }
                else if (map[i][j] == "H2"){
                    freq = Herbivores2::frequency;
                }

                if (round%freq == 0)
                {
                    Objects[i][j].reproduce(Objects, map, i, j, rows, cols);
                }
            }
        }

        //¸Εμφανιση αιτιου τερματισμου
        if (Carnivores::getPopulation() == 0 && plants_population == 0){//endl;
            flag = false;   //κανει false τη flag για να σταματησει η προσομοιωση
            reason = "all carnivores and all plants died";
        }
        else if (Carnivores::getPopulation() == 0){
            flag = false;    //κανει false τη flag για να σταματησει η προσομοιωση
            reason = "all carnivores died";
        }
        else if (plants_population == 0){
            flag = false;    //κανει false τη flag για να σταματησει η προσομοιωση
            reason = "all plants died";
        }
    }

    cout << reason << endl; // αιτια τερματισμου
    cout << "Guros prosomoiwshs: " << round;    //γυρος προσομοιωσης

    Simulator sim;  //δημιουργια αντικειμενου της κλασης simulator

    //κληση μεθοδων
    sim.showEaten();
    sim.showStarved();
    sim.showPlants(plants_population, size);    //ποσοστο φυτων στον χαρτη
    sim.showPopulation();   //πληθυσμος καθε τυπου ζωων
    sim.showMap(rows, cols, map);   //εμφανιση χαρτη
}
