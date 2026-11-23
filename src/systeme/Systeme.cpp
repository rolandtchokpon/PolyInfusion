

#include <string>
#include <iostream>
#include "../../include/systeme/Systeme.h"

namespace Machine
{

    Systeme::~Systeme() = default;

    Systeme::Systeme(std::unique_ptr<Reserve> &reserve, std::unique_ptr<DistributeurEau> &dEau,
                     std::unique_ptr<DistributeurThe> &dThe, std::unique_ptr<SystemeChauffage> &sysChauff) : reserve_(std::move(reserve)),
                                                                                                             distributeurEau_(std::move(dEau)),
                                                                                                             distributeurThe_(std::move(dThe)),
                                                                                                             systemeChauffage_(std::move(sysChauff)),
                                                                                                             infuseur_(std::make_unique<Infuseur>(distributeurEau_.get(), distributeurThe_.get(), systemeChauffage_.get())),
                                                                                                             rinceur_(std::make_unique<Rinceur>(distributeurEau_.get(), distributeurThe_.get(), systemeChauffage_.get())),
                                                                                                             ecran_(std::make_unique<Notification::Ecran>(reserve_.get())),
                                                                                                             app_(std::make_unique<Notification::AppDistant>(reserve_.get())),
                                                                                                             portions_(1),
                                                                                                             quitter_(false)
    {
    }

    void Systeme::infuser(const std::string &nomThe)
    {
        const The &the = distributeurThe_->obtenirThe(nomThe);

        reserve_->eauSuffisante(the.volumeService + the.volumeRincage, distributeurEau_->obtenirRatio());
        reserve_->theSuffisant(the.nom, the.quantiteService, distributeurThe_->obtenirRatio());

        std::cout << "Préparation d'un thé " << the.nom << "." << std::endl;

        rinceur_->rincer(nomThe);
        infuseur_->infuser(nomThe);

        std::cout << "Service : " << the.volumeService << " mL." << std::endl;
        std::cout << "Votre thé est prêt." << std::endl;
    }

    void Systeme::remplirEau(double quantite) { reserve_->remplirEau(quantite); }

    void Systeme::remplirThe(const std::string &the, double quantite) { reserve_->remplirThe(the, quantite); }

    void Systeme::afficherReserves() const { reserve_->afficherReserves(); }

    void Systeme::activerNotifications(bool activer) { reserve_->activerNotifications(activer); }

    bool Systeme::quitter(bool oui)
    {
        if (oui)
        {
            std::cout << "Arrêt de PolyInfusion." << std::endl;
            quitter_ = oui;
        }

        return quitter_;
    }

    bool Systeme::doitQuitter() { return quitter_; }

    void Systeme::ajouterObservateur(Notification::Observateur *o) { reserve_->ajouterObservateur(o); }

    const std::string &Systeme::theSelectionne() const { return theSelectionne_; }

    unsigned int Systeme::portions() const { return portions_; }

    void Systeme::modifierPortions(unsigned int portions)
    {
        portions_ = portions;
        std::cout << "Nombre de portions : " << portions_ << std::endl;
    }

    void Systeme::modifierTheSelectionne(const std::string &the)
    {
        theSelectionne_ = the;
        std::cout << "Thé sélectionné : " << theSelectionne_ << std::endl;
    }

    void Systeme::appliquerRoutine(std::shared_ptr<Routine::IRoutine> &r)
    {
        if (r)
        {
            r->appliquer(this);
        }
    }

} // namespace Machine