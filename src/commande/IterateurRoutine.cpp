
#include "../../include/commande/IterateurRoutine.h"

namespace CMD
{

    IterateurRoutine::IterateurRoutine(const std::vector<std::shared_ptr<CmdReglage>> &enfants) : enfants_(enfants), position_(0) {}

    IterateurRoutine::~IterateurRoutine() = default;

    bool IterateurRoutine::aSuivant()
    {
        // Passe aux enfants suivants tant que l'itérateur courant est épuisé.
        while ((!courant_ || !courant_->aSuivant()) && position_ < enfants_.size())
            courant_ = enfants_[position_++]->creerIterateur();

        return courant_ && courant_->aSuivant();
    }

    const CmdReglage &IterateurRoutine::suivant()
    {
        aSuivant();
        return courant_->suivant();
    }

} // namespace CMD
