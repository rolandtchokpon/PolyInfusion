
#include "../../include/executeur/Executeur.h"

namespace Execution
{

    Executeur::Executeur(Machine::Systeme *sys) : 
        sys_(sys),
        hist_(std::make_unique<HistoriqueCMD>())
    {}

    Executeur::~Executeur() = default;

    void Executeur::executer(const Console::Instruction &inst)
    {
        if (inst.type == Console::TypeInstruction::Invalide)
        {
            std::cout << "Erreur : " << inst.erreur << std::endl;
            return;
        }
        else if (inst.type == Console::TypeInstruction::Undo)
        {
            hist_->undo(sys_);
            return;
        }
        else if (inst.type == Console::TypeInstruction::Redo)
        {
            hist_->redo(sys_);
            return;
        }

        std::shared_ptr<CMD::Commande> cmd = std::move(commande(inst));

        if (cmd->estReversible()) hist_->ajouterCmd(cmd);

        cmd->executer(inst, sys_);
    }

    std::shared_ptr<CMD::Commande> &Executeur::commande(const Console::Instruction &inst)
    {
        std::shared_ptr<CMD::Commande> cmd;

        switch (inst.type)
        {
        case Console::TypeInstruction::Aide:
            break;

        case Console::TypeInstruction::Quitter:
            break;

        case Console::TypeInstruction::Invalide:
            break;

        case Console::TypeInstruction::Selection:
            break;

        case Console::TypeInstruction::Infuser:
            break;

        case Console::TypeInstruction::Reserves:
            break;

        case Console::TypeInstruction::RemplirEau:
            break;

        case Console::TypeInstruction::RemplirThe:
            break;

        case Console::TypeInstruction::Notifications:
            break;

        case Console::TypeInstruction::Apercu:
            break;

        case Console::TypeInstruction::Config:
            break;

        case Console::TypeInstruction::Portion:
            break;

        case Console::TypeInstruction::Redo:
            break;

        case Console::TypeInstruction::Undo:
            break;

        case Console::TypeInstruction::Routine:
            break;

        default:
            break;
        }

        return cmd;
    }

}