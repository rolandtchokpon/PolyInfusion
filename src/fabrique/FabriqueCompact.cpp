
#include "../../include/fabrique/FabriqueCompact.h"
#include "../../include/systemeChauffage/SystemeChauffageCompact.h"
#include "../../include/distributeurEau/DistributeurEauCompact.h"
#include "../../include/distributeurThe/DistributeurTheCompact.h"

namespace Fabrique
{

    FabriqueCompact::FabriqueCompact() = default;

    FabriqueCompact::~FabriqueCompact() = default;

    std::string FabriqueCompact::nomModele() const { return "Compact"; }

    std::unique_ptr<Machine::SystemeChauffage> FabriqueCompact::creerChauffage() const
    {
        return std::make_unique<Machine::SystemeChauffageCompact>();
    }

    std::unique_ptr<Machine::DistributeurEau> FabriqueCompact::creerDistributeurEau(Machine::Reserve *reserve) const
    {
        return std::make_unique<Machine::DistributeurEauCompact>(reserve);
    }

    std::unique_ptr<Machine::DistributeurThe> FabriqueCompact::creerDistributeurThe(Machine::Reserve *reserve) const
    {
        return std::make_unique<Machine::DistributeurTheCompact>(reserve);
    }

} // namespace Fabrique
