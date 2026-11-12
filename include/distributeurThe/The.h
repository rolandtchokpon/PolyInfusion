
#pragma once

#include <string>

namespace Machine {

    struct The {
        std::string nom;
        double quantiteService = 5.0; // g
        double volumeRincage = 0.0; // mL
        double volumeService = 250.0; // mL
        double temperatureInfusion; // °C
        double tempsInfusion; // secondes

        double quantite = 20.0; // g
    };

    struct TheVert : public The {
        TheVert() {
            nom = "vert";
            temperatureInfusion = 80.0;
            tempsInfusion = 120.0;
        }
    };

    struct TheNoir : public The {
        TheNoir() {
            nom = "noir";
            temperatureInfusion = 95.0;
            tempsInfusion = 180.0;
        }
    };

    struct TheOolong : public The {
        TheOolong() {
            nom = "oolong";
            volumeRincage = 50.0;
            temperatureInfusion = 90.0;
            tempsInfusion = 90.0;
        }
    };

}