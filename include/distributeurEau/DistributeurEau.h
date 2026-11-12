#pragma once

#include <iostream>
#include <map>

#include "../notification/Notificateur.h"
#include "EauInsuffisante.h"

namespace Machine {

    class DistributeurEau : public Notification::Notificateur {
        public:
            virtual ~DistributeurEau() = 0;

            void distribuerEau(double quantite);
            void remplirEau(double quantite);
            void afficherReserves() const;
            void activerNotifications(bool activer);
            void eauSuffisante(double quantite) const;
        
        protected:
            DistributeurEau(double ratioSurplus);

            double ratio_;
            double quantiteEau_;
    };

} // namespace Machine