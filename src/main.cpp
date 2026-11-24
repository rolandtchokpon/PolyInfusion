#include "../include/commande/CmdPolyInfusion.h"
#include "../include/console/Console.h"
#include "../include/executeur/Executeur.h"

#include <exception>
#include <iostream>
#include <memory>
#include <string>

#ifdef _WIN32
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

    std::unique_ptr<Console::InterfaceConsole> console = std::make_unique<Console::InterfaceConsole>();

    // Phase de démarrage : la console analyse les lignes jusqu'à « PolyInfusion <modèle> »,
    // qui désigne la fabrique à utiliser pour fabriquer la machine.
    std::unique_ptr<Machine::Systeme> sys;

    for (std::string ligne; !sys && (std::cout << "> " << std::flush, std::getline(std::cin, ligne));)
    {
        try
        {
            const Console::Instruction inst = console->analyser(ligne);

            if (inst.type == Console::TypeInstruction::Invalide)
            {
                std::cout << "Erreur : " << inst.erreur << std::endl
                          << std::endl;
            }
            else if (inst.type == Console::TypeInstruction::PolyInfusion)
            {
                sys = CMD::CmdPolyInfusion(inst.modele).creerSysteme();
                std::cout << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl
                      << std::endl;
        }
    }

    if (!sys)
    {
        std::cout << "\nArrêt de PolyInfusion.\n";
        return 0;
    }

    console->definirThes(sys->thesDisponibles());
    std::unique_ptr<Execution::Executeur> executeur = std::make_unique<Execution::Executeur>(sys.get());

    for (std::string ligne; std::cout << "> " << std::flush, std::getline(std::cin, ligne);)
    {
        try
        {
            executeur->executer(console->analyser(ligne));
            std::cout << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl
                      << std::endl;
        }

        if (sys->doitQuitter())
            return 0;
    }

    std::cout << "\nArrêt de PolyInfusion.\n";
    return 0;
}