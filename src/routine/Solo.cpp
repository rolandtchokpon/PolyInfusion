
#include "../../include/routine/Solo.h"
#include "../../include/systeme/Systeme.h"

namespace Routine
{

    Solo::Solo() = default;

    Solo::~Solo() = default;

    void Solo::appliquer(Machine::Systeme *sys) const
    {
        sys->modifierTheSelectionne("vert");
        sys->modifierPortions(1);
    }

}
