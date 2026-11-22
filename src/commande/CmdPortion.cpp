
#include "../../include/commande/CmdPortion.h"

namespace CMD
{

    CmdPortion::CmdPortion() : Commande(true) {}

    CmdPortion::~CmdPortion() = default;

    void CmdPortion::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        instruction_ = inst;

        portionsAvant_ = sys->portions();
        sys->modifierPortions(inst.portions, afficherModif_);

        afficherModif_ = false;
    }

    void CmdPortion::undo(Machine::Systeme *sys)
    {
        sys->modifierPortions(portionsAvant_);
    }
}