
#include <iostream>
#include <stdexcept>
#include <string>
#include "../../include/systeme/Systeme.h"
#include "../../include/util/Format.h"

namespace Machine
{

    Systeme::~Systeme() = default;

    Systeme::Systeme(const std::string &modele, std::unique_ptr<Reserve> &reserve, std::unique_ptr<DistributeurEau> &dEau,
                     std::unique_ptr<DistributeurThe> &dThe, std::unique_ptr<SystemeChauffage> &sysChauff) : reserve_(std::move(reserve)),
                                                                                                             distributeurEau_(std::move(dEau)),
                                                                                                             distributeurThe_(std::move(dThe)),
                                                                                                             systemeChauffage_(std::move(sysChauff)),
                                                                                                             profils_(std::make_unique<Profil::RegistreProfils>()),
                                                                                                             ecran_(std::make_unique<Notification::Ecran>()),
                                                                                                             app_(std::make_unique<Notification::AppDistant>()),
                                                                                                             portions_(1),
                                                                                                             quitter_(false),
                                                                                                             appAttache_(true)
    {
        // Une réserve de thé par profil d'infusion disponible.
        for (const std::string &nom : profils_->noms())
            reserve_->ajouterThe(nom);

        // Les alertes à l'écran sont toujours actives ; les notifications à distance le sont par défaut.
        reserve_->ajouterObservateur(ecran_.get());
        reserve_->ajouterObservateur(app_.get());

        std::cout << "Machine PolyInfusion démarrée : modèle " << modele << "." << std::endl;
    }

    void Systeme::infuser(const std::string &nomThe, unsigned int portions)
    {
        const Profil::ProfilInfusion *profil = profils_->trouver(nomThe);

        if (profil == nullptr)
            throw std::runtime_error("Erreur : aucun profil d'infusion pour le thé " + nomThe + ".");

        // Vérification de l'ensemble des portions (pertes du modèle incluses) avant toute consommation.
        const Profil::Besoins besoins = profil->besoins();
        distributeurEau_->verifierSuffisance(portions * besoins.eau);
        distributeurThe_->verifierSuffisance(nomThe, portions * besoins.the);

        Composants composants{*systemeChauffage_, *distributeurEau_, *distributeurThe_};

        for (unsigned int i = 0; i < portions; ++i)
            profil->preparer(composants);
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

} // namespace Machine
