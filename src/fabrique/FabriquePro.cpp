
#include "../../include/fabrique/FabriquePro.h"
#include "../../include/systemeChauffage/SystemeChauffagePro.h"
#include "../../include/distributeurEau/DistributeurEauPro.h"
#include "../../include/distributeurThe/DistributeurThePro.h"

namespace Fabrique
{

    FabriquePro::FabriquePro() = default;

    FabriquePro::~FabriquePro() = default;

    std::string FabriquePro::nomModele() const { return "Pro"; }

    std::unique_ptr<Machine::SystemeChauffage> FabriquePro::creerChauffage() const
    {
        return std::make_unique<Machine::SystemeChauffagePro>();
    }

    std::unique_ptr<Machine::DistributeurEau> FabriquePro::creerDistributeurEau(Machine::Reserve *reserve) const
    {
        return std::make_unique<Machine::DistributeurEauPro>(reserve);
    }

    std::unique_ptr<Machine::DistributeurThe> FabriquePro::creerDistributeurThe(Machine::Reserve *reserve) const
    {
        return std::make_unique<Machine::DistributeurThePro>(reserve);
    }

} // namespace Fabrique
