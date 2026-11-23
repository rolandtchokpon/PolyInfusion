
#include "Commande.h"

namespace CMD
{
    class CmdSelection : public Commande
    {
    public:
        CmdSelection(const Console::Instruction &inst);
        ~CmdSelection();

        virtual void executer(Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void apercu(unsigned int numero = 1) override;
    };

} // namespace Commande