
#include "Commande.h"

namespace CMD
{
    class CmdRemplirEau : public Commande
    {
    public:
        CmdRemplirEau(const Console::Instruction &inst);
        ~CmdRemplirEau();

        virtual void executer(Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void apercu(unsigned int numero = 1) override;
    };

} // namespace Commande