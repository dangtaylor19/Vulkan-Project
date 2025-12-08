#include "vulkan_backend.h"

enum Backend {
    OPENGL,
    VULKAN,
    DIRECTX
};

int main() {
    Backend backend = VULKAN;

    if (backend == OPENGL) {
        
    }
    else if (backend == VULKAN) {
        VulkanBackend app;

        try {
            app.run();
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }
    else if (backend == DIRECTX) {

    }

    return EXIT_SUCCESS;
}