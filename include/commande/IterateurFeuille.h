
#pragma once
#include "IterateurReglage.h"

namespace CMD
{

    // Itérateur d'un changement élémentaire : il ne produit que lui-même.
    class IterateurFeuille : public IterateurReglage
    {
    public:
        explicit IterateurFeuille(const CmdReglage &reglage);
        ~IterateurFeuille();

        virtual bool aSuivant() override;
        virtual const CmdReglage &suivant() override;

    private:
        const CmdReglage &reglage_;
        bool consomme_;
    };

} // namespace CMD
