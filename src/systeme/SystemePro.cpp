
#include "../../include/systeme/SystemePro.h"
#include "../../include/distributeurEau/DistributeurEauPro.h"
#include "../../include/distributeurThe/DistributeurThePro.h"
#include "../../include/systemeChauffage/SystemeChauffagePro.h"

namespace Machine {

    SystemePro::SystemePro(DistributeurEau* distributeurEau, DistributeurThe* distributeurThe, SystemeChauffage* systemeChauffage) :
        Systeme(distributeurEau, distributeurThe, systemeChauffage)    
    {
        std::cout <<  "Machine PolyInfusion démarrée : modèle Pro." << std::endl;
    }

    SystemePro::~SystemePro() = default;

}  // namespace Machine