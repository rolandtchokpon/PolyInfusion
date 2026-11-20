
#include "Commande.h"

namespace CMD
{
    class CmdInfuser : public Commande
    {
    public:
        CmdInfuser();
        ~CmdInfuser();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
    };

} // namespace Commande