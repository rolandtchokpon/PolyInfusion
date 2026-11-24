
#include "../../include/fabrique/FabriqueSysteme.h"

namespace Fabrique
{

    FabriqueSysteme::FabriqueSysteme() = default;

    FabriqueSysteme::~FabriqueSysteme() = default;

    std::unique_ptr<Machine::Systeme> FabriqueSysteme::creerSysteme() const
    {
        std::unique_ptr<Machine::Reserve> reserve = std::make_unique<Machine::Reserve>();
        std::unique_ptr<Machine::DistributeurEau> dEau = creerDistributeurEau(reserve.get());
        std::unique_ptr<Machine::DistributeurThe> dThe = creerDistributeurThe(reserve.get());
        std::unique_ptr<Machine::SystemeChauffage> chauffage = creerChauffage();

        return std::make_unique<Machine::Systeme>(nomModele(), reserve, dEau, dThe, chauffage);
    }

} // namespace Fabrique
