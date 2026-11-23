
#include "../../include/commande/CmdRoutine.h"

namespace CMD
{

    CmdRoutine::CmdRoutine(const std::string &nom, const std::shared_ptr<Commande> &routine) : Commande(true), nom_(nom), routine_(routine) {}

    CmdRoutine::~CmdRoutine() = default;

    void CmdRoutine::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        routine_->executer(inst, sys);
        std::cout << "Routine appliquée : " << nom_ << "." << std::endl;
    }

    void CmdRoutine::undo(Machine::Systeme *sys) { routine_->undo(sys); }

    void CmdRoutine::redo(Machine::Systeme *sys) { routine_->redo(sys); }

    void CmdRoutine::apercu(std::vector<std::string> &lignes) const { routine_->apercu(lignes); }

    std::shared_ptr<Commande> CmdRoutine::cloner() const { return std::make_shared<CmdRoutine>(nom_, routine_->cloner()); }

} // namespace CMD
