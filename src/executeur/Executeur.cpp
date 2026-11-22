
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

    std::shared_ptr<CMD::Commande> Executeur::commande(const Console::Instruction &inst)
    {
        std::shared_ptr<CMD::Commande> cmd;

        switch (inst.type)
        {
        case Console::TypeInstruction::Aide:
            cmd = std::make_shared<CMD::CmdAide>();
            break;

        case Console::TypeInstruction::Quitter:
            cmd = std::make_shared<CMD::CmdQuit>();
            break;

        case Console::TypeInstruction::Selection:
            cmd = std::make_shared<CMD::CmdSelection>();
            break;

        case Console::TypeInstruction::Infuser:
            cmd = std::make_shared<CMD::CmdInfuser>();
            break;

        case Console::TypeInstruction::Reserves:
            cmd = std::make_shared<CMD::CmdReserve>();
            break;

        case Console::TypeInstruction::RemplirEau:
            cmd = std::make_shared<CMD::CmdRemplirEau>();
            break;

        case Console::TypeInstruction::RemplirThe:
            cmd = std::make_shared<CMD::CmdRemplirThe>();
            break;

        case Console::TypeInstruction::Notifications:
            cmd = std::make_shared<CMD::CmdNotif>();
            break;

        case Console::TypeInstruction::Apercu:
            cmd = std::make_shared<CMD::CmdApercu>();
            break;

        case Console::TypeInstruction::Config:
            cmd = std::make_shared<CMD::CmdConfig>();
            break;

        case Console::TypeInstruction::Portion:
            cmd = std::make_shared<CMD::CmdPortion>();
            break;

        case Console::TypeInstruction::Routine:
            cmd = std::make_shared<CMD::CmdRoutine>();
            break;

        // Pas de Commande associée : traités directement par Historique
        // (undo/redo) ou par l'appelant (instruction vide ou invalide).
        case Console::TypeInstruction::Undo:
        case Console::TypeInstruction::Redo:
        case Console::TypeInstruction::Invalide:
        case Console::TypeInstruction::Vide:
        default:
            break;
        }

        return cmd;
    }

}