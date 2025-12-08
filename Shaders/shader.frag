#version 450

layout(location = 0) out vec4 outColor;

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec2 fragTexCoord;
layout(location = 2) in vec3 fragPos;
layout(location = 3) in vec3 viewPos;

layout(binding = 1) uniform sampler2D texSampler;

void main() {
    //Ambient light
    vec3 ambientLight = vec3(0.1);

    vec3 result = ambientLight;

    vec3 lightPos = vec3(0.0, 1.0, 0.0);
    vec3 lightCol = vec3(1.0, 1.0, 1.0);

    //Diffuse
    vec3 normalized = normalize(vec3(0.0, 1.0, 0.0));
    vec3 lightDir = normalize(lightPos - fragPos);
    float diff = max(dot(normalized, lightDir), 0.0);
    vec3 diffuse = diff * lightCol * max((1 - (distance(lightPos, fragPos) / (1.25+0.0001))), 0.0);

    //Specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, normalized);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = min(specularStrength * spec * lightCol, 1.0); 


    result = result + (diffuse + specular) * 1.0;

    outColor = (vec4(fragColor * texture(texSampler, fragTexCoord).rgb, 1.0)) * vec4(result, 1.0);
    
}