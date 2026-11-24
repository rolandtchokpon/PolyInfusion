
#include "../../include/executeur/RegistreRoutines.h"
#include "../../include/commande/CmdPortion.h"
#include "../../include/commande/CmdSelection.h"
#include "../../include/commande/Routine.h"

namespace Execution
{

    RegistreRoutines::RegistreRoutines()
    {
        auto solo = std::make_shared<CMD::Routine>("solo");
        solo->ajouter(std::make_shared<CMD::CmdSelection>("vert"));
        solo->ajouter(std::make_shared<CMD::CmdPortion>(1));

        auto duo = std::make_shared<CMD::Routine>("duo");
        duo->ajouter(std::make_shared<CMD::CmdSelection>("noir"));
        duo->ajouter(std::make_shared<CMD::CmdPortion>(2));

        auto matin = std::make_shared<CMD::Routine>("matin");
        matin->ajouter(duo); // sous-routine, pas une répétition de ses commandes
        matin->ajouter(std::make_shared<CMD::CmdSelection>("oolong"));

        enregistrer("solo", solo);
        enregistrer("duo", duo);
        enregistrer("matin", matin);
    }

    RegistreRoutines::~RegistreRoutines() = default;

    void RegistreRoutines::enregistrer(const std::string &nom, const std::shared_ptr<CMD::CmdReglage> &routine)
    {
        routines_[nom] = routine;
    }

    std::shared_ptr<CMD::CmdReglage> RegistreRoutines::obtenir(const std::string &nom) const
    {
        auto it = routines_.find(nom);
        return it == routines_.end() ? nullptr : it->second;
    }

    std::shared_ptr<CMD::CmdReglage> RegistreRoutines::creerExecution(const std::string &nom) const
    {
        auto routine = obtenir(nom);
        return routine ? routine->cloner() : nullptr;
    }

} // namespace Execution
