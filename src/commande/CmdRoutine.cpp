
#include <iostream>
#include "../../include/commande/CmdRoutine.h"

namespace CMD
{

    CmdRoutine::CmdRoutine(const std::string &nom, const std::shared_ptr<CmdReglage> &routine) : nom_(nom), routine_(routine) {}

    CmdRoutine::~CmdRoutine() = default;

    void CmdRoutine::executer(Machine::Systeme *sys)
    {
        routine_->executer(sys);
        std::cout << "Routine appliquée : " << nom_ << "." << std::endl;
    }

    void CmdRoutine::undo(Machine::Systeme *sys) { routine_->undo(sys); }

    void CmdRoutine::redo(Machine::Systeme *sys) { routine_->redo(sys); }

    std::string CmdRoutine::description() const { return routine_->description(); }

    std::unique_ptr<IterateurReglage> CmdRoutine::creerIterateur() const { return routine_->creerIterateur(); }

    std::shared_ptr<CmdReglage> CmdRoutine::cloner() const { return std::make_shared<CmdRoutine>(nom_, routine_->cloner()); }

} // namespace CMD
