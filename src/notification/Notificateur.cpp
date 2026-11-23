
#include "../../include/notification/Notificateur.h"
#include <algorithm>

namespace Notification
{

    Notificateur::Notificateur() : eauFaible_(false) {}

    Notificateur::~Notificateur() = default;

    void Notificateur::ajouterObservateur(Observateur *o)
    {
        if (std::find(observateurs_.begin(), observateurs_.end(), o) == observateurs_.end())
            observateurs_.push_back(o);
    }

    void Notificateur::retirerObservateur(Observateur *o)
    {
        observateurs_.erase(std::remove(observateurs_.begin(), observateurs_.end(), o), observateurs_.end());
    }

    void Notificateur::verifierEau(double qte)
    {
        const bool faible = qte < SEUIL_QTE_EAU;

        if (faible == eauFaible_)
            return; // Pas de nouvelle alerte tant que l'état ne change pas.

        eauFaible_ = faible;
        const Evenement evenement = faible ? Evenement::Faible : Evenement::Suffisante;

        for (Observateur *o : observateurs_)
            o->alerterEau(evenement, qte);
    }

    void Notificateur::verifierThe(const std::string &the, double qte)
    {
        const bool faible = qte < SEUIL_QTE_THE;
        bool &etat = theFaible_[the];

        if (faible == etat)
            return;

        etat = faible;
        const Evenement evenement = faible ? Evenement::Faible : Evenement::Suffisante;

        for (Observateur *o : observateurs_)
            o->alerterThe(evenement, the, qte);
    }

} // namespace Notification
