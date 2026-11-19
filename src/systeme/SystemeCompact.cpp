
#include "../../include/systeme/SystemeCompact.h"

namespace Machine {

    SystemeCompact::SystemeCompact(Reserve* reserve, DistributeurEau* dEau, DistributeurThe* dThe, SystemeChauffage* sysChauff) :
        Systeme(reserve, dEau, dThe, sysChauff)    
    {
        std::cout <<  "Machine PolyInfusion démarrée : modèle Compact." << std::endl;
    }

    SystemeCompact::~SystemeCompact() = default;

} // namespace Machine