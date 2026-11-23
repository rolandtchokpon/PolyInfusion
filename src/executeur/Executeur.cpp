
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
        hist_(std::make_unique<HistoriqueCMD>()),
        routines_(std::make_unique<RegistreRoutines>())
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

        cmd->executer(inst, sys_);

        // L'historique n'est modifié qu'après une exécution réussie.
        if (cmd->estReversible()) hist_->ajouterCmd(cmd);
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
            return std::make_shared<CMD::CmdSelection>(inst.the);
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
        {
            auto routine = routines_->obtenir(inst.routine);
            if (!routine)
            {
                std::cout << "Erreur : routine inconnue." << std::endl;
                return nullptr;
            }
            return std::make_shared<CMD::CmdApercu>(routine);
        }
        case Console::TypeInstruction::Config:
            return std::make_shared<CMD::CmdConfig>();
        case Console::TypeInstruction::Portion:
            return std::make_shared<CMD::CmdPortion>(inst.portions);
        case Console::TypeInstruction::Routine:
        {
            auto execution = routines_->creerExecution(inst.routine);
            if (!execution)
            {
                std::cout << "Erreur : routine inconnue." << std::endl;
                return nullptr;
            }
            return std::make_shared<CMD::CmdRoutine>(inst.routine, execution);
        }
        default:
            return nullptr;
        }
    }

} // namespace Execution
