
#include "../../include/routine/Duo.h"

namespace Routine
{
    const unsigned int PORTIONS = 2;
    const std::string THE = "noir";

    Duo::~Duo() = default;

    Duo::Duo() : IRoutine(PORTIONS, THE) {}

    void Duo::apercu() const
    {
        std::cout << "1. Sélectionner le thé " << the_ << "." << std::endl
                  << "2. Régler le nombre de portions à " << portions_ << "." << std::endl;
    }

    void Duo::appliquer(Machine::Systeme *sys, bool afficherModif) const
    {
        sys->modifierTheSelectionne(the_, afficherModif);
        sys->modifierPortions(portions_, afficherModif);
    }

}