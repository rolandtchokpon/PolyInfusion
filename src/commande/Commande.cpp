
#include "../../include/commande/Commande.h"

namespace CMD
{

    Commande::Commande(bool estReversible, const Console::Instruction &instruction) : estReversible_(estReversible),
                                                                                      afficherModif_(true),
                                                                                      instruction_(instruction)
    {
    }

    Commande::~Commande() = default;

    bool Commande::estReversible() const { return estReversible_; }

    const Console::Instruction &Commande::sauvgarde() { return instruction_; }

    std::shared_ptr<Routine::IRoutine> Commande::lireRoutine(const std::string &r)
    {
        if (r == "solo")
        {
            return std::make_shared<Routine::Solo>();
        }
        else if (r == "duo")
        {
            return std::make_shared<Routine::Duo>();
        }
        else if (r == "matin")
        {
            return std::make_shared<Routine::Matin>();
        }

        return nullptr;
    }

}