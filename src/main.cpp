#include "../include/console/Console.h"
#include "../include/fabrique/FabriqueCompact.h"
#include "../include/fabrique/FabriquePro.h"

#include <exception>
#include <iostream>
#include <memory>
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

    std::unique_ptr<Fabrique::FabriqueSysteme> fabrique;
    if (std::string(argv[1]) == "compact")
        fabrique = std::make_unique<Fabrique::FabriqueCompact>();
    else
        fabrique = std::make_unique<Fabrique::FabriquePro>();

    std::unique_ptr<Machine::Systeme> sys = fabrique->creerSysteme();
    std::unique_ptr<Execution::Executeur> executeur = fabrique->creerExecuteur(sys.get());
    std::unique_ptr<Console::InterfaceConsole> console = fabrique->creerInterfaceConsole();

    for (std::string ligne; std::cout << "> " << std::flush, std::getline(std::cin, ligne);)
    {
        try
        {
            executeur->executer(console->analyser(ligne));
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        if (sys->doitQuitter())
            return 0;
    }

    std::cout << "\nArrêt de PolyInfusion.\n";
    return 0;
}
