
#include "Commande.h"

namespace CMD
{
    class CmdQuit : public Commande
    {
    public:
        CmdQuit(const Console::Instruction &inst);
        ~CmdQuit();

        virtual void executer(Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void apercu(unsigned int numero = 1) override;
    };

} // namespace Commande