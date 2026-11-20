
#include "Commande.h"

namespace CMD
{
    class CmdConfig : public Commande
    {
    public:
        CmdConfig();
        ~CmdConfig();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
    };

} // namespace Commande