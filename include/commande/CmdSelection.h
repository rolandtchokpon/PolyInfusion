
#include "Commande.h"

namespace CMD
{
    class CmdSelection : public Commande
    {
    public:
        CmdSelection();
        ~CmdSelection();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
    };

} // namespace Commande