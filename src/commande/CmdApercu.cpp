
#include <iostream>
#include "../../include/commande/CmdApercu.h"

namespace CMD
{

    CmdApercu::CmdApercu(const std::shared_ptr<CmdReglage> &routine) : routine_(routine) {}

    CmdApercu::~CmdApercu() = default;

    void CmdApercu::executer(Machine::Systeme *)
    {
        // L'itérateur parcourt les changements élémentaires sans rien exécuter ni modifier.
        std::unique_ptr<IterateurReglage> iterateur = routine_->creerIterateur();

        for (int numero = 1; iterateur->aSuivant(); ++numero)
            std::cout << numero << ". " << iterateur->suivant().description() << std::endl;
    }

} // namespace CMD
