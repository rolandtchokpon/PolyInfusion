
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Observateur.h"

namespace Notification {

    enum class Etat { M_EAU, M_THE, CORRECT };

    class Notificateur {
        public:
            virtual ~Notificateur() = 0;

            void activerNotifications(bool aciver);
            void ajouterObservateur(Observateur* o);
            void retirerObservateur(Observateur* o);
            Etat obtenirEtat();
            void mettreEtat(Etat e);
        
        protected:
            Notificateur();

            virtual void notifier(double qte);
            virtual void notifier(const std::string& the, double qte);

            std::vector<Observateur*> observateurs_;
            Etat etat_;
            bool notificationsActives_;
    };

}  // namespace Notification