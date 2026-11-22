
#include "../../include/notification/Ecran.h"

namespace Notification
{

    Ecran::Ecran(Machine::Reserve *reserve) : Observateur(),
                                              reserve_(reserve)
    {
    }

    Ecran::~Ecran() = default;

    void Ecran::notifier(double qte)
    {
        auto etat = reserve_->obtenirEtatEau();

        if (qte < SEUIL_QTE_EAU && etat == Machine::Etat::CORRECT)
        {
            if (notifActive_)
                std::cout << "[Ecran] Réserve d'eau faible : " << qte << " mL." << std::endl;
        }
        else if (qte >= SEUIL_QTE_EAU && etat == Machine::Etat::M_EAU)
        {
            if (notifActive_)
                std::cout << "[Ecran] Réserve d'eau de nouveau suffisante : " << qte << " mL." << std::endl;
        }
    }

    void Ecran::notifier(const std::string &the, double qte)
    {
        auto etat = reserve_->obtenirEtatThe(the);

        if (qte < SEUIL_QTE_THE && etat == Machine::Etat::CORRECT)
        {
            if (notifActive_)
                std::cout << "[Ecran] Réserve de the " << the << " faible : " << qte << " g." << std::endl;
        }
        else if (qte >= SEUIL_QTE_THE && etat == Machine::Etat::M_THE)
        {
            if (notifActive_)
                std::cout << "[Ecran] Réserve de the " << the << " de nouveau suffisante : " << qte << " g." << std::endl;
        }
    }

} // namespace Notification