
#include "../../include/systeme/SystemePro.h"
#include "../../include/distributeurEau/DistributeurEauPro.h"
#include "../../include/distributeurThe/DistributeurThePro.h"
#include "../../include/systemeChauffage/SystemeChauffagePro.h"

namespace Machine
{

    SystemePro::SystemePro(std::unique_ptr<Reserve> &reserve, std::unique_ptr<DistributeurEau> &dEau,
                           std::unique_ptr<DistributeurThe> &dThe, std::unique_ptr<SystemeChauffage> &sysChauff) : Systeme(reserve, dEau, dThe, sysChauff)
    {
        std::cout << "Machine PolyInfusion démarrée : modèle Pro." << std::endl;
    }

    SystemePro::~SystemePro() = default;

} // namespace Machine