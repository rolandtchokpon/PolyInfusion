
#pragma once
#include <memory>
#include <string>
#include "Composants.h"
#include "../profil/RegistreProfils.h"
#include "../reserve/Reserve.h"
#include "../notification/Ecran.h"
#include "../notification/AppDistant.h"

namespace Machine
{

    // La machine : elle coordonne les composants fournis par la fabrique du modèle
    // et les profils d'infusion, sans connaître ni le modèle ni les profils concrets.
    class Systeme
    {

    public:
        Systeme(const std::string &modele, std::unique_ptr<Reserve> &reserve, std::unique_ptr<DistributeurEau> &dEau,
                std::unique_ptr<DistributeurThe> &dThe, std::unique_ptr<SystemeChauffage> &sysChauff);
        ~Systeme();

        // Prépare `portions` portions du thé ; refuse sans rien consommer
        // si les réserves ne suffisent pas pour l'ensemble des portions.
        void infuser(const std::string &nomThe, unsigned int portions = 1);
        void remplirThe(const std::string &nom, double quantite);
        void remplirEau(double quantite);
        void afficherReserves() const;
        void activerNotifications(bool activer);
        bool quitter(bool oui);
        bool doitQuitter();
        void ajouterObservateur(Notification::Observateur *o);
        const std::string &theSelectionne() const;
        unsigned int portions() const;
        void modifierPortions(unsigned int portions);
        void modifierTheSelectionne(const std::string &the);

    private:
        std::unique_ptr<Reserve> reserve_;
        std::unique_ptr<DistributeurEau> distributeurEau_;
        std::unique_ptr<DistributeurThe> distributeurThe_;
        std::unique_ptr<SystemeChauffage> systemeChauffage_;
        std::unique_ptr<Profil::RegistreProfils> profils_;
        std::unique_ptr<Notification::Ecran> ecran_;
        std::unique_ptr<Notification::AppDistant> app_;

        unsigned int portions_;
        std::string theSelectionne_;
        bool quitter_;
        bool appAttache_;
    };

} // namespace Machine
