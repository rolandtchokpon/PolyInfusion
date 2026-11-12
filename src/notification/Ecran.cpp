
#include "../../include/notification/Ecran.h"

namespace Notification {

    Ecran::Ecran(Machine::DistributeurEau* dEau, Machine::DistributeurThe* dThe) :
        dEau_(dEau),
        dThe_(dThe)
    {}

    Ecran::~Ecran() = default;

    void Ecran::notifier(double qte) {
        auto etat = dEau_->obtenirEtat();

        if (qte < SEUIL_QTE_EAU && etat == Etat::CORRECT) {
            std::cout << "[Ecran] Réserve d'eau faible : " << qte << " mL." << std::endl;
        }
        else if (qte >= SEUIL_QTE_EAU && etat == Etat::M_EAU) {
            std::cout << "[Ecran] Réserve d'eau de nouveau suffisante : " << qte << " mL." << std::endl;
        }
    }

    void Ecran::notifier(const std::string& the, double qte) {
        auto etat = dThe_->obtenirEtat();

        if (qte < SEUIL_QTE_THE && etat == Etat::CORRECT) {
            std::cout << "[Ecran] Réserve de the " << the << " faible : " << qte << " g." << std::endl;
        }
        else if (qte >= SEUIL_QTE_THE && etat == Etat::M_THE) {
            std::cout << "[Ecran] Réserve de the " << the << " de nouveau suffisante : " << qte << " g." << std::endl;
        }
    }

}  // namespace Notification