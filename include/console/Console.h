#pragma once
#include <string>
#include <unordered_map>
#include "Mot.h"
#include "Instruction.h"
namespace Console
{
    class InterfaceConsole
    {
    public:
        InterfaceConsole();
        ~InterfaceConsole();

        Instruction analyser(const std::string &ligne);

    private:
        bool estUnThe(const std::string &valeur);
        Instruction invalide(const std::string &message);
        bool lireQuantite(const std::string &texte, double &quantite);
        Mot lireMot(const std::string &nom);
    };

} // namespace console
