

#include <string>
#include <iostream>
#include "../../include/systeme/Systeme.h"

namespace Machine {

    Systeme::~Systeme() {
        delete distributeurEau_;
        delete distributeurThe_;
        delete systemeChauffage_;
        delete infuseur_;
        delete rinceur_;
    };

    Systeme::Systeme(DistributeurEau* distributeurEau, DistributeurThe* distributeurThe, SystemeChauffage* systemeChauffage) :
        distributeurEau_(distributeurEau), 
        distributeurThe_(distributeurThe), 
        systemeChauffage_(systemeChauffage),
        infuseur_(new Infuseur(distributeurEau_, distributeurThe_, systemeChauffage_)),
        rinceur_(new Rinceur(distributeurEau_, distributeurThe_, systemeChauffage_)),
        quitter_(false)
    {}

    void Systeme::infuser(const std::string& nomThe) {
        const The& the = distributeurThe_->obtenirThe(nomThe);

        distributeurEau_->eauSuffisante(the.volumeService + the.volumeRincage);
        distributeurThe_->theSuffisant(the.nom, the.quantiteService);

        std::cout << "Préparation d'un thé " << the.nom << "." << std::endl;

        rinceur_->rincer(nomThe);
        infuseur_->infuser(nomThe);

        std::cout << "Service : " << the.volumeService << " mL." << std::endl;
        std::cout << "Votre thé est prêt." << std::endl;
    }

    void Systeme::remplirEau(double quantite) { distributeurEau_-> remplirEau(quantite); }

    void Systeme::remplirThe(const std::string& the, double quantite) { distributeurThe_->remplirThe(the, quantite); }

    void Systeme::afficherReserves() const {
        distributeurEau_->afficherReserves();
        distributeurThe_->afficherReserves();
    }

    void Systeme::activerNotifications(bool activer) {
        distributeurEau_->activerNotifications(activer);
        distributeurThe_->activerNotifications(activer);
    }

    bool Systeme::quitter(bool oui) {
        if (oui) {
            std::cout << "Arrêt de PolyInfusion" << std::endl;
            quitter_ = oui;
        }

        return quitter_;
    }

    void Systeme::ajouterObservateur(Notification::Observateur* o) {
        distributeurEau_->ajouterObservateur(o);
        distributeurThe_->ajouterObservateur(o);
    }

}  // namespace Machine