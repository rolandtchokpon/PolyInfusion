
#include "../../include/systeme/SystemeCompact.h"

namespace Machine {

    SystemeCompact::SystemeCompact(std::unique_ptr<Reserve> &reserve, std::unique_ptr<DistributeurEau> &dEau, std::unique_ptr<DistributeurThe> &dThe, std::unique_ptr<SystemeChauffage> &sysChauff) :
        Systeme(reserve, dEau, dThe, sysChauff)
    {
        std::cout << "Machine PolyInfusion démarrée : modèle Compact." << std::endl;
    }

    SystemeCompact::~SystemeCompact() = default;

} // namespace Machine
