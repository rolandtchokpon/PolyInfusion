
#include "../../include/distributeurEau/DistributeurEau.h"

namespace Machine {

    const double QTE_EAU_INITIALE = 2000.0; // mL

    DistributeurEau::DistributeurEau(double ratioSurplus) :
        Notification::Notificateur(),
        ratio_(ratioSurplus), 
        quantiteEau_(QTE_EAU_INITIALE)
    {}

    DistributeurEau::~DistributeurEau() = default;

    void DistributeurEau::distribuerEau(double quantite) {
        double quantiteRequise = quantite * (1.0 + ratio_);

        quantiteEau_ -= quantiteRequise;

        std::cout << "Consommation d'eau : " << quantiteRequise << " mL" << std::endl;

        this->notifier(quantiteEau_);
    }

    void DistributeurEau::remplirEau(double quantite) {
        quantiteEau_ += quantite;

        std::cout << "Ajout d'eau : " << quantite << " mL" << std::endl;

        this->notifier(quantiteEau_);
    }

    void DistributeurEau::afficherReserves() const {
        std::cout << "Eau : " << quantiteEau_ << " mL" << std::endl;
    }

    void DistributeurEau::activerNotifications(bool activer) { Notification::Notificateur::activerNotifications(activer); }

    void DistributeurEau::eauSuffisante(double quantite) const {
        double quantiteRequise = quantite * (1.0 + ratio_);

        if (quantiteEau_ < quantiteRequise) {
            throw EauInsuffisante(quantiteRequise, quantiteEau_);
        }
    }

} // namespace Machine