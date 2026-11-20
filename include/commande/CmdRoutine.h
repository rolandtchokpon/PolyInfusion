
#include "Commande.h"

namespace CMD
{
    class CmdRoutine : public Commande
    {
    public:
        CmdRoutine();
        ~CmdRoutine();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;

    private:
        Machine::Routine lireRoutine(const std::string &r);
        Machine::Routine routine_;
    };

} // namespace Commande