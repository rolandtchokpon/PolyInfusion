
#include "../../include/fabrique/FabriquePro.h"

namespace Fabrique
{

    FabriquePro::FabriquePro() = default;

    FabriquePro::~FabriquePro() = default;

    std::unique_ptr<Machine::Systeme> FabriquePro::creerSysteme()
    {
        std::unique_ptr<Machine::Reserve> reserve = std::make_unique<Machine::Reserve>();
        std::unique_ptr<Machine::DistributeurEau> dEau = std::make_unique<Machine::DistributeurEauPro>(reserve.get());
        std::unique_ptr<Machine::DistributeurThe> dThe = std::make_unique<Machine::DistributeurThePro>(reserve.get());
        std::unique_ptr<Machine::SystemeChauffage> chauffage = std::make_unique<Machine::SystemeChauffagePro>();

        return std::make_unique<Machine::SystemePro>(reserve, dEau, dThe, chauffage);
    }

} // namespace Fabrique
