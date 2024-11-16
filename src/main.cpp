#include "./controller/app.h"

int main() {
    App* avant_garde_app = new App(1920, 1080, true);

    try {
        avant_garde_app->run();
        delete avant_garde_app;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
