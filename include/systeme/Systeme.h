
#pragma once

#include "../preparation/Infuseur.h"
#include "../preparation/Rinceur.h"

namespace Machine {

    class Systeme {

        public:
            virtual ~Systeme();

            void infuser(const std::string& nomThe);
            void remplirThe(const std::string& nom, double quantite);
            void remplirEau(double quantite);
            void afficherReserves() const;
            void activerNotifications(bool activer);
            bool quitter(bool oui);
            void ajouterObservateur(Notification::Observateur* o);
        
        protected:
            Systeme(DistributeurEau* distributeurEau, DistributeurThe* distributeurThe, SystemeChauffage* systemeChauffage);
            virtual void dummy() = 0; // Méthode virtuelle pure pour rendre la classe abstraite

        private:
            DistributeurEau* distributeurEau_;
            DistributeurThe* distributeurThe_;
            SystemeChauffage* systemeChauffage_;
            Infuseur* infuseur_;
            Rinceur* rinceur_;
            bool quitter_;
    };

} // namespace Machine
