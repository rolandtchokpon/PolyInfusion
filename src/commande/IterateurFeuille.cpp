
#include "../../include/commande/IterateurFeuille.h"

namespace CMD
{

    IterateurFeuille::IterateurFeuille(const CmdReglage &reglage) : reglage_(reglage), consomme_(false) {}

    IterateurFeuille::~IterateurFeuille() = default;

    bool IterateurFeuille::aSuivant() { return !consomme_; }

    const CmdReglage &IterateurFeuille::suivant()
    {
        consomme_ = true;
        return reglage_;
    }

} // namespace CMD
