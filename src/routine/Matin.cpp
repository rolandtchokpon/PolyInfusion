
#include "../../include/routine/Matin.h"
#include "../../include/routine/Duo.h"
#include "../../include/systeme/Systeme.h"

namespace Routine
{

    Matin::Matin() = default;

    Matin::~Matin() = default;

    void Matin::appliquer(Machine::Systeme *sys) const
    {
        Duo().appliquer(sys);
        sys->modifierTheSelectionne("oolong");
    }

}
