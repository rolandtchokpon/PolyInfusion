
#include "Commande.h"

namespace CMD
{
    class CmdNotif : public Commande
    {
    public:
        CmdNotif(const Console::Instruction &inst);
        ~CmdNotif();

        virtual void executer(Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void apercu(unsigned int numero = 1) override;
    };

} // namespace Commande