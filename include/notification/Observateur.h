
#pragma once

#include <iostream>
#include <string>

namespace Notification
{

    const double SEUIL_QTE_THE = 10.0;  // g
    const double SEUIL_QTE_EAU = 500.0; // mL

    enum class Evenement
    {
        Faible,
        Suffisante
    };

    // Textes communs aux destinataires des alertes de réserve.
    std::string messageEau(Evenement evenement, double qte);
    std::string messageThe(Evenement evenement, const std::string &the, double qte);

    class Observateur
    {
    public:
        virtual ~Observateur() = 0;
        virtual void alerterEau(Evenement evenement, double qte) = 0;
        virtual void alerterThe(Evenement evenement, const std::string &the, double qte) = 0;
    };

} // namespace Notification
