
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Observateur.h"

namespace Notification
{

    enum class Etat
    {
        M_EAU,
        M_THE,
        CORRECT
    };

    class Notificateur
    {
    public:
        virtual ~Notificateur() = 0;

        void activerNotifications(bool aciver);
        void ajouterObservateur(Observateur *o);
        void retirerObservateur(Observateur *o);
        Etat obtenirEtatEau();
        Etat obtenirEtatThe();
        void mettreEtatEau(Etat e);
        void mettreEtatThe(Etat e);

    protected:
        Notificateur();

        virtual void notifier(double qte);
        virtual void notifier(const std::string &the, double qte);

        std::vector<Observateur *> observateurs_;
        Etat etatEau_;
        Etat etatThe_;
        bool notificationsActives_;
    };

} // namespace Notification