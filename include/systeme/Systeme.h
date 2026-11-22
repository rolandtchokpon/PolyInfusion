
#pragma once
#include <memory>
#include "../routine/IRoutine.h"
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

        void infuser();
        void remplirThe(const std::string &nom, double quantite);
        void remplirEau(double quantite);
        void afficherReserves() const;
        void activerNotifications(bool activer);
        bool quitter(bool oui);
        bool doitQuitter();
        void ajouterObservateur(Notification::Observateur *o);
        const std::string &theSelectionne() const;
        unsigned int portions() const;
        void modifierPortions(unsigned int portions, bool afficherModif);
        void modifierTheSelectionne(const std::string &the, bool afficherModif);
        void appliquerRoutine(std::shared_ptr<Routine::IRoutine> &r, bool afficherModif);

    protected:
        Systeme(std::unique_ptr<Reserve> &reserve, std::unique_ptr<DistributeurEau> &dEau, std::unique_ptr<DistributeurThe> &dThe, std::unique_ptr<SystemeChauffage> &sysChauff);

    private:
        std::unique_ptr<Reserve> reserve_;
        std::unique_ptr<DistributeurEau> distributeurEau_;
        std::unique_ptr<DistributeurThe> distributeurThe_;
        std::unique_ptr<SystemeChauffage> systemeChauffage_;
        std::unique_ptr<Infuseur> infuseur_;
        std::unique_ptr<Rinceur> rinceur_;
        std::unique_ptr<Notification::Observateur> ecran_;
        std::unique_ptr<Notification::Observateur> app_;

        unsigned int portions_;
        std::string theSelectionne_;
        bool quitter_;
    };

} // namespace Machine
