
#include "../../include/notification/AppDistant.h"

namespace Notification {

    AppDistant::AppDistant(Machine::DistributeurEau* dEau, Machine::DistributeurThe* dThe) :
        dEau_(dEau),
        dThe_(dThe)
    {}

    AppDistant::~AppDistant() = default;

    void AppDistant::notifier(double qte) {
        auto etat = dEau_->obtenirEtat();

        if (qte < SEUIL_QTE_EAU && etat == Etat::CORRECT) {
            dEau_->mettreEtat(Etat::M_EAU);
            std::cout << "[Notification distante] Réserve d'eau faible : " << qte << " mL." << std::endl;
        }
        else if (qte >= SEUIL_QTE_EAU && etat == Etat::M_EAU) {
            dEau_->mettreEtat(Etat::CORRECT);
            std::cout << "[Notification distante] Réserve d'eau de nouveau suffisante : " << qte << " mL." << std::endl;
        }
    }

    void AppDistant::notifier(const std::string& the, double qte) {
        auto etat = dThe_->obtenirEtat();

        if (qte < SEUIL_QTE_THE && etat == Etat::CORRECT) {
            dThe_->mettreEtat(Etat::M_THE);
            std::cout << "[Notification distante] Réserve de the " << the << " faible : " << qte << " g." << std::endl;
        }
        else if (qte >= SEUIL_QTE_THE && etat == Etat::M_THE) {
            dThe_->mettreEtat(Etat::CORRECT);
            std::cout << "[Notification distante] Réserve de the " << the << " de nouveau suffisante : " << qte << " g." << std::endl;
        }
    }

}  // namespace Notification