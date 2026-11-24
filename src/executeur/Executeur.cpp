
#include <iostream>
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

    Executeur::Executeur(Machine::Systeme *sys) : sys_(sys),
                                                  hist_(std::make_unique<HistoriqueCMD>()),
                                                  routines_(std::make_unique<RegistreRoutines>())
    {
    }

    Executeur::~Executeur() = default;

    void Executeur::executer(const Console::Instruction &inst)
    {
        switch (inst.type)
        {
        case Console::TypeInstruction::Invalide:
            std::cout << "Erreur : " << inst.erreur << std::endl;
            return;

        case Console::TypeInstruction::Undo:
            hist_->undo(sys_);
            return;

        case Console::TypeInstruction::Redo:
            hist_->redo(sys_);
            return;

        case Console::TypeInstruction::Selection:
        case Console::TypeInstruction::Portion:
        case Console::TypeInstruction::Routine:
        {
            std::shared_ptr<CMD::CmdReglage> reglage = creerReglage(inst);

            if (!reglage)
                return;

            reglage->executer(sys_);

            // L'historique n'est modifié qu'après une exécution réussie.
            hist_->ajouterCmd(reglage);
            return;
        }

        default:
        {
            std::shared_ptr<CMD::Commande> cmd = creerCommande(inst);

            if (cmd)
                cmd->executer(sys_);
            return;
        }
        }
    }

    std::shared_ptr<CMD::CmdReglage> Executeur::creerReglage(const Console::Instruction &inst)
    {
        switch (inst.type)
        {
        case Console::TypeInstruction::Selection:
            return std::make_shared<CMD::CmdSelection>(inst.the);

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

    std::shared_ptr<CMD::Commande> Executeur::creerCommande(const Console::Instruction &inst)
    {
        switch (inst.type)
        {
        case Console::TypeInstruction::Aide:
            return std::make_shared<CMD::CmdAide>();
        case Console::TypeInstruction::Quitter:
            return std::make_shared<CMD::CmdQuit>();
        case Console::TypeInstruction::Infuser:
            return std::make_shared<CMD::CmdInfuser>();
        case Console::TypeInstruction::Reserves:
            return std::make_shared<CMD::CmdReserve>();
        case Console::TypeInstruction::RemplirEau:
            return std::make_shared<CMD::CmdRemplirEau>(inst.quantite);
        case Console::TypeInstruction::RemplirThe:
            return std::make_shared<CMD::CmdRemplirThe>(inst.the, inst.quantite);
        case Console::TypeInstruction::Notifications:
            return std::make_shared<CMD::CmdNotif>(inst.notificationsActives);
        case Console::TypeInstruction::Config:
            return std::make_shared<CMD::CmdConfig>();
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
        default:
            return nullptr;
        }
    }

} // namespace Execution
