
#include "../../include/systeme/SystemePro.h"
#include "../../include/distributeurEau/DistributeurEauPro.h"
#include "../../include/distributeurThe/DistributeurThePro.h"
#include "../../include/systemeChauffage/SystemeChauffagePro.h"

namespace Machine {

    SystemePro::SystemePro(Reserve* reserve, DistributeurEau* dEau, DistributeurThe* dThe, SystemeChauffage* sysChauff) :
        Systeme(reserve, dEau, dThe, sysChauff)    
    {
        std::cout <<  "Machine PolyInfusion démarrée : modèle Pro." << std::endl;
    }

    SystemePro::~SystemePro() = default;

}  // namespace Machine