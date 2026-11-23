
#pragma once

#include "../systemeChauffage/SystemeChauffage.h"
#include "../distributeurEau/DistributeurEau.h"
#include "../distributeurThe/DistributeurThe.h"

namespace Machine
{

    // Les opérations propres au matériel sont réalisées par ces composants ;
    // les profils d'infusion s'en servent sans connaître le modèle de la machine.
    struct Composants
    {
        SystemeChauffage &chauffage;
        DistributeurEau &eau;
        DistributeurThe &the;
    };

} // namespace Machine
