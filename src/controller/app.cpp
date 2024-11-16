#include "app.h"

/**
 * Construct a new App
 * 
 * @param width     width of the window
 * @param height    height of the window
 * @param debug     whether to run the app with vulkan validation layers and debug print statements
 */
App::App(int width, int height, bool debug) {
    build_glfw_window(width, height);

    graphicsEngine = new Engine(width, height, window);

    scene = new Scene();
}

/**
 * Build App's window
 * 
 * @param width     width of the window
 * @param height    height of the window
 */
void App::build_glfw_window(int width, int height) {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
   
    
    if (window = glfwCreateWindow(width, height, "Project", nullptr, nullptr)) {
        std::cout << "Success: glfwCreateWindow \"Project\", width: \"" << width << ", height: " << height << '\n';
    } else {
        std::cout << "Failed: glfwCreateWindow\n";
    }
    
    glfwSetWindowUserPointer(window, this);
    // glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}

/**
 * Start the App's main loop
 */
void App::run() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        graphicsEngine->drawFrame();
        calculateFrameRate();
    }
    // vkDeviceWaitIdle(device);
}

/**
 * Calculates the App's framerate and updates the window title with the framerate
 */
void App:: calculateFrameRate() {
    currentTime = glfwGetTime();
    double delta_t = currentTime - lastTime;

    if (delta_t >= 1) {
        int framerate { std::max(1, int(numFrames / delta_t)) };
        std::stringstream title;
        title << "Running at " << framerate << " fps.";
        glfwSetWindowTitle(window, title.str().c_str());
        lastTime = currentTime;
        numFrames = -1;
        frameTime = float(1000.0 / framerate);
    }

    ++numFrames;
}

/**
 * Destruct App
 */
App::~App() {
    delete graphicsEngine;
    delete scene;
}