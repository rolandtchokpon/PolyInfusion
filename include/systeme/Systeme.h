
#pragma once
#include <memory>
#include <string>
#include "../preparation/Infuseur.h"
#include "../preparation/Rinceur.h"
#include "../notification/Ecran.h"
#include "../notification/AppDistant.h"

namespace Machine
{

    class Systeme
    {

    public:
        virtual ~Systeme() = 0;

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

    protected:
        Systeme(std::unique_ptr<Reserve> &reserve, std::unique_ptr<DistributeurEau> &dEau, std::unique_ptr<DistributeurThe> &dThe, std::unique_ptr<SystemeChauffage> &sysChauff);

    private:
        std::unique_ptr<Reserve> reserve_;
        std::unique_ptr<DistributeurEau> distributeurEau_;
        std::unique_ptr<DistributeurThe> distributeurThe_;
        std::unique_ptr<SystemeChauffage> systemeChauffage_;
        std::unique_ptr<Infuseur> infuseur_;
        std::unique_ptr<Rinceur> rinceur_;
        std::unique_ptr<Notification::Ecran> ecran_;
        std::unique_ptr<Notification::AppDistant> app_;

        unsigned int portions_;
        std::string theSelectionne_;
        bool quitter_;
        bool appAttache_;
    };

} // namespace Machine
