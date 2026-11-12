
#pragma once

#include "../systeme/SystemeCompact.h"
#include "../systeme/SystemePro.h"
#include "../notification/AppDistant.h"
#include "../notification/Ecran.h"

namespace Fabrique {

    class FabriqueSysteme {
        public:
            FabriqueSysteme();
            ~FabriqueSysteme();

            Machine::Systeme* creerSysteme(const std::string& modele);
        
        private:
            Machine::Systeme* creerSystemeCompact();
            Machine::Systeme* creerSystemePro();

            Notification::Observateur* ecran_;
            Notification::Observateur* app_;
    };

} // namespace Fabrique