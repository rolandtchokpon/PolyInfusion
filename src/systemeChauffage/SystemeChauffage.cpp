
#include "../../include/systemeChauffage/SystemeChauffage.h"

namespace Machine {

    SystemeChauffage::SystemeChauffage(double vitesse) : 
        vitesse_(vitesse) 
    {}

    SystemeChauffage::~SystemeChauffage() = default;

    void SystemeChauffage::chaufferEau(double temperature) {
        double tempsChauffage = temperature / vitesse_;

        std::cout << "Chauffage de l'eau de préparation à " << temperature << "°C : " 
                  << tempsChauffage << " secondes simulées." << std::endl;
    }

    void SystemeChauffage::chaufferEauRincage(double temperature) {
        double tempsChauffage = temperature / vitesse_;

        std::cout << "Chauffage de l'eau de rinçage à " << temperature << "°C : " 
                  << tempsChauffage << " secondes simulées." << std::endl;
    }

}  // namespace Machine