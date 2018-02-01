#include "GLEngineErrors.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <cstdlib>

namespace GLEngine {
	
	void fatalError(std::string error) {

		std::cout << error << std::endl << "Enter any key to quit...\n";
		int tmp;
		std::cin >> tmp;
		SDL_Quit();
		exit(1);

	}

}
