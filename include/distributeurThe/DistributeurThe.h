
#pragma once

#include <iostream>
#include <map>

#include "../notification/Notificateur.h"
#include "TheInsuffisant.h"

namespace Machine {
    
    class DistributeurThe : public Notification::Notificateur {
        public:
            virtual ~DistributeurThe() = 0;

            void distribuerThe(const std::string& the, double quantite);
            void remplirThe(const std::string& the, double quantite);
            void afficherReserves() const;
            void activerNotifications(bool activer);
            void ajouterThe(const The& the);
            void theSuffisant(const std::string& nomThe, double quantite) const;
            const The& obtenirThe(const std::string& nomThe) const;
        
        protected:
            DistributeurThe(double ratioSurplus);

            double ratio_;
            std::map<std::string, The> reserves_;
    };

} // namespace Machine