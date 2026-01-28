#version 450

layout(set = 0, binding = 0) uniform CameraUBO {
    mat4 view;
    mat4 proj;
} camera;

layout(push_constant) uniform ModelPC {
    mat4 model;
} obj;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec2 inTexCoord;

layout(location = 0) out vec2 fragTexCoord;
layout(location = 1) out vec3 fragPos;
layout(location = 2) out vec3 viewPos;

void main() {
    gl_Position = camera.proj * camera.view * obj.model * vec4(inPosition, 1.0);
    fragTexCoord = inTexCoord;

    fragPos = vec3(obj.model * vec4(inPosition, 1.0));
    viewPos = inverse(camera.view)[3].xyz;
}