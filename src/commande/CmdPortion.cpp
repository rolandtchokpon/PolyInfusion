
#include "../../include/commande/CmdPortion.h"

namespace CMD
{

    CmdPortion::CmdPortion() : Commande(true) {}

    CmdPortion::~CmdPortion() = default;

    void CmdPortion::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        if (portionsAvant_ < 0)
            portionsAvant_ = sys->portions();

        sys->modifierPortions(inst.portions);
    }

    void CmdPortion::undo(Machine::Systeme *sys)
    {
        // TODO
    }
}