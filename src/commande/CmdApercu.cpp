
#include "../../include/commande/CmdApercu.h"

namespace CMD
{

    CmdApercu::CmdApercu(const std::shared_ptr<Commande> &routine) : Commande(false), routine_(routine) {}

    CmdApercu::~CmdApercu() = default;

    void CmdApercu::executer(const Console::Instruction &, Machine::Systeme *)
    {
        // Parcourt les changements élémentaires sans rien exécuter ni modifier.
        std::vector<std::string> lignes;
        routine_->apercu(lignes);

        for (std::size_t i = 0; i < lignes.size(); ++i)
            std::cout << (i + 1) << ". " << lignes[i] << std::endl;
    }

    void CmdApercu::undo(Machine::Systeme *)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }

} // namespace CMD
