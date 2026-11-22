
#include "../../include/routine/Matin.h"
#include "../../include/routine/Duo.h"

namespace Routine
{
    const unsigned int PORTIONS = 2;
    const std::string THE = "oolong";

    Matin::~Matin() = default;

    Matin::Matin() : IRoutine(PORTIONS, THE) {}

    void Matin::apercu() const
    {
        auto r = Duo();
        r.apercu();

        std::cout << "3. Sélectionner le thé " << the_ << "." << std::endl;
    }

    void Matin::appliquer(Machine::Systeme *sys, bool afficherModif) const
    {
        auto r = Duo();
        r.appliquer(sys, afficherModif);
        sys->modifierTheSelectionne(the_, afficherModif);
    }

}