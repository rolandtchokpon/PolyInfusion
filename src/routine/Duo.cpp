
#include "../../include/routine/Duo.h"
#include "../../include/systeme/Systeme.h"

namespace Routine
{

    Duo::Duo() = default;

    Duo::~Duo() = default;

    void Duo::appliquer(Machine::Systeme *sys) const
    {
        sys->modifierTheSelectionne("noir");
        sys->modifierPortions(2);
    }

}
