
#include "../../include/notification/AppDistant.h"

namespace Notification {

    AppDistant::AppDistant(Machine::Reserve* reserve) :
        reserve_(reserve)
    {}

    AppDistant::~AppDistant() = default;

    void AppDistant::notifier(double qte) {
        auto etat = reserve_->obtenirEtatEau();

        if (qte < SEUIL_QTE_EAU && etat == Etat::CORRECT) {
            reserve_->mettreEtatEau(Etat::M_EAU);
            std::cout << "[Notification distante] Réserve d'eau faible : " << qte << " mL." << std::endl;
        }
        else if (qte >= SEUIL_QTE_EAU && etat == Etat::M_EAU) {
            reserve_->mettreEtatEau(Etat::CORRECT);
            std::cout << "[Notification distante] Réserve d'eau de nouveau suffisante : " << qte << " mL." << std::endl;
        }
    }

    void AppDistant::notifier(const std::string& the, double qte) {
        auto etat = reserve_->obtenirEtatThe();

        if (qte < SEUIL_QTE_THE && etat == Etat::CORRECT) {
            reserve_->mettreEtatThe(Etat::M_THE);
            std::cout << "[Notification distante] Réserve de the " << the << " faible : " << qte << " g." << std::endl;
        }
        else if (qte >= SEUIL_QTE_THE && etat == Etat::M_THE) {
            reserve_->mettreEtatThe(Etat::CORRECT);
            std::cout << "[Notification distante] Réserve de the " << the << " de nouveau suffisante : " << qte << " g." << std::endl;
        }
    }

}  // namespace Notification