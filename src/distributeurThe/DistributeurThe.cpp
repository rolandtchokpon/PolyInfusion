
#include "../../include/distributeurThe/DistributeurThe.h"

namespace Machine {

    DistributeurThe::DistributeurThe(double ratioSurplus) :
        Notification::Notificateur(),
        ratio_(ratioSurplus)
    {
        reserves_.clear();
        ajouterThe(TheVert());
        ajouterThe(TheNoir());
        ajouterThe(TheOolong());
    }

    DistributeurThe::~DistributeurThe() = default;

    void DistributeurThe::distribuerThe(const std::string& the, double quantite) {
        double quantiteRequise = quantite * (1.0 + ratio_);

        reserves_[the].quantite -= quantiteRequise;

        std::cout << "Consommation de thé " << the << " : " << quantiteRequise << " g." << std::endl;

        this->notifier(the, reserves_[the].quantite);
    }

    void DistributeurThe::remplirThe(const std::string& the, double quantite) {
        reserves_[the].quantite += quantite;

        std::cout << "Ajout de thé " << the << " : " << quantite << " g." << std::endl;

        this->notifier(the, reserves_[the].quantite);
    }

    void DistributeurThe::afficherReserves() const {
        std::cout << "Réserves de thés :" << std::endl;
        for (const auto& pair : reserves_) {
            const The& the = pair.second;
            std::cout << "  - " << "Thé " << the.nom << " : " << the.quantite << " g." << std::endl;
        }
    }

    void DistributeurThe::activerNotifications(bool activer) { Notification::Notificateur::activerNotifications(activer); }

    void DistributeurThe::ajouterThe(const The& the) { reserves_[the.nom] = the; }

    void DistributeurThe::theSuffisant(const std::string& nomThe, double quantite) const {
        auto it = reserves_.find(nomThe);
        double quantiteRequise = quantite * (1.0 + ratio_);

        if (it == reserves_.end()) {
            throw TheInsuffisant(nomThe, quantiteRequise, 0.0);
        }
        
        const The& the = it->second;

        if (the.quantite < quantiteRequise) {
            throw TheInsuffisant(nomThe, quantiteRequise, the.quantite);
        }
    }

    const The& DistributeurThe::obtenirThe(const std::string& nomThe) const {
        auto it = reserves_.find(nomThe);

        if (it == reserves_.end()) {
            throw TheInsuffisant(nomThe, 0.0, 0.0);
        }

        return it->second;
    }

}  // namespace Machine