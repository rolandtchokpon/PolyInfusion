
#pragma once

#include <memory>
#include <string>

#include "../systeme/Systeme.h"
#include "../executeur/Executeur.h"
#include "../console/Console.h"

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

        std::unique_ptr<Execution::Executeur> creerExecuteur(Machine::Systeme *sys);
        std::unique_ptr<Console::InterfaceConsole> creerInterfaceConsole();

    protected:
        FabriqueSysteme();
    };

} // namespace Fabrique
