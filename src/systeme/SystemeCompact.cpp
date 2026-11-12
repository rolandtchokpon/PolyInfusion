
#include "../../include/systeme/SystemeCompact.h"

namespace Machine {

    SystemeCompact::SystemeCompact(DistributeurEau* distributeurEau, DistributeurThe* distributeurThe, SystemeChauffage* systemeChauffage) :
        Systeme(distributeurEau, distributeurThe, systemeChauffage)    
    {
        std::cout <<  "Machine PolyInfusion démarrée : modèle Compact." << std::endl;
    }

    SystemeCompact::~SystemeCompact() = default;

} // namespace Machine