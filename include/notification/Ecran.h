
#pragma once

#include "Observateur.h"

namespace Notification
{

    class Ecran : public Observateur
    {
    public:
        Ecran();
        ~Ecran();

        virtual void alerterEau(Evenement evenement, double qte) override;
        virtual void alerterThe(Evenement evenement, const std::string &the, double qte) override;
    };

} // namespace Notification
