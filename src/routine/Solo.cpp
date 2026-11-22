
#include "../../include/routine/Solo.h"

namespace Routine
{
    const unsigned int PORTIONS = 1;
    const std::string THE = "vert";

    Solo::~Solo() = default;

    Solo::Solo() : IRoutine(PORTIONS, THE) {}

    void Solo::apercu() const
    {
        std::cout << "1. Sélectionner le thé " << the_ << "." << std::endl
                  << "2. Régler le nombre de portions à " << portions_ << "." << std::endl;
    }

    void Solo::appliquer(Machine::Systeme *sys, bool afficherModif) const
    {
        sys->modifierTheSelectionne(the_, afficherModif);
        sys->modifierPortions(portions_, afficherModif);
    }

}