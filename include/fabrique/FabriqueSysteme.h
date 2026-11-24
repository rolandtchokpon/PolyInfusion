
#pragma once

#include <memory>
#include <string>

#include "../systeme/Systeme.h"

namespace Fabrique
{

    // Patron Abstract Factory : chaque fabrique concrète fournit l'ensemble cohérent de composants
    // d'un modèle. Ajouter un modèle = ajouter une fabrique ; ni les profils ni Systeme ne changent.
    class FabriqueSysteme
    {
    public:
        virtual ~FabriqueSysteme();

        virtual std::string nomModele() const = 0;
        virtual std::unique_ptr<Machine::SystemeChauffage> creerChauffage() const = 0;
        virtual std::unique_ptr<Machine::DistributeurEau> creerDistributeurEau(Machine::Reserve *reserve) const = 0;
        virtual std::unique_ptr<Machine::DistributeurThe> creerDistributeurThe(Machine::Reserve *reserve) const = 0;

        // Assemble une machine avec les composants du modèle.
        std::unique_ptr<Machine::Systeme> creerSysteme() const;

    protected:
        FabriqueSysteme();
    };

} // namespace Fabrique
