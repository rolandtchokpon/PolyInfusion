
#include "../../include/fabrique/FabriqueCompact.h"

namespace Fabrique
{
    FabriqueCompact::FabriqueCompact() = default;

    FabriqueCompact::~FabriqueCompact() = default;

    std::unique_ptr<Machine::Systeme> FabriqueCompact::creerSysteme()
    {
        std::unique_ptr<Machine::Reserve> reserve = std::make_unique<Machine::Reserve>();
        std::unique_ptr<Machine::DistributeurEau> dEau = std::make_unique<Machine::DistributeurEauCompact>(reserve.get());
        std::unique_ptr<Machine::DistributeurThe> dThe = std::make_unique<Machine::DistributeurTheCompact>(reserve.get());
        std::unique_ptr<Machine::SystemeChauffage> sysChauff = std::make_unique<Machine::SystemeChauffageCompact>();

        return std::make_unique<Machine::SystemeCompact>(reserve, dEau, dThe, sysChauff);
    }

} // namespace Fabrique