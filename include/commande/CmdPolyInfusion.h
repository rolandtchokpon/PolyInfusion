#pragma once

#include <memory>
#include <string>
#include "Commande.h"
#include "../fabrique/FabriqueSysteme.h"

namespace CMD
{

    // Commande de démarrage « PolyInfusion <modèle> » : elle détermine la fabrique
    // du modèle demandé, puis s'en sert pour fabriquer le système.
    class CmdPolyInfusion : public Commande
    {
    public:
        explicit CmdPolyInfusion(const std::string &modele);
        ~CmdPolyInfusion();

        // Détermine la fabrique à utiliser selon le modèle ; lance std::invalid_argument si le modèle est inconnu.
        std::unique_ptr<Fabrique::FabriqueSysteme> creerFabrique() const;

        // Fabrique le système du modèle (le message de démarrage est affiché par Systeme).
        std::unique_ptr<Machine::Systeme> creerSysteme() const;

        // La machine existe déjà : le démarrage n'a plus de sens.
        virtual void executer(Machine::Systeme *sys) override;

    private:
        std::string modele_;
    };

} // namespace CMD