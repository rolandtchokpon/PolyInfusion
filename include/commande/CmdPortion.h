
#include "Commande.h"

namespace CMD
{
    class CmdPortion : public Commande
    {
    public:
        CmdPortion(const Console::Instruction &inst);
        ~CmdPortion();

        virtual void executer(Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void apercu(unsigned int numero = 1) override;
    };

} // namespace Commande