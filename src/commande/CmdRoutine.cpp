
#include "../../include/commande/CmdRoutine.h"

namespace CMD
{

    CmdRoutine::CmdRoutine() : Commande(true) {}

    CmdRoutine::~CmdRoutine() = default;

    void CmdRoutine::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        instruction_ = inst;
        portionsAvant_ = sys->portions();
        theAvant_ = sys->theSelectionne();

        auto routine = lireRoutine(inst.routine);
        sys->appliquerRoutine(routine);
    }

    void CmdRoutine::undo(Machine::Systeme *sys)
    {
        sys->modifierPortions(portionsAvant_);
        sys->modifierTheSelectionne(theAvant_);
    }

} // namespace CMD