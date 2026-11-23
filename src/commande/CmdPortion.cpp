
#include "../../include/commande/CmdPortion.h"

namespace CMD
{

    CmdPortion::CmdPortion() : Commande(true) {}

    CmdPortion::~CmdPortion() = default;

    void CmdPortion::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        anciennesPortions_ = sys->portions();
        nouvellesPortions_ = inst.portions;

        sys->modifierPortions(nouvellesPortions_);
        std::cout << "Nombre de portions : " << nouvellesPortions_ << "." << std::endl;
    }

    void CmdPortion::undo(Machine::Systeme *sys) { sys->modifierPortions(anciennesPortions_); }

    void CmdPortion::redo(Machine::Systeme *sys) { sys->modifierPortions(nouvellesPortions_); }

} // namespace CMD
