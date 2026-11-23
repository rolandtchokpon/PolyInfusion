
#include <string>
#include <iostream>
#include "../../include/systeme/Systeme.h"
#include "../../include/util/Format.h"

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
                                                                                                             ecran_(std::make_unique<Notification::Ecran>()),
                                                                                                             app_(std::make_unique<Notification::AppDistant>()),
                                                                                                             portions_(1),
                                                                                                             quitter_(false),
                                                                                                             appAttache_(true)
    {
        // Les alertes à l'écran sont toujours actives ; les notifications à distance le sont par défaut.
        reserve_->ajouterObservateur(ecran_.get());
        reserve_->ajouterObservateur(app_.get());
    }

    void Systeme::infuser(const std::string &nomThe, unsigned int portions)
    {
        const The &the = distributeurThe_->obtenirThe(nomThe);

        // Vérification de l'ensemble des portions (pertes incluses) avant toute consommation.
        reserve_->eauSuffisante(portions * (the.volumeService + the.volumeRincage), distributeurEau_->obtenirRatio());
        reserve_->theSuffisant(the.nom, portions * the.quantiteService, distributeurThe_->obtenirRatio());

        for (unsigned int i = 0; i < portions; ++i)
        {
            std::cout << "Préparation d'un thé " << the.nom << "." << std::endl;

            rinceur_->rincer(nomThe);
            infuseur_->infuser(nomThe);

            std::cout << "Service : " << Util::nombre(the.volumeService) << " mL." << std::endl;
            std::cout << "Votre thé est prêt." << std::endl;
        }
    }

    void Systeme::remplirEau(double quantite) { reserve_->remplirEau(quantite); }

    void Systeme::remplirThe(const std::string &the, double quantite) { reserve_->remplirThe(the, quantite); }

    void Systeme::afficherReserves() const { reserve_->afficherReserves(); }

    void Systeme::activerNotifications(bool activer)
    {
        if (activer && !appAttache_)
        {
            reserve_->ajouterObservateur(app_.get());
            appAttache_ = true;
        }
        else if (!activer && appAttache_)
        {
            reserve_->retirerObservateur(app_.get());
            appAttache_ = false;
        }

        std::cout << "Notifications à distance " << (activer ? "activées." : "désactivées.") << std::endl;
    }

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

    void Systeme::modifierPortions(unsigned int portions) { portions_ = portions; }

    void Systeme::modifierTheSelectionne(const std::string &the) { theSelectionne_ = the; }

    void Systeme::appliquerRoutine(std::shared_ptr<Routine::IRoutine> &r)
    {
        if (r)
        {
            r->appliquer(this);
        }
    }

} // namespace Machine
