
#include "../../include/systemeChauffage/SystemeChauffagePro.h"

namespace Machine {

    const double VITESSE_CHAUFFAGE_PRO = 10.0; // °C par seconde

    SystemeChauffagePro::SystemeChauffagePro() : SystemeChauffage(VITESSE_CHAUFFAGE_PRO) {}

    SystemeChauffagePro::~SystemeChauffagePro() = default;

}  // namespace Machine