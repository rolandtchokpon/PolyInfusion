
#pragma once

#include <string>
#include "../systeme/Composants.h"

namespace Profil
{

    // Quantités nominales (sans pertes) nécessaires à une portion.
    struct Besoins
    {
        double eau; // mL
        double the; // g
    };

    // Patron Strategy : chaque profil détermine les paramètres et les étapes de la préparation
    // d'une portion (patron de méthode : annoncer, rincer, infuser, servir).
    class ProfilInfusion
    {
    public:
        virtual ~ProfilInfusion() = 0;

        const std::string &nom() const;
        Besoins besoins() const;

        // Prépare une portion avec les composants du modèle courant.
        void preparer(Machine::Composants &composants) const;

    protected:
        ProfilInfusion(const std::string &nom, double temperature, double tempsInfusion, double volumeRincage = 0.0);

        // Étapes variables : par défaut, pas de rinçage et infusion directe.
        virtual void rincer(Machine::Composants &composants) const;
        virtual void infuser(Machine::Composants &composants) const;

        std::string nom_;
        double quantiteService_ = 5.0; // g
        double volumeService_ = 250.0; // mL
        double volumeRincage_;         // mL
        double temperature_;           // °C
        double tempsInfusion_;         // s
    };

} // namespace Profil
