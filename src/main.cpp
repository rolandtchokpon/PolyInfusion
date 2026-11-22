#include "Console/Console.h"
#include "../include/fabrique/FabirquePro.h"
#include "../include/fabrique/FabriqueCompact.h"
#include "../include/executeur/Executeur.h"

#include <iostream>
#include <string>

#ifdef _WIN32
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

int main(int argc, char *argv[])
{
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

    if (argc != 2 || (std::string(argv[1]) != "compact" && std::string(argv[1]) != "pro"))
    {
        std::cerr << "Utilisation : PolyInfusion <compact|pro>\n";
        return 1;
    }

    const std::string modele = argv[1];

    std::unique_ptr<Fabrique::FabriqueSysteme> fabrique;

    if (modele == "pro")
    {
        fabrique = std::make_unique<Fabrique::FabriquePro>();
    }
    else
    {
        fabrique = std::make_unique<Fabrique::FabriqueCompact>();
    }

    std::unique_ptr<Machine::Systeme> systeme = std::move(fabrique->creerSysteme());

    std::unique_ptr<Execution::Executeur> executeur = std::move(std::make_unique<Execution::Executeur>(systeme.get()));

    std::unique_ptr<Console::InterfaceConsole> interface = std::make_unique<Console::InterfaceConsole>();

    for (std::string ligne; std::cout << "> " << std::flush, std::getline(std::cin, ligne);)
    {
        try
        {
            const auto instruction = interface->analyser(ligne);

            executeur->executer(instruction);

            if (systeme->doitQuitter())
                return 0;
        }
        catch (Machine::EauInsuffisante e)
        {
            std::cerr << e.what() << std::endl;
        }
        catch (Machine::TheInsuffisant e)
        {
            std::cerr << e.what() << std::endl;
        }
        catch (std::exception e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << "\nArrêt de PolyInfusion.\n";
    return 0;
}
