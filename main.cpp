#include "vulkan_backend.h"
#include "core_headers.h"

GLFWwindow* window;

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

void initWindow();
void mainLoop(VulkanBackend app);

std::vector<Mesh> _meshes;

enum Backend {
    OPENGL,
    VULKAN,
    DIRECTX
};

int main() {
    Mesh mesh1 = Mesh();
    Mesh mesh2 = Mesh();

    _meshes.push_back(mesh1);
    _meshes.push_back(mesh2);

    initWindow();

    //ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    ImGui::StyleColorsDark();

    Backend backend = VULKAN;

    if (backend == OPENGL) {
        
    }
    else if (backend == VULKAN) {
        VulkanBackend app;
        app.set_meshes(&_meshes);

        try {
            app.run(window);
            mainLoop(app);
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

void initWindow() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan Daniel", nullptr, nullptr);
}

void mainLoop(VulkanBackend app) { //TO-DO: Replace vulkanbackend with abstract backend class
    while (!glfwWindowShouldClose(window)) {
        //Input
        glfwPollEvents();

        //Setup ImGui
        ImGui_ImplVulkan_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        ImGui::NewFrame();

        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("File")) {
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }

        if(ImGui::Begin("Settings", nullptr)) {
            glm::vec3 speed = app.speed;
            if (ImGui::DragFloat3("Speed", &speed.x, 0.1f)) {
                app.speed = speed;
            }

            glm::vec3 position = app.position;
            if (ImGui::DragFloat3("Position", &position.x, 0.1f)) {
                app.position = position;
            }

            glm::vec3 rotation = app.rotation;
            if (ImGui::DragFloat3("Rotation", &rotation.x, 0.1f)) {
                app.rotation = rotation;
            }

            glm::vec3 scale = app.scale;
            if (ImGui::DragFloat3("Scale", &scale.x, 0.1f)) {
                app.scale = scale;
            }

            ImGui::End();
        }

        ImGui::Render();

        //Draw all the data onto the screen
        app.drawFrame();
    }

    ImGui_ImplVulkan_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    //Cleanup app
    app.cleanup();
}