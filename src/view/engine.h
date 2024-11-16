#pragma once

#include "../config.h"
#include "../model/scene.h"

class Engine {

public:
    Engine(int width, int height, GLFWwindow* window);

    ~Engine();

    void render(Scene* scene);

private:
    GLFWwindow* window;

    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkSurfaceKHR surface;

    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;

    VkQueue graphicsQueue;
    VkQueue presentQueue;

    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;
    
    VkRenderPass renderPass;
    VkDescriptorSetLayout descriptorSetLayout;
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;

    std::vector<VkFramebuffer> swapChainFramebuffers;

    VkCommandPool commandPool;

    VkDescriptorPool descriptorPool;
    std::vector<VkDescriptorSet> descriptorSets;

    std::vector<VkCommandBuffer> commandBuffers;
    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;

    uint32_t currentFrame = 0;

    bool framebufferResized = false;

    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;

    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;
    std::vector<void*> uniformBuffersMapped;

    // setupVulkan.cpp
    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
    void initWindow();
    void initVulkan();
    void createInstance();
    void setupDebugMessenger();
    void pickPhysicalDevice();
    void createLogicalDevice();

    bool checkValidationLayerSupport();
    std::vector<const char*> getRequiredExtensions();
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData
    );
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    bool isDeviceSuitable(VkPhysicalDevice device);
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);


    void cleanup();

    // Presentation
    void createSurface();
    void createSwapChain();
    void createImageViews();
    void recreateSwapChain();
    void cleanupSwapChain();
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& avaliableForm);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> & avaliablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

    // Pipline
    void createGraphicsPipeline();
    void createRenderPass();
    static std::vector<char> readFile(const std::string& filename);
    VkShaderModule createShaderModule(const std::vector<char>& code);

    // Drawing
    void createDescriptorSetLayout();
    void createFramebuffers();
    void createCommandPool();
    void createVertexBuffer();
    void createIndexBuffer();
    void createUniformBuffers();
    void createDescriptorPool();
    void createDescriptorSets();
    void createCommandBuffers();
    void createSyncObjects();
    void recordCommandBuffer( VkCommandBuffer commandBuffer, uint32_t imageIndex);
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
    void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

    // Main Loop func
    void mainLoop();
    void drawFrame();
    void updateUniformBuffer(uint32_t currentImage);





    // // glfw
    // int width;
    // int height;
    // GLFWwindow* window;

    // // instance
    // VkInstance instance;
    // VkDebugUtilsMessengerEXT debugMessenger;
    // VkSurfaceKHR surface;

    // // device
    // VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    // VkDevice device;
    // VkQueue graphicsQueue;
    // VkQueue presentQueue;
    // VkSwapchainKHR swapChain;
    // std::vector<VkImage> swapChainImages;
    // VkFormat swapChainImageFormat;
    // VkExtent2D swapChainExtent;
    // std::vector<VkImageView> swapChainImageViews;

    // // pipeline
    // VkRenderPass renderPass;
    // VkDescriptorSetLayout descriptorSetLayout;
    // VkPipelineLayout pipelineLayout;
    // VkPipeline graphicsPipeline;
    // std::vector<VkFramebuffer> swapChainFramebuffers;

    // // command
    // VkCommandPool commandPool;
    // VkDescriptorPool descriptorPool;
    // std::vector<VkDescriptorSet> descriptorSets;
    // std::vector<VkCommandBuffer> commandBuffers;

    // // synchronization objects
    // std::vector<VkSemaphore> imageAvailableSemaphores;
    // std::vector<VkSemaphore> renderFinishedSemaphores;
    // std::vector<VkFence> inFlightFences;
    // uint32_t currentFrame = 0;
    // bool framebufferResized = false;

    // // asset pointers
    // VkBuffer vertexBuffer;
    // VkDeviceMemory vertexBufferMemory;
    // VkBuffer indexBuffer;
    // VkDeviceMemory indexBufferMemory;
    // std::vector<VkBuffer> uniformBuffers;
    // std::vector<VkDeviceMemory> uniformBuffersMemory;
    // std::vector<void*> uniformBuffersMapped;

    // // instance setup
    // void create_instance();

    // // device setup
    // void create_device();
    // void create_swapchain();
    // void recreate_swapchain();

    // // pipeline setup
    // void create_pipeline();

    // //final setup steps
    // void finalize_setup();
    // void create_framebuffers();
    // void create_frame_sync_objects();

    // // asset creation
    // void create_assets();
    
    // // draw
    // void prepare_scene(VkCommandBuffer commandBuffer);
    // void record_draw_commands(VkCommandBuffer commandBuffer, uint32_t imageIndex, Scene* scene);

    // // cleanup functions
    // void cleanup_swapchain();
}