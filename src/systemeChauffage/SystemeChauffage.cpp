#include "../../include/systemeChauffage/SystemeChauffage.h"
#include "../../include/util/Format.h"

namespace Machine {

    const double TEMPERATURE_EAU_INITIALE = 20.0; // °C

    SystemeChauffage::SystemeChauffage(double vitesse) :
        vitesse_(vitesse)
    {}

    SystemeChauffage::~SystemeChauffage() = default;

    double SystemeChauffage::dureeChauffage(double temperature) const {
        return (temperature - TEMPERATURE_EAU_INITIALE) / vitesse_;
    }

    void SystemeChauffage::chaufferEau(double temperature) {
        std::cout << "Chauffage à " << Util::nombre(temperature) << " °C : "
                  << Util::nombre(dureeChauffage(temperature)) << " secondes simulées." << std::endl;
    }

    void SystemeChauffage::chaufferEauPreparation(double temperature) {
        std::cout << "Chauffage de l'eau de préparation à " << Util::nombre(temperature) << " °C : "
                  << Util::nombre(dureeChauffage(temperature)) << " secondes simulées." << std::endl;
    }

    void SystemeChauffage::chaufferEauRincage(double temperature) {
        std::cout << "Chauffage de l'eau de rinçage à " << Util::nombre(temperature) << " °C : "
                  << Util::nombre(dureeChauffage(temperature)) << " secondes simulées." << std::endl;
    }

}  // namespace Machine
