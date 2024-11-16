#pragma once

#include "./engine.h"

Engine::Engine(int width, int height, GLFWwindow* window) {
    this->width  = width;
    this->height = height;
    this->window = window;

    std::cout << "Creating graphics engine...\n";

    create_instance();

    create_device();

    create_pipeline();

    finalize_setup();

    create_assets();
}

void Engine::create_instance() {

}

void Engine::create_device() {

}

void Engine::create_swapchain() {

}

void Engine::recreate_swapchain() {

}

void Engine::create_pipeline() {

}

void Engine::create_framebuffers() {

}

void Engine::create_frame_sync_objects() {

}

void Engine::finalize_setup() {

}

void Engine::create_assets() {

}

void Engine::prepare_scene(VkCommandBuffer commandBuffer) {

}

void Engine::record_draw_commands(VkCommandBuffer commandBuffer, uint32_t imageIndex, Scene* scene) {

}

void Engine::render(Scene* scene) {

}

void cleanup_swapchain() {

}

Engine::~Engine() {

}
