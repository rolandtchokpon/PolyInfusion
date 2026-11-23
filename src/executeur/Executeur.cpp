
#include "../../include/executeur/Executeur.h"
#include "../../include/commande/CmdAide.h"
#include "../../include/commande/CmdApercu.h"
#include "../../include/commande/CmdConfig.h"
#include "../../include/commande/CmdInfuser.h"
#include "../../include/commande/CmdNotif.h"
#include "../../include/commande/CmdPortion.h"
#include "../../include/commande/CmdQuit.h"
#include "../../include/commande/CmdRemplirEau.h"
#include "../../include/commande/CmdRemplirThe.h"
#include "../../include/commande/CmdReserve.h"
#include "../../include/commande/CmdRoutine.h"
#include "../../include/commande/CmdSelection.h"

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

        std::shared_ptr<CMD::Commande> cmd = commande(inst);

        if (!cmd) return;

        if (cmd->estReversible()) hist_->ajouterCmd(cmd);

        cmd->executer(inst, sys_);
    }

    std::shared_ptr<CMD::Commande> Executeur::commande(const Console::Instruction &inst)
    {
        switch (inst.type)
        {
        case Console::TypeInstruction::Aide:
            return std::make_shared<CMD::CmdAide>();
        case Console::TypeInstruction::Quitter:
            return std::make_shared<CMD::CmdQuit>();
        case Console::TypeInstruction::Selection:
            return std::make_shared<CMD::CmdSelection>();
        case Console::TypeInstruction::Infuser:
            return std::make_shared<CMD::CmdInfuser>();
        case Console::TypeInstruction::Reserves:
            return std::make_shared<CMD::CmdReserve>();
        case Console::TypeInstruction::RemplirEau:
            return std::make_shared<CMD::CmdRemplirEau>();
        case Console::TypeInstruction::RemplirThe:
            return std::make_shared<CMD::CmdRemplirThe>();
        case Console::TypeInstruction::Notifications:
            return std::make_shared<CMD::CmdNotif>();
        case Console::TypeInstruction::Apercu:
            return std::make_shared<CMD::CmdApercu>();
        case Console::TypeInstruction::Config:
            return std::make_shared<CMD::CmdConfig>();
        case Console::TypeInstruction::Portion:
            return std::make_shared<CMD::CmdPortion>();
        case Console::TypeInstruction::Routine:
            return std::make_shared<CMD::CmdRoutine>();
        default:
            return nullptr;
        }
    }

} // namespace Execution
