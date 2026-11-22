
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Observateur.h"

namespace Notification
{

    class Notificateur
    {
    public:
        virtual ~Notificateur() = 0;

        void ajouterObservateur(Observateur *o);
        void retirerObservateur(Observateur *o);

    protected:
        Notificateur();

        virtual void notifier(double qte);
        virtual void notifier(const std::string &the, double qte);
        
        std::vector<Observateur *> observateurs_;
    };

} // namespace Notification