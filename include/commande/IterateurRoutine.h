
#pragma once
#include <cstddef>
#include <memory>
#include <vector>
#include "IterateurReglage.h"
#include "CmdReglage.h"

namespace CMD
{

    // Parcourt les changements élémentaires d'une routine dans leur ordre d'exécution.
    // Une sous-routine est parcourue par son propre itérateur : ni la routine ni l'appelant
    // n'ont besoin de connaître la structure de l'arbre.
    class IterateurRoutine : public IterateurReglage
    {
    public:
        explicit IterateurRoutine(const std::vector<std::shared_ptr<CmdReglage>> &enfants);
        ~IterateurRoutine();

        virtual bool aSuivant() override;
        virtual const CmdReglage &suivant() override;

    private:
        std::vector<std::shared_ptr<CmdReglage>> enfants_;
        std::size_t position_;
        std::unique_ptr<IterateurReglage> courant_;
    };

} // namespace CMD
