
#include "../../include/systemeChauffage/SystemeChauffageCompact.h"

namespace Machine {

    const double VITESSE_CHAUFFAGE_COMPACT = 5.0; // °C par seconde

    SystemeChauffageCompact::SystemeChauffageCompact() : SystemeChauffage(VITESSE_CHAUFFAGE_COMPACT) {}

    SystemeChauffageCompact::~SystemeChauffageCompact() = default;

}  // namespace Machine