
#include "Commande.h"

namespace CMD
{
    class CmdRemplirEau : public Commande
    {
    public:
        CmdRemplirEau();
        ~CmdRemplirEau();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
    };

} // namespace Commande