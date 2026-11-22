
#include "../../include/notification/AppDistant.h"

namespace Notification
{

    AppDistant::AppDistant(Machine::Reserve *reserve) : Observateur(),
                                                        reserve_(reserve)
    {
    }

    AppDistant::~AppDistant() = default;

    void AppDistant::notifier(double qte)
    {
        auto etat = reserve_->obtenirEtatEau();

        if (qte < SEUIL_QTE_EAU && etat == Machine::Etat::CORRECT)
        {
            reserve_->mettreEtatEau(Machine::Etat::M_EAU);
            if (notifActive_)
                std::cout << "[Notification distante] Réserve d'eau faible : " << qte << " mL." << std::endl;
        }
        else if (qte >= SEUIL_QTE_EAU && etat == Machine::Etat::M_EAU)
        {
            reserve_->mettreEtatEau(Machine::Etat::CORRECT);
            if (notifActive_)
                std::cout << "[Notification distante] Réserve d'eau de nouveau suffisante : " << qte << " mL." << std::endl;
        }
    }

    void AppDistant::notifier(const std::string &the, double qte)
    {
        auto etat = reserve_->obtenirEtatThe(the);

        if (qte < SEUIL_QTE_THE && etat == Machine::Etat::CORRECT)
        {
            reserve_->mettreEtatThe(the, Machine::Etat::M_THE);
            if (notifActive_)
                std::cout << "[Notification distante] Réserve de the " << the << " faible : " << qte << " g." << std::endl;
        }
        else if (qte >= SEUIL_QTE_THE && etat == Machine::Etat::M_THE)
        {
            reserve_->mettreEtatThe(the, Machine::Etat::CORRECT);
            if (notifActive_)
                std::cout << "[Notification distante] Réserve de the " << the << " de nouveau suffisante : " << qte << " g." << std::endl;
        }
    }

} // namespace Notification