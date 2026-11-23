
#pragma once

#include "Observateur.h"

namespace Notification
{

    class AppDistant : public Observateur
    {
    public:
        AppDistant();
        ~AppDistant();

        virtual void alerterEau(Evenement evenement, double qte) override;
        virtual void alerterThe(Evenement evenement, const std::string &the, double qte) override;
    };

} // namespace Notification
