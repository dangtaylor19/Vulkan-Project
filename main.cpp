#include "vulkan_backend.h"
#include "core_headers.h"

GLFWwindow* window;

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

void initWindow();
void mainLoop(VulkanBackend& app);

std::vector<Mesh> _meshes;

enum Backend {
    OPENGL,
    VULKAN,
    DIRECTX
};

int main() {
    Mesh mesh1 = Mesh();
    Mesh mesh2 = Mesh();

    mesh2.vertices = {
        // Base (Y = 0.5f)
        {-0.5f, 0.5f, -0.5f},
        { 0.5f, 0.5f, -0.5f},
        { 0.5f, 0.5f,  0.5f},
        {-0.5f, 0.5f,  0.5f},

        // Front Face
        { 0.0f, -0.5f,  0.0f}, // Apex
        {-0.5f,  0.5f,  0.5f}, // Bottom Left
        { 0.5f,  0.5f,  0.5f}, // Bottom Right

        // Back Face
        { 0.0f, -0.5f,  0.0f}, // Apex
        { 0.5f,  0.5f, -0.5f}, // Bottom Left
        {-0.5f,  0.5f, -0.5f}, // Bottom Right

        // Left Face
        { 0.0f, -0.5f,  0.0f}, // Apex
        {-0.5f,  0.5f, -0.5f}, // Bottom Left
        {-0.5f,  0.5f,  0.5f}, // Bottom Right

        // Right Face
        { 0.0f, -0.5f,  0.0f}, // Apex
        { 0.5f,  0.5f,  0.5f}, // Bottom Left
        { 0.5f,  0.5f, -0.5f}, // Bottom Right
    };

    mesh2.indices = {
            0, 2, 1, 0, 3, 2, //Base
            4, 6, 5,          //Front
            7, 9, 8,          //Back
            10, 12, 11,       //Left
            13, 15, 14,       //Right
    };

    mesh2.uvs = {
        // Base
        {0.0f, 0.0f},
        {1.0f, 0.0f},
        {1.0f, 1.0f},
        {0.0f, 1.0f},

        // Front
        {0.5f, 0.0f},
        {0.0f, 1.0f},
        {1.0f, 1.0f},

        // Back
        {0.5f, 0.0f},
        {0.0f, 1.0f},
        {1.0f, 1.0f},

        // Left
        {0.5f, 0.0f},
        {0.0f, 1.0f},
        {1.0f, 1.0f},

        // Right
        {0.5f, 0.0f},
        {0.0f, 1.0f},
        {1.0f, 1.0f},
    };

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

            /*Input*/
            glfwSetScrollCallback(window, InputManager::scrollCallback);
            glfwSetMouseButtonCallback(window, InputManager::mouseButtonCallback);
            glfwSetKeyCallback(window, InputManager::keyCallback);
            glfwSetCursorPosCallback(window, InputManager::cursorPositionCallback);

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

void mainLoop(VulkanBackend& app) { //TO-DO: Replace vulkanbackend with abstract backend class
    /*For time delta*/
    float oldTime = 0;

    Vector2 movement;
    
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

        //Update Time
        //GameTime::updateDelta(glfwGetTime() - oldTime);
        //oldTime = glfwGetTime();

        //---------Process game scripts---------
        /*Editor Camera Controls*/
        if (InputManager::GetMouseButton(1)) {
           // //Movement
           // movement = Vector2(InputManager::GetAxis("Horizontal") * 8, InputManager::GetAxis("Vertical") * 8);
           //
           // Vector3 pos = editorCamera.GetPosition();
           //
           // pos += editorCamera.GetRightVec() * movement.x * GameTime::delta;
           // pos += editorCamera.GetForwardVec() * movement.y * GameTime::delta;
           //
           // editorCamera.SetPosition(pos);
           //
           // //Rotation
           // editorCamera.SetRotation(Vector3(editorCamera.GetRotation().x + InputManager::GetMousePositionDelta().y, editorCamera.GetRotation().y - InputManager::GetMousePositionDelta().x, 0));
        }


        InputManager::Update();

        //Reset Scroll Values
        InputManager::GetMouseScroll("");
    }

    ImGui_ImplVulkan_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    //Cleanup app
    app.cleanup();
}